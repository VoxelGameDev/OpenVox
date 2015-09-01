find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${CMAKE_CURRENT_LIST_DIR}/include)

file(GLOB_RECURSE openvox_header_files
    ${CMAKE_CURRENT_LIST_DIR}/include/*.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/*.h
    ${CMAKE_CURRENT_LIST_DIR}/include/*.inl
    )

file(GLOB_RECURSE openvox_source_files
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/*.c
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cc
    )

ADD_LIBRARY(${CMAKE_PROJECT_NAME}
    ${openvox_header_files}
    ${openvox_source_files}
)

SET_TARGET_PROPERTIES(${CMAKE_PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

TARGET_INCLUDE_DIRECTORIES(${CMAKE_PROJECT_NAME} PUBLIC
    "$<BUILD_INTERFACE:"
    "$<INSTALL_INTERFACE:include>"
)
