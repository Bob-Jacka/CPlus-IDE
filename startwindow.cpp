#include "startwindow.h"

#include <QVBoxLayout>
#include "ComponentNames.hpp"
#include "ExternalVariable.h"
#include "componentfactory.h"
#include <qpushbutton.h>

void start_main_window();

StartWindow::StartWindow() {
    this->setWindowTitle(WINDOW_NAME);
    this->setMinimumHeight(600);
    this->setMinimumWidth(600);
    this->create_new_proj_btn = new QPushButton(CREATE_PROJ);
    this->open_existing_proj_btn = new QPushButton(OPEN_PROJ);
    this->layout = new QVBoxLayout();

    //Connect button with signals
    connect(create_new_proj_btn, &QPushButton::clicked, create_new_project);
    connect(create_new_proj_btn, &QPushButton::clicked, createMain);

    connect(open_existing_proj_btn, &QPushButton::clicked, ComponentFactory::init_file_explorer());
    connect(open_existing_proj_btn, &QPushButton::clicked, error);

    this->layout->addWidget(create_new_proj_btn);
    this->layout->addWidget(open_existing_proj_btn);

    this->setLayout(layout);
}

StartWindow::~StartWindow() {
    delete this->create_new_proj_btn;
    delete this->open_existing_proj_btn;
    delete this->layout;

    startWindow = nullptr;
    logger->log_message("Start window destroyed.");
}

void create_new_project()
{
    ComponentFactory().construct_new_project_window();
}

//Signals
void StartWindow::createMain()
{
    logger->log_message();
}

void StartWindow::error()
{
    logger->log_error();
}
