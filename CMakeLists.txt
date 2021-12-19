cmake_minimum_required(VERSION 3.5)

project(Erender VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Gui REQUIRED)

message("Vulkan SDK path : $ENV{VULKAN_SDK}")

include_directories($ENV{VULKAN_SDK}/include)
link_directories($ENV{VULKAN_SDK}/lib)
link_directories(/usr/local/lib)
set(VKEnginePath externals/VKEngine)
add_subdirectory(${VKEnginePath})


set(PROJECT_INCLUDE
    contextmanager.cpp
    main.cpp
    mainwindow.cpp
    projectwindow.cpp
    erenderutility.cpp
    devicesetting.cpp
)

set(PROJECT_SRC
    contextmanager.h
    mainwindow.h
    projectwindow.h
    erenderutility.h
    devicesetting.h
)

set(PROJECT_UI
    mainwindow.ui
    devicesetting.ui
    projectwindow.ui
)

set(PROJECT_SOURCES
    ${PROJECT_INCLUDE}
    ${PROJECT_SRC}
    ${PROJECT_UI}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Erender
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Erender APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Erender SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Erender
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Erender PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Erender PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(Erender PRIVATE VKEngine)
target_include_directories(Erender PRIVATE ${VKEnginePath}/include)
set_target_properties(Erender PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Erender)
endif()
