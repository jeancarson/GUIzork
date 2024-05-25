cmake_minimum_required(VERSION 3.5)

project(zork3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Keycard.png
)

# qt6_add_resources(RESOURCE_FILES resources.qrc)



if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(zork3
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}







        maingamewindow.h maingamewindow.cpp maingamewindow.ui
        room.h room.cpp
        gamesetup.h gamesetup.cpp
        frontDoorGeneric.jpg


        conor.jpg
        taylor.jpg
        guide.h guide.cpp guide.ui
        guideLevel1.jpg
        guideLevel2.png
        item.h item.cpp
        task.h task.cpp

        Keycard.png
        inventorybackend.h inventorybackend.cpp
        timer.h timer.cpp
        umbrella.png
        lunchbox.png
        endgamescreen.h endgamescreen.cpp endgamescreen.ui
        gameWon.jpg
        gameLost.jpg
        enemy.h enemy.cpp
        character.h character.cpp
        threateningcharacter.h threateningcharacter.cpp
        curiouscharacter.h curiouscharacter.cpp
        anxiouscharacter.h anxiouscharacter.cpp
        resources.qrc
        logger.h logger.cpp
        ALISON.png MIA.png




    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET zork3 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(zork3 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(zork3
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(zork3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.zork3)
endif()
set_target_properties(zork3 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS zork3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(zork3)
endif()
