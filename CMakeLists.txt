cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)

include(ExternalProject)

project(EnttPong)

# Install all final products of ExternalProject_ADD() at this location
set(EXTERNAL_INSTALL_PATH "${CMAKE_BINARY_DIR}/external")

FIND_LIBRARY(COCOA_LIBRARY Cocoa)

if(APPLE)
	# Download & build SDL2 dependency
	ExternalProject_Add(
	        sdl2

	        URL         https://libsdl.org/release/SDL2-2.0.8.zip
	        #install it in the build directory. no "" chars because they break SDL2's installation :(
	        CMAKE_ARGS  -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_PATH} -DCMAKE_OSX_ARCHITECHURES=i386;x86_64
	)

        set(
                SDL2_LINK_DEPENDENCIES

                # Those two might be Linux/MacOs specific ?
                PRIVATE dl
                PRIVATE pthread
                PRIVATE ${COCOA_LIBRARY}
        )
elseif(LINUX OR UNIX)
	# Download & build SDL2 dependency
	ExternalProject_Add(
	        sdl2

	        URL         https://libsdl.org/release/SDL2-2.0.8.zip
	        #install it in the build directory. no "" chars because they break SDL2's installation :(
	        CMAKE_ARGS  -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_PATH}
	)

        set(
                SDL2_LINK_DEPENDENCIES

                # Those two might be Linux/MacOs specific ?
                PRIVATE dl
                PRIVATE pthread
        )
endif()

# Cross-platform SDL2 static library filenames & paths
set(SDL2_STATIC_FILENAME            "${CMAKE_STATIC_LIBRARY_PREFIX}SDL2${CMAKE_STATIC_LIBRARY_SUFFIX}")
set(SDL2_STATIC_LIBRARY_PATH        "${EXTERNAL_INSTALL_PATH}/lib/${SDL2_STATIC_FILENAME}")

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
        EnttPong/src/tags/BallTag.cpp
        EnttPong/src/tags/BallTag.hpp
        EnttPong/src/tags/AITag.cpp
        EnttPong/src/tags/AITag.hpp

        EnttPong/src/graphics/Window.cpp
        EnttPong/src/graphics/Window.hpp

        EnttPong/src/systems/MoveSystem.cpp
        EnttPong/src/systems/MoveSystem.hpp
        EnttPong/src/systems/RenderSystem.cpp
        EnttPong/src/systems/RenderSystem.hpp
        EnttPong/src/systems/CollisionSystem.hpp
        EnttPong/src/systems/CollisionSystem.cpp
        EnttPong/src/systems/AISystem.hpp
        EnttPong/src/systems/AISystem.cpp

        EnttPong/src/components/PositionComponent.cpp
        EnttPong/src/components/PositionComponent.hpp
        EnttPong/src/components/SpriteComponent.cpp
        EnttPong/src/components/SpriteComponent.hpp

        EnttPong/src/utils/RandomVelocity.hpp

        # SDL2_gfx dependency (sources directly integrated to the project)
        EnttPong/src/libs/SDL2_gfx/SDL2_gfxPrimitives.c
        EnttPong/src/libs/SDL2_gfx/SDL2_gfxPrimitives.h
        EnttPong/src/libs/SDL2_gfx/SDL2_gfxPrimitives_font.h
        EnttPong/src/libs/SDL2_gfx/SDL2_rotozoom.c
        EnttPong/src/libs/SDL2_gfx/SDL2_rotozoom.h

        #entt dependency
        EnttPong/src/libs/entt/core/family.hpp
        EnttPong/src/libs/entt/core/hashed_string.hpp
        EnttPong/src/libs/entt/core/ident.hpp

        EnttPong/src/libs/entt/entity/actor.hpp
        EnttPong/src/libs/entt/entity/entt_traits.hpp
        EnttPong/src/libs/entt/entity/registry.hpp
        EnttPong/src/libs/entt/entity/sparse_set.hpp
        EnttPong/src/libs/entt/entity/view.hpp

		EnttPong/src/libs/entt/locator/locator.hpp

		EnttPong/src/libs/entt/process/process.hpp
		EnttPong/src/libs/entt/process/scheduler.hpp

		EnttPong/src/libs/entt/resource/cache.hpp
		EnttPong/src/libs/entt/resource/handle.hpp
		EnttPong/src/libs/entt/resource/loader.hpp

		EnttPong/src/libs/entt/signal/bus.hpp
		EnttPong/src/libs/entt/signal/delegate.hpp
		EnttPong/src/libs/entt/signal/dispatcher.hpp
		EnttPong/src/libs/entt/signal/emitter.hpp
		EnttPong/src/libs/entt/signal/sigh.hpp
		EnttPong/src/libs/entt/signal/signal.hpp

		EnttPong/src/libs/entt/entt.hpp
)	

add_executable(
        "${ENTTPONG_EXE}"
        "${ENTTPONG_SOURCES}"
)

# Make sure project's dependencies have been cloned/built before building enttpong
add_dependencies(
        "${ENTTPONG_EXE}"
        sdl2
)


target_include_directories(
        "${ENTTPONG_EXE}"
        PRIVATE "${EXTERNAL_INSTALL_PATH}/include"
)

target_link_libraries(
        "${ENTTPONG_EXE}"

        ${SDL2_LINK_DEPENDENCIES}
        PRIVATE ${SDL2_STATIC_LIBRARY_PATH}
)