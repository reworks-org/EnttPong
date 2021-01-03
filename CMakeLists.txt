cmake_minimum_required(VERSION 3.7)

project(entt_pong LANGUAGES C CXX)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds not allowed. Please make a new build directory and run CMake from there.\n")
endif()

set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_C_FLAGS_RELEASE "")
set(CMAKE_CXX_FLAGS "")
set(CMAKE_CXX_FLAGS_DEBUG "")
set(CMAKE_CXX_FLAGS_RELEASE "")
set(CMAKE_EXE_LINKER_FLAGS "")
set(CMAKE_MODULE_LINKER_FLAGS "")
set(CMAKE_SHARED_LINKER_FLAGS "")
set(CMAKE_STATIC_LINKER_FLAGS "")

set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS}")
set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_MODULE_LINKER_FLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS}")
set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS}")
set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS}")
set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "${CMAKE_STATIC_LINKER_FLAGS}")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CONFIGURATION_TYPES
        "Debug"
        "Release"
        CACHE STRING "" FORCE
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_source_files_properties(*.c LANGUAGE C)
set_source_files_properties(*.cc LANGUAGE CXX)
set_source_files_properties(*.cpp LANGUAGE CXX)
set_source_files_properties(*.h LANGUAGE C)
set_source_files_properties(*.hh LANGUAGE CXX)
set_source_files_properties(*.hpp LANGUAGE CXX)
set_source_files_properties(*.inl LANGUAGE CXX)

file(GLOB_RECURSE entt_pong_src
    "${CMAKE_SOURCE_DIR}/EnttPong/*.cpp"
    "${CMAKE_SOURCE_DIR}/EnttPong/*.hpp"
    "${CMAKE_SOURCE_DIR}/deps/SDL2_gfx/src/*.c"
)

source_group(${PROJECT_NAME} ${entt_pong_src})
add_executable(${PROJECT_NAME} ${entt_pong_src})

set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/bin"
    PDB_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output/bin"
)

if (MSVC)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/deps/SDL2/lib/x64/SDL2.dll" "${CMAKE_SOURCE_DIR}/output/bin/${CMAKE_BUILD_TYPE}/SDL2.dll")
    
    set(USE_MSVC_RUNTIME_LIBRARY_DLL OFF CACHE BOOL "" FORCE)
    set(FORCE_STATIC_VCRT ON CACHE BOOL "" FORCE)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

    set(SDL2_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/deps/SDL2/include")

    SET(SDL2_LIB "${CMAKE_SOURCE_DIR}/deps/SDL2/lib/x64/SDL2.lib")
    SET(SDL2MAIN_LIB "${CMAKE_SOURCE_DIR}/deps/SDL2/lib/x64/SDL2main.lib")
    set(SDL2_LIBRARIES
        "${SDL2_LIB}"
        "${SDL2MAIN_LIB}"
    )

    set(LIB_FILES
        "${SDL2_LIBRARIES}"
        "opengl32.lib"
        "kernel32.lib"
        "user32.lib"
        "gdi32.lib"
        "winspool.lib"
        "comdlg32.lib"
        "advapi32.lib"
        "shell32.lib"
        "ole32.lib"
        "oleaut32.lib"
        "uuid.lib"
        "winmm.lib"
        "Shlwapi.lib"
        "psapi.lib"
        "dsound.lib"
        "synchronization.lib"
    )
else()
    find_package(SDL2 REQUIRED)

    set(LIB_FILES
        "${SDL2_LIBRARIES}"
        "pthread"
        "dl"
    )
endif()

set(HEADERS
    "${SDL2_INCLUDE_DIRS}"
    "${CMAKE_SOURCE_DIR}/deps/entt/src"
    "${CMAKE_SOURCE_DIR}/deps/SDL2_gfx/include"
)
target_include_directories(${PROJECT_NAME} PUBLIC ${HEADERS})

include(cmake/CompileDefs.cmake)
include(cmake/LinkDefs.cmake)
include(cmake/PreprocessorDefs.cmake)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PUBLIC ${PREPROCESSOR_FLAGS_DEBUG})
    target_compile_options(${PROJECT_NAME} PUBLIC ${COMPILE_FLAGS_DEBUG})
    target_link_options(${PROJECT_NAME} PUBLIC ${LINK_FLAGS_DEBUG})
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    target_compile_definitions(${PROJECT_NAME} PUBLIC ${PREPROCESSOR_FLAGS_RELEASE})
    target_compile_options(${PROJECT_NAME} PUBLIC ${COMPILE_FLAGS_RELEASE})
    target_link_options(${PROJECT_NAME} PUBLIC ${LINK_FLAGS_RELEASE})
else()
    message(FATAL_ERROR "Could not determine build configuration. Is currently: ${CMAKE_BUILD_TYPE}")
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC "${LIB_FILES}")
