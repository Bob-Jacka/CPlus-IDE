cmake_minimum_required(VERSION 3.28)
project(untitled LANGUAGES CXX)

find_package(Qt6 6.8 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(untitled
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.hpp

    settingswindow.hpp settingswindow.cpp
    FileController.hpp
    UtilFuncs.hpp
    componentfactory.h componentfactory.cpp
    startwindow.h startwindow.cpp
    ExternalVariables.h
    IWindowTheme.cpp

)

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)

# add_executable()
# target_link_libraries()

target_link_libraries(untitled
    PRIVATE
        Qt6::Core
        Qt6::Widgets
)

include(GNUInstallDirs)

install(TARGETS untitled
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET untitled
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
