#include "componentfactory.h"

#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include "ComponentNames.hpp"
#include "ExternalVariable.h"
#include "UtilFuncs.hpp"
#include "mainwindow.hpp"
#include "settingswindow.hpp"
#include <exception>

ComponentFactory::ComponentFactory()
{
    if (logger != nullptr) {
        logger->log_message("Component factory created");
    } else {
        println("Component factory created");
    }
}

ComponentFactory::~ComponentFactory()
{
    if (logger != nullptr) {
        cfactory = nullptr;
        logger->log_message("Component factory destroyed");
    } else {
        println("Component factory destroyed");
    }
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
        QPushButton *git_btn = new QPushButton(GIT_BTN);
        QPushButton *todo_btn = new QPushButton(TO_DO_BTN);
        QVBoxLayout *layout = new QVBoxLayout();

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
        logger->log_message("Settings window created");
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
        logger->log_message("Main window created");
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

/*
 *Creates window with input fields for new project name and directory where it will be stored. 
 */
bool ComponentFactory::construct_new_project_window() const
{
    QWidget *proj_window = new QWidget("Create new project");
    proj_window->resize(POP_UP_WIDTH, POP_UP_HEIGHT);
    QTextEdit *proj_name_input = new QTextEdit();
    QTextEdit *proj_dir_input = new QTextEdit();
    QPushButton *accept_creating = new QPushButton("Create");
    QPushButton *cancel_creating = new QPushButton("Cancel");
    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(proj_name_input);
    layout->addWidget(proj_dir_input);
    layout->addWidget(accept_creating);
    layout->addWidget(cancel_creating);

    proj_window->setLayout(layout);
    proj_window->show();
    return true;
}

/*
 *Method for constructing pop with given name and text. 
 */
void ComponentFactory::construct_pop_up(std::string name, std::string text) const
{
    QMessageBox *msgBox;
    msgBox->setWindowTitle(name);
    msgBox->setText(text);
    msgBox->resize(POP_UP_WIDTH, POP_UP_HEIGHT);
    logger->log_message("Pop up created");
    msgBox->exec();
}

bool ComponentFactory::construct_startup_window(StartWindow* &startupWindow) const {
    try {
        startupWindow = new StartWindow();
        logger->log_message("Start window created");
        if (startupWindow != nullptr) {
            startupWindow->show();
            // connect(this, &ComponentFactory::window_created, &ComponentFactory::create_main_window);
            return true;
        } else {
            return false;
        }
    } catch (exception &e) {
        logger->log_error("An exception ocurred in Component factory - construct startup window");
    }
    return false;
}

//Other constructs

bool ComponentFactory::create_logger()
{
    try {
        logger = new Logger();
        if (logger != nullptr) {
            logger->log_message("Logger created");
            return true;
        } else {
            return false;
        }
    } catch (exception &e) {
        println("Error ocurred during logger creating.");
    }
}

//Slots for component factory class.

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
