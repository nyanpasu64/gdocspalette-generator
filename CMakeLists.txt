cmake_minimum_required(VERSION 3.14)

project(gdocspalette-generator LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui REQUIRED)

add_executable(gdocspalette-generator
  main.cpp
)
target_link_libraries(gdocspalette-generator Qt${QT_VERSION_MAJOR}::Gui fmt)
