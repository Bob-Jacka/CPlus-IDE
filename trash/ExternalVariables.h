#ifndef EXTERNALVARIABLE_H
#define EXTERNALVARIABLE_H

#include "componentfactory.h"
#include "logger.hpp"
#include "mainwindow.hpp"
#include "settingswindow.hpp"
#include "startwindow.h"

//Window entities
static MainWindow* mainWindow; //main window entitie
static SettingsWindow* settingsWindow; //settings window entitie
static StartWindow* startupWindow;

static Logger *logger; //global instance of logger entitie

//Factory entities
static ComponentFactory *cfactory; //component factory entitie

#endif // EXTERNALVARIABLE_H
