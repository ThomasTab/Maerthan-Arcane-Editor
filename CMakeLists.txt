cmake_minimum_required (VERSION 3.8)

project (Editor VERSION 0.2.0 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "D:/Qt/5.15.0/msvc2019_64/lib/cmake")
set(CMAKE_AUTOUIC_SEARCH_PATHS "${PROJECT_SOURCE_DIR}/ui")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

# QT
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# Add libraries
include_directories("${PROJECT_SOURCE_DIR}/include")

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(Qt5_USE_STATIC_LIBS ON)    
    set(Qt5_USE_STATIC_RUNTIME ON)

    add_executable(Editor WIN32
        "${PROJECT_SOURCE_DIR}/apps/main.cpp"
        "${PROJECT_SOURCE_DIR}/ui/editor.ui"
        "${PROJECT_SOURCE_DIR}/ui/editor.qrc"
        "${PROJECT_SOURCE_DIR}/ui/modifierWidget.ui"
        "${PROJECT_SOURCE_DIR}/src/element.cpp"
        "${PROJECT_SOURCE_DIR}/src/modifier.cpp"
        "${PROJECT_SOURCE_DIR}/src/editor.cpp"
        "${PROJECT_SOURCE_DIR}/src/modifierWidget.cpp"
        "${PROJECT_SOURCE_DIR}/include/element.h"
        "${PROJECT_SOURCE_DIR}/include/modifier.h"
        "${PROJECT_SOURCE_DIR}/include/editor.h"
        "${PROJECT_SOURCE_DIR}/include/modifierWidget.h"
    )
else()
    add_executable(Editor
        "${PROJECT_SOURCE_DIR}/apps/main.cpp"
        "${PROJECT_SOURCE_DIR}/ui/editor.ui"
        "${PROJECT_SOURCE_DIR}/ui/editor.qrc"
        "${PROJECT_SOURCE_DIR}/ui/modifierWidget.ui"
        "${PROJECT_SOURCE_DIR}/src/element.cpp"
        "${PROJECT_SOURCE_DIR}/src/modifier.cpp"
        "${PROJECT_SOURCE_DIR}/src/editor.cpp"
        "${PROJECT_SOURCE_DIR}/src/modifierWidget.cpp"
        "${PROJECT_SOURCE_DIR}/include/element.h"
        "${PROJECT_SOURCE_DIR}/include/modifier.h"
        "${PROJECT_SOURCE_DIR}/include/editor.h"
        "${PROJECT_SOURCE_DIR}/include/modifierWidget.h"
    )
endif()

target_link_libraries(Editor Qt5::Core Qt5::Widgets)
