#include "settingswindow.hpp"
#include <QHBoxLayout>
#include "ExternalVariable.h"

SettingsWindow::SettingsWindow(QWidget *parent): QWidget{parent}
{
    this->splitter = new QSplitter();
    this->apply_btn = new QPushButton();
    this->cancel_btn = new QPushButton();
    this->ok_btn = new QPushButton();
    this->layout = new QHBoxLayout();

    this->layout->addWidget(apply_btn);
    this->layout->addWidget(cancel_btn);
    this->layout->addWidget(ok_btn);
    logger->log_message("Settings created");
}

SettingsWindow::~SettingsWindow()
{
    delete this->apply_btn;
    delete this->ok_btn;
    delete this->cancel_btn;
    delete this->splitter;
    settingsWindow = nullptr;
    logger->log_message("Settings destroyed");
}

SettingsWindow::apply_settings()
{
    logger->log_message("Settings applied");
}

/*
 * Cancels changes in IDE
 */
SettingsWindow::cancel_settings()
{
    logger->log_message("Settings canceled");
}

/*
 * slot for settings change
 */
SettingsWindow::change_settings()
{
    emit settings_changed();
}

/*
 * slot for settings cancel
 */
SettingsWindow::cancel_settings()
{
    emit settings_canceled();
}
