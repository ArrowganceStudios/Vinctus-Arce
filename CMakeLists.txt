cmake_minimum_required (VERSION 3.14)
project (VinctusArce CXX)

# Installation settings
set(GAME_INSTALL_DIR ${CMAKE_SOURCE_DIR}/bin)
file(INSTALL ${CMAKE_SOURCE_DIR}/assets DESTINATION ${GAME_INSTALL_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${GAME_INSTALL_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${GAME_INSTALL_DIR})

# Allegro lib
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(ExternalAllegro)

# Pacman executable
add_subdirectory(src)
