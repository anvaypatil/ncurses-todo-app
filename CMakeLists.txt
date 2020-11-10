cmake_minimum_required(VERSION 3.16)
project(monitor)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(monitor ${SOURCES} src/WindowManager.cpp include/WindowManager.h src/ColorManager.cpp include/ColorManager.h include/Colors.h src/InputWindow.cpp include/InputWindow.h src/DataList.cpp include/DataList.h src/TaskManager.cpp include/TaskManager.h src/TaskPersistence.cpp include/TaskPersistence.h include/Serializable.h src/TaskItem.cpp include/TaskItem.h)

set_property(TARGET monitor PROPERTY CXX_STANDARD 17)
target_link_libraries(monitor ${CURSES_LIBRARIES})
# TODO: Run -Werror in CI.
target_compile_options(monitor PRIVATE -Wall -Wextra)