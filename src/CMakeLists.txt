add_subdirectory(Game)
add_subdirectory(Graphics)
add_subdirectory(Menu)

list(APPEND GAME_SOURCES Common.h)
list(APPEND GAME_SOURCES GameEngine.cpp)
list(APPEND GAME_SOURCES GameEngine.h)
list(APPEND GAME_SOURCES Globals.h)
list(APPEND GAME_SOURCES Input.cpp)
list(APPEND GAME_SOURCES Input.h)
list(APPEND GAME_SOURCES InputMap.h)
list(APPEND GAME_SOURCES Main.cpp)
list(APPEND GAME_SOURCES Singleton.h)
list(APPEND GAME_SOURCES State.cpp)
list(APPEND GAME_SOURCES State.h)

set(GAME_TARGET VinctusArce)
add_executable(${GAME_TARGET} ${GAME_SOURCES})
target_link_libraries(${GAME_TARGET} PRIVATE ${ALLEGRO_LIBS})
target_include_directories(${GAME_TARGET} PRIVATE ${ALLEGRO_INCLUDES})