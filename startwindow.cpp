#include "startwindow.h"

#include "componentfactory.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <qpushbutton.h>
#include "ExternalVariable.h"

void start_main_window();
void errorStart();

StartWindow::StartWindow() {
    this->setWindowTitle("Startup menu");
    this->setMinimumHeight(600);
    this->setMinimumWidth(600);
    this->create_new_proj_btn = new QPushButton("Create project");
    this->open_existing_proj_btn = new QPushButton("Open project");
    this->layout = new QVBoxLayout();

    //Connect button with signals
    connect(create_new_proj_btn, &QPushButton::clicked, start_main_window);
    connect(open_existing_proj_btn, &QPushButton::clicked, errorStart);

    this->layout->addWidget(create_new_proj_btn);
    this->layout->addWidget(open_existing_proj_btn);

    this->setLayout(layout);
}

StartWindow::~StartWindow() {
    delete this->create_new_proj_btn;
    delete this->open_existing_proj_btn;
    delete this->layout;
}

void start_main_window() {
    ComponentFactory().construct_main_window(mainWindow);
}

void errorStart()
{
    QMessageBox* msgBox;
    msgBox->setWindowTitle("Error");
    msgBox->setText("Error placeholder");
    msgBox->resize(50, 50);
    msgBox->exec();
}
