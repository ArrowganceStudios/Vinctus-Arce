add_subdirectory(Layers)
list(APPEND GAME_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Camera.cpp)
list(APPEND GAME_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Camera.h)
list(APPEND GAME_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Layer.cpp)
list(APPEND GAME_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Layer.h)

set(GAME_SOURCES ${GAME_SOURCES} PARENT_SCOPE)