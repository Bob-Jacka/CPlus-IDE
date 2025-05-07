#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include "mainwindow.hpp"
#include "settingswindow.hpp"
#include "startwindow.h"
#include <string>

#include <QObject>

#define MIN_BUTTON_SIZE 50
#define MAX_BUTTON_SIZE 100

//Pop up sizes
#define POP_UP_WIDTH 200
#define POP_UP_HEIGHT 200

//Window sizes
#define MIN_WINDOW_HEIGHT 400
#define MAX_WINDOW_HEIGHT 1080

#define MIN_WINDOW_WIDTH 400
#define MAX_WINDOW_WIDTH 1920

//default IDE sizes
#define IDE_WIDTH 1680
#define IDE_HEIGHT 1080

class ComponentFactory : QObject
{
    Q_OBJECT
private:
//

public:
    ComponentFactory();
    ~ComponentFactory();

    //Windows constructs
    bool construct_main_window(MainWindow* &) const;
    bool construct_settings_window(SettingsWindow* &) const;
    bool construct_startup_window(StartWindow* &) const;
    bool construct_new_project_window() const; //window with creating new project functionaly
    void construct_pop_up(std::string name, std::string text) const;

    //Menus constructs
    void construct_left_menu(MainWindow* &) const;
    void construct_right_menu(MainWindow* &) const;
    void construct_upper_level_menu(MainWindow* &) const;

    //Other dependencies
    bool create_logger() const;

signals:
    void window_created();
    void pop_up_created();
    void menu_created();
    void logger_created();

public slots:
    void create_main_window();
    void create_settings_window();
    void create_startup_window();
    void create_info_pop_up();
};

#endif // COMPONENTFACTORY_H
