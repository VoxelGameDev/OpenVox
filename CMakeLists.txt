CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(openvox)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_files)

# Windows
IF (MSVC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Za /Wall")
    SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Zi /DEBUG /Od /MDd")
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ox")
    SET(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /Os")
    SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /Ox /Zi /Zo /DEBUG")

# Mac
ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    # for policy CMP0042
    SET(CMAKE_SKIP_BUILD_RPATH  TRUE)

    SET(WARNINGS
        "-Wall"
        "-Wextra"
        "-Wno-unknown-pragmas"
        "-Wpedantic"
        "-Wno-gnu-anonymous-struct"
        "-Wno-nested-anon-types"
        "-Wno-unused-parameter"
    )
    ADD_DEFINITIONS(
        -std=libc++
        -std=c++11
        -ferror-limit=1000
        ${WARNINGS}
    )
    INCLUDE_DIRECTORIES(/System/Library/Frameworks)
    INCLUDE_DIRECTORIES(/usr/local/opt/llvm/include)

# Linux
ELSE()
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Wpedantic")
    SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
    SET(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} -Os")
    SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -g -O3")

ENDIF()



ADD_SUBDIRECTORY(Engine)
