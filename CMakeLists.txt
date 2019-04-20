cmake_minimum_required(VERSION 3.5.1)
project(portend CXX)
set(EXECUTABLE_NAME "portend")



#-------------------------------------------------------------------------------
# Compiler config
#-------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    add_compile_options("-Wall")
    add_compile_options("-Wextra")
    add_compile_options("-Wconversion")
    add_compile_options("-pedantic")
    add_compile_options("-Wfatal-errors")
endif()



#-------------------------------------------------------------------------------
# target engine
#-------------------------------------------------------------------------------
set(ENGINE_PATH "./engine")
file(GLOB ENGINE_SOURCE
    "${ENGINE_PATH}/include/engine/*.hpp"
    "${ENGINE_PATH}/src/*.cpp"

    "${ENGINE_PATH}/include/engine/Application/*.hpp"
    "${ENGINE_PATH}/src/Application/*.cpp"

    "${ENGINE_PATH}/include/engine/Event/*.hpp"
    "${ENGINE_PATH}/src/Event/*.cpp"

    "${ENGINE_PATH}/include/engine/Window/*.hpp"
    "${ENGINE_PATH}/src/Window/*.cpp"

    "${ENGINE_PATH}/include/engine/ECSEngine/*.hpp"
    "${ENGINE_PATH}/src/ECSEngine/*.cpp"

    "${ENGINE_PATH}/include/engine/ECSEngine/utility/*.hpp"
    "${ENGINE_PATH}/src/ECSEngine/utility/*.cpp"
    )
if(ENGINE_SOURCE)
	message("-- Found engine at ${ENGINE_PATH}")
endif()
include_directories("${ENGINE_PATH}/include")



#-------------------------------------------------------------------------------
# target the portend game
#-------------------------------------------------------------------------------
set(GAME_PATH "./portend")
file(GLOB GAME_SOURCE
    "${GAME_PATH}/include/*.hpp"
    "${GAME_PATH}/src/*.cpp"
)
if(GAME_SOURCE)
    message("-- Found portend at ${GAME_PATH}")
endif()



#-------------------------------------------------------------------------------
# target spdlog
#-------------------------------------------------------------------------------
set(SPDLOG_PATH "./engine/vendor/spdlog/include")
include_directories(${SPDLOG_PATH})




set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED network audio graphics window system)
include_directories(${SFML_INCLUDE_DIR})



add_executable(${EXECUTABLE_NAME} ${ENGINE_SOURCE} ${GAME_SOURCE})
