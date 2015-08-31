#include "Window.h"
#include <iostream>
#include <fstream>

#include <GL/glew.h>

// TODO(Ben): This might not be right.
#include <SDL/SDL.h>

#define DEFAULT_WINDOW_FLAGS (SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN)

ovox::Window::Window() :
onQuit(this) {
    // Empty
}
OPENVOX_MOVABLE_DEF(ovox::Window, o) {
    std::swap(m_glc, o.m_glc);
    std::swap(m_window, o.m_window);
    std::swap(m_displayMode, o.m_displayMode);
    std::swap(m_quitSignal, o.m_quitSignal);

    // Swap events, but keep correct senders
    std::swap(onQuit, o.onQuit);
    this->onQuit.setSender(this);
    o.onQuit.setSender(&o);
    return *this;
}

bool ovox::Window::init(GameDisplayMode* displayMode /*= nullptr*/, bool isResizable /*= true*/) {
    if (isInitialized()) return false;
    if (displayMode) m_displayMode = *displayMode;
    m_displayMode.isResizable = isResizable;

    SDL_WindowFlags flags = (SDL_WindowFlags)DEFAULT_WINDOW_FLAGS;
    if (m_displayMode.isResizable) flags = (SDL_WindowFlags)(flags | SDL_WINDOW_RESIZABLE);
    if (m_displayMode.isBorderless) flags = (SDL_WindowFlags)(flags | SDL_WINDOW_BORDERLESS);
    if (m_displayMode.isFullscreen) flags = (SDL_WindowFlags)(flags | SDL_WINDOW_FULLSCREEN);
    m_window = SDL_CreateWindow(DEFAULT_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_displayMode.screenWidth, m_displayMode.screenHeight, flags);

    // Create The Window
    if (m_window == nullptr) {
        printf("Window Creation Failed\r\n");
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, (int)m_displayMode.major);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, (int)m_displayMode.minor);
    if (m_displayMode.core) {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    } else {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    }
    m_glc = SDL_GL_CreateContext((SDL_Window*)m_window);
    SDL_GL_MakeCurrent((SDL_Window*)m_window, (SDL_GLContext)m_glc);

    // Check for a valid context
    if (m_glc == nullptr) {
        printf("Could Not Create OpenGL Context");
        return false;
    }

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        printf("Glew failed to initialize. Your graphics card is probably WAY too old. Or you forgot to extract the .zip. It might be time for an upgrade :)");
        return false;
    }

    // Create default clear values
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);

    // Initialize Frame Buffer
    glViewport(0, 0, getWidth(), getHeight());

    { // Get supported window resolutions
        SDL_DisplayMode mode;
        // TODO(Ben): Handle other displays indices.
        int displayIndex = 0;
        int numDisplayModes = SDL_GetNumDisplayModes(displayIndex);
        for (int i = 0; i < numDisplayModes; i++) {
            SDL_GetDisplayMode(displayIndex, i, &mode);
            ui32v2 res(mode.w, mode.h);
            if (i == 0 || m_supportedResolutions.back() != res) {
                m_supportedResolutions.push_back(res);
            }
        }
    }

    // Set More Display Settings
    setSwapInterval(m_displayMode.swapInterval, true);

    // Push input from this window and receive quit signals
    // TODO(Ben): Input
    // ovox::InputDispatcher::init(this);
    // ovox::InputDispatcher::window.onClose += makeDelegate(*this, &Window::onQuitSignal);
    // ovox::InputDispatcher::onQuit += makeDelegate(*this, &Window::onQuitSignal);
    // ovox::InputDispatcher::window.onResize += makeDelegate(*this, &Window::onResize);
    m_quitSignal = false;

    return true;
}
void ovox::Window::dispose() {
    if (!isInitialized()) return;

    // TODO(Ben): Input
    // ovox::InputDispatcher::onQuit -= makeDelegate(*this, &Window::onQuitSignal);
    // ovox::InputDispatcher::window.onClose -= makeDelegate(*this, &Window::onQuitSignal);
    // ovox::InputDispatcher::window.onResize -= makeDelegate(*this, &Window::onResize);
    // ovox::InputDispatcher::dispose();

    if (m_glc) {
        SDL_GL_DeleteContext((SDL_GLContext)m_glc);
    }
    if (m_window) {
        SDL_DestroyWindow((SDL_Window*)m_window);
    }
    // Get rid of dangling pointers
    m_window = nullptr;
    m_glc = nullptr;
}

