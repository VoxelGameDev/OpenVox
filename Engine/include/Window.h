//
// Window.cpp
// OpenVox Engine
//
// Created by Benjamin Arnold on 31 Aug 2015
// Pulled from Vorb Engine.
//

/*! \file Window.cpp
* @brief Window class for creating a window with an OpenGL context.
*/

#pragma once

#include "OVOX.h"
#include "Events.hpp"

namespace ovox {
    // Forward declarations
    struct WindowResizeEvent;

    typedef void* WindowHandle; ///< Typeless window handle;
    typedef void* GraphicsContext; ///< Typeless graphics handle.

#define DEFAULT_TITLE "OpenVox Window"
#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600
#define DEFAULT_SWAP_INTERVAL GameSwapInterval::V_SYNC
#define DEFAULT_MAX_FPS 60.0f

    /*! @brief Swapping intervals used for monitor synchronization and graphics stability.
    */
    enum class GameSwapInterval : i32 {
        UNLIMITED_FPS = 0, ///< No synchronization or FPS limiting is performed.
        V_SYNC = 1, ///< Synchronize with monitor frame by frame, full refresh rate.
        LOW_SYNC = 2, ///< Skip synchronization every other frame, half the refresh rate of the system.
        POWER_SAVER = 3, ///< Large pause between window and graphics updates, saves computations and power.
        USE_VALUE_CAP = 4 ///< Do not use monitor synchronization, but FPS cap and high resolution timer.
    };

    /*! @brief Window properties that additionally define graphics usage.
    */
    struct GameDisplayMode {
    public:
        UNIT_SPACE(PIXEL) i32 screenWidth = DEFAULT_WINDOW_WIDTH; ///< Width of the backbuffer (and borderless window width).
        UNIT_SPACE(PIXEL) i32 screenHeight = DEFAULT_WINDOW_HEIGHT; ///< Height of the backbuffer (and borderless window height).

        bool isFullscreen = false; ///< True if the window is fullscreen.
        bool isBorderless = false; ///< True if the window does not have a border.
        bool isResizable = true; ///< True if the window can be resized.

        GameSwapInterval swapInterval = DEFAULT_SWAP_INTERVAL; ///< Synchronization value for the system's refresh rate.
        f32 maxFPS = DEFAULT_MAX_FPS; ///< Maximum desired FPS with if the FPS limiter is used.

        u32 major = 3; ///< Major version for the graphics context (ex. GL:3).
        u32 minor = 2; ///< Minor version for the graphics context (ex. GL:2).
        bool core = false; ///< True if the graphics context should disable compatibility with lower versions.
    };

    class Window {
    public:
        /*! @brief Initializes window with default application settings.
        *
        * Does not create the physical window or modify any OS settings.
        */
        Window();

        /*! @brief Create the window and graphics context.
        *
        * @return True if no error occurred.
        */
        bool init(GameDisplayMode* displayMode = nullptr);
        /*! @brief Destroys the window and associated graphics context.
        *
        * @pre: This disposal method should be called on the thread where the window was created and the
        * graphics context has ownership.
        *
        * The window will save its current settings to DEFAULT_APP_CONFIG_FILE. The InputDispatcher will
        * be destroyed.
        */
        void dispose();

        /*! @brief A check for whether the window has been created or not.
        *
        * @return True if the window is created and if it is still alive.
        */
        bool isInitialized() const {
            return m_window != nullptr;
        }

        /*! @brief Detection of input to terminate this window.
        *
        * @return True if a quit signal was received by this window.
        */
        const bool& shouldQuit() const {
            return m_quitSignal;
        }

        // Access Display Settings
        int getX() const;
        int getY() const;
        i32v2 getPosition() const;
        const int& getWidth() const {
            return m_displayMode.screenWidth;
        }
        const int& getHeight() const {
            return m_displayMode.screenHeight;
        }
        u32v2 getViewportDims() const {
            return ui32v2(m_displayMode.screenWidth, m_displayMode.screenHeight);
        }
        f32 getAspectRatio() const {
            return (float)m_displayMode.screenWidth / (float)m_displayMode.screenHeight;
        }
        const bool& isFullscreen() const {
            return m_displayMode.isFullscreen;
        }
        const bool& isBorderless() const {
            return m_displayMode.isBorderless;
        }
        const bool& isResizable() const {
            return m_displayMode.isResizable;
        }
        const GameSwapInterval& getSwapInterval() const {
            return m_displayMode.swapInterval;
        }
        const f32& getMaxFPS() const {
            return m_displayMode.maxFPS;
        }
        WindowHandle getHandle() const {
            return m_window;
        }
        const std::vector<u32v2>& getSupportedResolutions() const {
            return m_supportedResolutions;
        }

        GraphicsContext getContext() const;

        // Change Display Settings
        void setScreenSize(int w, int h, bool overrideCheck = false);
        void setFullscreen(bool useFullscreen, bool overrideCheck = false);
        void setBorderless(bool useBorderless, bool overrideCheck = false);
        void setSwapInterval(GameSwapInterval mode, bool overrideCheck = false);
        /*! @brief Sets the position of the window
        * @param x: X position. 0 will center it.
        * @param Y: Y position. 0 will center it.
        */
        void setPosition(int x, int y);
        void setMaxFPS(f32 fpsLimit);
        void setTitle(const cString title) const;

        void sync(u32 frameTime = UINT_MAX);

        Event<> onQuit;

    private:
        OPENVOX_NON_COPYABLE(Window);
        OPENVOX_NON_COPYABLE(Window);

        void onResize(Sender s, const WindowResizeEvent& e);
        void onQuitSignal(Sender);
        void pollInput();

        std::vector<u32v2> m_supportedResolutions; ///< All resolutions supported by the window
        WindowHandle m_window = nullptr; ///< Window's OS handle.
        GraphicsContext m_glc = nullptr; ///< Window's graphics context.
        GameDisplayMode m_displayMode; ///< The current display settings of the window.
        bool m_quitSignal = false; ///< Flag for the window's termination request status.
    };
}
