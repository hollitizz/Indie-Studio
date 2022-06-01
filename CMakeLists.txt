cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(bomberman)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (POLICY CMP0072)
  set(OpenGL_GL_PREFERENCE LEGACY)
endif()

# Dependencies
find_package(raylib 4.0.0 QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()
IF(UNIX)
  SET(MY_MATH_LIB -lm)
ELSE(UNIX)
  SET(MY_MATH_LIB)
ENDIF(UNIX)

INCLUDE_DIRECTORIES(headers/)
INCLUDE_DIRECTORIES(headers/Scenes/)
INCLUDE_DIRECTORIES(headers/Dependencies/)
FILE(GLOB SOURCES sources/Dependencies/*.cpp sources/Scenes/*.cpp sources/Bomberman.cpp sources/State.cpp sources/main.cpp)

ADD_EXECUTABLE(bomberman ${SOURCES})
TARGET_LINK_LIBRARIES(bomberman raylib)