void ovox::Window::setScreenSize(i32 w, i32 h, bool overrideCheck /*= false*/) {
    // Apply A Minimal State Change
    if ((overrideCheck || m_displayMode.screenWidth != w || m_displayMode.screenHeight != h) && !m_displayMode.isFullscreen) {
        m_displayMode.screenWidth = w;
        m_displayMode.screenHeight = h;

        SDL_SetWindowSize(ovox_WINDOW_HANDLE(m_window), m_displayMode.screenWidth, m_displayMode.screenHeight);
        InputDispatcher::window.onResize({ w, h }); // TODO(Ben): This feels so dirty, but is necessary for LUA UI
    }
}
void ovox::Window::setFullscreen(bool useFullscreen, bool overrideCheck /*= false*/) {
    if (overrideCheck || m_displayMode.isFullscreen != useFullscreen) {
        m_displayMode.isFullscreen = useFullscreen;
        SDL_SetWindowFullscreen(ovox_WINDOW_HANDLE(m_window), m_displayMode.isFullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    }
}
void ovox::Window::setBorderless(bool useBorderless, bool overrideCheck /*= false*/) {
    if ((overrideCheck || m_displayMode.isBorderless != useBorderless) && !m_displayMode.isFullscreen) {
        m_displayMode.isBorderless = useBorderless;
        SDL_SetWindowBordered((SDL_Window*)m_window, m_displayMode.isBorderless ? SDL_FALSE : SDL_TRUE);
    }
}

void ovox::Window::setSwapInterval(GameSwapInterval mode, bool overrideCheck /*= false*/) {
    if (overrideCheck || m_displayMode.swapInterval != mode) {
        m_displayMode.swapInterval = mode;
        switch (m_displayMode.swapInterval) {
            case GameSwapInterval::UNLIMITED_FPS:
            case GameSwapInterval::USE_VALUE_CAP:
                SDL_GL_SetSwapInterval(0);
                break;
            default:
                SDL_GL_SetSwapInterval(static_cast<i32>(DEFAULT_SWAP_INTERVAL));
                break;
        }
    }
}
void ovox::Window::setMaxFPS(f32 fpsLimit) {
    m_displayMode.maxFPS = fpsLimit;
}
void ovox::Window::setTitle(const cString title) const {
    if (!title) title = DEFAULT_TITLE;
    SDL_SetWindowTitle((SDL_Window*)m_window, title);
}

void ovox::Window::setPosition(int x, int y) {
    SDL_SetWindowPosition((SDL_Window*)m_window, x, y);
}

void ovox::Window::sync(ui32 frameTime) {
    pollInput();
    SDL_GL_SwapWindow(ovox_WINDOW_HANDLE(m_window));

    // Limit FPS
    if (m_displayMode.swapInterval == GameSwapInterval::USE_VALUE_CAP) {
        f32 desiredFPS = 1000.0f / (f32)m_displayMode.maxFPS;
        u32 sleepTime = (u32)(desiredFPS - frameTime);
        if (desiredFPS > frameTime && sleepTime > 0) SDL_Delay(sleepTime);
    }
}

ovox::GraphicsContext ovox::Window::getContext() const {
    return m_glc;
}

i32 ovox::Window::getX() const {
    i32 v;
    SDL_GetWindowPosition(ovox_WINDOW_HANDLE(m_window), &v, nullptr);
    return v;
}
i32 ovox::Window::getY() const {
    i32 v;
    SDL_GetWindowPosition(ovox_WINDOW_HANDLE(m_window), nullptr, &v);
    return v;
}
i32v2 ovox::Window::getPosition() const {
    i32v2 v;
    SDL_GetWindowPosition(ovox_WINDOW_HANDLE(m_window), &v.x, &v.y);
    return v;
}

void ovox::Window::pollInput() {
    // TODO(Ben): Event filter
    // SDL_Event e;
    // while (SDL_PollEvent(&e) != 0) continue;
}

void ovox::Window::onResize(Sender s, const WindowResizeEvent& e) {
    m_displayMode.screenWidth = e.w;
    m_displayMode.screenHeight = e.h;
}

void ovox::Window::onQuitSignal(Sender) {
    m_quitSignal = true;
}
