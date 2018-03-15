cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

include(ExternalProject)

project(ray)

# Install all final products of ExternalProject_ADD() at this location
set(EXTERNAL_INSTALL_PATH "${CMAKE_BINARY_DIR}/external")

# Download & build SDL2 dependency
ExternalProject_Add(
        sdl2

        URL         https://libsdl.org/release/SDL2-2.0.8.zip
        #install it in the build directory. no "" chars because they break SDL2's installation :(
        CMAKE_ARGS  -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_PATH}
)

# Not handled yet, no CMakeList in SDL_gfx sources
#ExternalProject_Add(
#        sdlgfx
#        URL         http://www.ferzkopp.net/Software/SDL2_gfx/SDL2_gfx-1.0.4.tar.gz
#        CMAKE_ARGS  "-DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_PATH}"
#
#)

# entt ECS engine cloning
ExternalProject_Add(
        entt

        GIT_REPOSITORY  https://github.com/skypjack/entt
        # Header-only library -> no build/install phase (Entt's build breaks when used as ExternalProject)
        INSTALL_COMMAND ""
        # Define the cloning path (build/entt)
        PREFIX          "${CMAKE_BINARY_DIR}/entt"
        # Turn off Entt's tests (Causing a build error)
        CMAKE_ARGS      -DBUILD_TESTING=OFF
)

# Executable's name & sources
set(ENTTPONG_EXE "enttpong")
set(
        ENTTPONG_SOURCES

        EnttPong/src/main.cpp

        EnttPong/src/core/BasicLog.hpp
        EnttPong/src/core/Game.cpp
        EnttPong/src/core/Game.hpp

        EnttPong/src/tags/PlayerTag.cpp
        EnttPong/src/tags/PlayerTag.hpp

        EnttPong/src/graphics/Window.cpp
        EnttPong/src/graphics/Window.hpp

        EnttPong/src/systems/MoveSystem.cpp
        EnttPong/src/systems/MoveSystem.hpp
        EnttPong/src/systems/RenderSystem.cpp
        EnttPong/src/systems/RenderSystem.hpp

        EnttPong/src/components/PositionComponent.cpp
        EnttPong/src/components/PositionComponent.hpp
        EnttPong/src/components/SpriteComponent.cpp
        EnttPong/src/components/SpriteComponent.hpp
        EnttPong/src/components/VelocityComponent.cpp
        EnttPong/src/components/VelocityComponent.hpp
)

add_executable(
        "${ENTTPONG_EXE}"
        "${ENTTPONG_SOURCES}"
)

# Make sure project's dependencies have been cloned/built before building enttpong
add_dependencies(
        "${ENTTPONG_EXE}"
        sdl2
        # sdlgfx # Not handled yet
        entt
)


target_include_directories(
        "${ENTTPONG_EXE}"
        # Kinda hackish, maybe there is a better way to do this ?
        # Can't use CMake's find_* functions because Entt is an ExternalProject
        PRIVATE "${CMAKE_BINARY_DIR}/entt/src/entt"
        PRIVATE "${EXTERNAL_INSTALL_PATH}/include"
)

# Cross-platform SDL2 static library filenames & paths
set(SDL2_STATIC_FILENAME            "${CMAKE_STATIC_LIBRARY_PREFIX}SDL2${CMAKE_STATIC_LIBRARY_SUFFIX}")
set(SDL2_STATIC_LIBRARY_PATH        "${EXTERNAL_INSTALL_PATH}/lib/${SDL2_STATIC_FILENAME}")
target_link_libraries(
        "${ENTTPONG_EXE}"

        # Those two might be Linux/MacOs specific ?
        PRIVATE dl
        PRIVATE pthread

        PRIVATE ${SDL2_STATIC_LIBRARY_PATH}

        # Unhandled dependency as of now. Users are expected to have it installed in their environment.
        PRIVATE SDL_gfx
)