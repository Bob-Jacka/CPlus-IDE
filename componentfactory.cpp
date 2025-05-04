#include "componentfactory.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <exception>
#include "UtilFuncs.hpp"
#include "mainwindow.hpp"
#include "settingswindow.hpp"

#define MIN_BUTTON_SIZE 50
#define MAX_BUTTON_SIZE 100
#define POP_UP_WIDTH 200
#define POP_UP_HEIGHT 200

ComponentFactory::ComponentFactory()
{
//
}

ComponentFactory::~ComponentFactory()
{
//
}

//Private constructs
/*
 * Initialize main menu in main window.
 */
// void ComponentFactory::construct_upper_level_menu()
// {
//     println("Upper level menu is initialized");
//     mainWindow->setUpperLevelMenu(new QWidget());
//     QPushButton* run_btn = new QPushButton();
//     QPushButton* debug_btn = new QPushButton();
//     QHBoxLayout layout;

//     run_btn->resize(MIN_BUTTON_SIZE, MIN_BUTTON_SIZE);
//     debug_btn->resize(MIN_BUTTON_SIZE, MIN_BUTTON_SIZE);

//     layout.addWidget(mainWindow->getUpperLevelMenu());
//     layout.addWidget(run_btn);
//     layout.addWidget(debug_btn);
// }

/*
 * Initialize left menu in main window.
 */
void ComponentFactory::construct_left_menu(MainWindow* &mainWindow) const
{
    try {
        println("Left menu is initialized");
        mainWindow->setLeftMenu(new LeftMenu());
        QPushButton *git_btn = new QPushButton("git");
        QPushButton *todo_btn = new QPushButton("To do");
        QVBoxLayout layout;

        git_btn->resize(MIN_BUTTON_SIZE, MIN_BUTTON_SIZE);
        todo_btn->resize(MIN_BUTTON_SIZE, MIN_BUTTON_SIZE);

        layout.addWidget(git_btn);
        layout.addWidget(todo_btn);
    }
    catch (exception &e) {
        println("An exception ocurred in Component factory - construct left menu");
    }
}

/*
 * Initialize right menu in main window.
 */
void ComponentFactory::construct_right_menu(MainWindow* &window) const
{
    try {
        println("Right menu is initialized");
        window->setRightMenu(new RightMenu());
        QVBoxLayout layout;
    }
    catch (exception &e) {
        println("An exception ocurred in Component factory - construct right menu");
    }
}

//Public constructs

/*
 *Method for constructing settings window.
 */
bool ComponentFactory::construct_settings_window(SettingsWindow* &settingsWindow) const {
    try {
        settingsWindow = new SettingsWindow();
        if (settingsWindow != nullptr) {
            settingsWindow->show();
            return true;
        } else {
            return false;
        }
    }
    catch(exception &e) {
        println("An exception ocurred in Component factory - construct settings window");
    }
    return false;
}

bool ComponentFactory::construct_main_window(MainWindow* &mainWindow) const {
    try {
        mainWindow = new MainWindow();
        if (mainWindow != nullptr) {
            mainWindow->show();
            return true;
        } else {
            return false;
        }
    }
    catch(exception &e) {
        println("An exception ocurred in Component factory - construct main window");
    }
    return false;
}

bool ComponentFactory::construct_startup_window(StartWindow* &startupWindow) const {
    try {
        startupWindow = new StartWindow();
        if (startupWindow != nullptr) {
            startupWindow->show();
            // connect(this, &ComponentFactory::window_created, &ComponentFactory::create_main_window);
            return true;
        } else {
            return false;
        }
    }
    catch(exception &e) {
        println("An exception ocurred in Component factory - construct startup window");
    }
    return false;
}

void ComponentFactory::create_main_window() {
    emit this->window_created();
}

void ComponentFactory::create_settings_window() {
    emit this->window_created();
}

void ComponentFactory::create_startup_window() {
    emit this->window_created();
}

void ComponentFactory::create_info_pop_up() {
    emit this->pop_up_created();
}
