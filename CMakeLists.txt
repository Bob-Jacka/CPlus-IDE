cmake_minimum_required(VERSION 3.28)

project(IDE_gui VERSION 0.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appIDE_gui
    main.cpp
)

qt_add_qml_module(appIDE_gui
    URI IDE_gui
    VERSION 1.0
    QML_FILES
        SOURCES

        QML_FILES
        StartWindow.qml
        SettingsWindow.qml
        Main.qml

        App.qml

        RightMenu.qml
        LeftMenu.qml
        MenuBar.qml
        UpperLevelMenu.qml

        Button.qml
        Menu.qml
        TxtInput.qml
        CheckBox.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appIDE_gui PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appIDE_gui
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appIDE_gui PRIVATE
    Qt6::Quick
    Qt6::Core
)

include(GNUInstallDirs)
install(TARGETS appIDE_gui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
