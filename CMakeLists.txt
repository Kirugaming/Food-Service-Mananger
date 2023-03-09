cmake_minimum_required(VERSION 3.5)

project(FoodServiceManager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Sql Qml Charts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        initDatabase.h
        BestFitLine.h
        customrectitem.cpp
        customrectitem.h
        admin.h admin.cpp admin.ui
        editablesqlmodel.cpp editablesqlmodel.h
        embeddeddialog.ui embeddeddialog.cpp embeddeddialog.h
        feedbackgraphs.cpp feedbackgraphs.h feedbackgraphs.ui

)

if(6 GREATER_EQUAL 6)
    qt_add_executable(FoodServiceManager
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET FoodServiceManager APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(FoodServiceManager SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(FoodServiceManager
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(FoodServiceManager PRIVATE Qt6::Widgets Qt6::Sql Qt6::Qml Qt6::Charts)
set_target_properties(FoodServiceManager PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS FoodServiceManager
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FoodServiceManager)
endif()
