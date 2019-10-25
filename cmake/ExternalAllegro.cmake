include(FetchContent)
set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/3rdparty)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

set(ALLEGRO_PROJECT "allegro_project")

# Setting options by set() instead of CMAKE_ARGS in FetchContent
# because the policy CMP0077 wasn't set to NEW in allegro project.
# In other words, the CMAKE_ARGS cache variable settings are 
# overwritten by the default cache values determined by allegro,
# when this policy is not set.
set(WANT_DOCS OFF CACHE INTERNAL "")
set(WANT_DOCS_HTML OFF CACHE INTERNAL "")
set(WANT_DOCS_MAN OFF CACHE INTERNAL "")
set(WANT_DEMO OFF CACHE INTERNAL "")
set(WANT_EXAMPLES OFF CACHE INTERNAL "")
set(WANT_POPUP_EXAMPLES OFF CACHE INTERNAL "")
set(WANT_POPUP_EXAMPLES OFF CACHE INTERNAL "")
set(WANT_TESTS OFF CACHE INTERNAL "")

FetchContent_Declare(
  ${ALLEGRO_PROJECT}
  GIT_REPOSITORY      "https://github.com/liballeg/allegro5.git"
  CMAKE_ARGS          -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
  GIT_SHALLOW         TRUE
)
FetchContent_MakeAvailable(${ALLEGRO_PROJECT})

# Base allegro includes and targets
list(APPEND ALLEGRO_INCLUDES ${${ALLEGRO_PROJECT}_BINARY_DIR}/include)
list(APPEND ALLEGRO_INCLUDES ${${ALLEGRO_PROJECT}_SOURCE_DIR}/include)
list(APPEND ALLEGRO_LIBS allegro)

# Addons includes and targets
set(ALLEGRO_ADDON_PATH ${${ALLEGRO_PROJECT}_SOURCE_DIR}/addons)
list(APPEND ALLEGRO_INCLUDES ${ALLEGRO_ADDON_PATH}/primitives)
list(APPEND ALLEGRO_INCLUDES ${ALLEGRO_ADDON_PATH}/image)
list(APPEND ALLEGRO_INCLUDES ${ALLEGRO_ADDON_PATH}/font)
list(APPEND ALLEGRO_INCLUDES ${ALLEGRO_ADDON_PATH}/ttf)
list(APPEND ALLEGRO_INCLUDES ${ALLEGRO_ADDON_PATH}/audio)
list(APPEND ALLEGRO_INCLUDES ${ALLEGRO_ADDON_PATH}/acodec)
list(APPEND ALLEGRO_LIBS allegro_primitives)
list(APPEND ALLEGRO_LIBS allegro_image)
list(APPEND ALLEGRO_LIBS allegro_font)
list(APPEND ALLEGRO_LIBS allegro_ttf)
list(APPEND ALLEGRO_LIBS allegro_audio)
list(APPEND ALLEGRO_LIBS allegro_acodec)