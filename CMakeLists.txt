cmake_minimum_required(VERSION 3.16)
#project(ncurses_sample)
#
#set(CMAKE_CXX_STANDARD 20)
#
#find_package(Curses REQUIRED)
#include_directories(${CURSES_INCLUDE_DIRS})
#include_directories(${CURSES_INCLUDE_DIR})
#include_directories(include)
#
#add_executable(todoApp src/main.cpp src/Window.cpp include/Window.h include/Position.h src/TextContent.cpp include/TextContent.h)
#target_link_libraries(todoApp ${CURSES_LIBRARIES})
#target_compile_options(todoApp PRIVATE -Wall -Wextra)



project(monitor)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(monitor ${SOURCES} src/WindowManager.cpp include/WindowManager.h src/ColorManager.cpp include/ColorManager.h include/Colors.h src/InputWindow.cpp include/InputWindow.h src/DataList.cpp include/DataList.h src/TaskManager.cpp include/TaskManager.h)

set_property(TARGET monitor PROPERTY CXX_STANDARD 17)
target_link_libraries(monitor ${CURSES_LIBRARIES})
# TODO: Run -Werror in CI.
target_compile_options(monitor PRIVATE -Wall -Wextra)