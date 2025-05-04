#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include "mainwindow.hpp"
#include "settingswindow.hpp"
#include "startwindow.h"

#include <QObject>

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

    //Menus constructs
    void construct_left_menu(MainWindow* &) const;
    void construct_right_menu(MainWindow* &) const;
    void construct_upper_level_menu(MainWindow* &) const;

signals:
    void window_created();
    void pop_up_created();
    void menu_created();

public slots:
    void create_main_window();
    void create_settings_window();
    void create_startup_window();
    void create_info_pop_up();
};

#endif // COMPONENTFACTORY_H
