#include "mainwindow.hpp"
#include <QVBoxLayout>
#include "ComponentNames.hpp"
#include "ExternalVariable.h"
#include "UtilFuncs.hpp"
#include "componentfactory.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    this->setWindowTitle(IDE_TITLE);
    this->resize(IDE_WIDTH, IDE_HEIGHT);
    this->layout = new QVBoxLayout();

    this->upperLevelMenu = new UpperLevelMenu();
    this->leftMenu = new LeftMenu();
    this->rightMenu = new RightMenu();
    this->splitter = new QSplitter();

    this->mainLayout->addWidget(upperLevelMenu);
    this->mainLayout->addWidget(leftMenu);
    this->mainLayout->addWidget(rightMenu);
    this->mainLayout->addWidget(splitter);

    this->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete this->upperLevelMenu;
    delete this->leftMenu;
    delete this->rightMenu;
    delete this->splitter;

    mainWindow = nullptr;
    logger->log_message("Main window destroyed");
}

void MainWindow::goSettings() const {
    cfactory->construct_settings_window(settingsWindow);
}

void MainWindow::view_help_menu() const
{
    cfactory->construct_pop_up("Help menu", "IDE version is " + ide_version);
}

void MainWindow::hide_left_menu() const {
    this->leftMenu->hide();
}

void MainWindow::hide_right_menu() const {
    this->rightMenu->hide();
}

void MainWindow::hide_upper_menu() const {
    this->upperLevelMenu->hide();
}

//Setters
void MainWindow::setLeftMenu(LeftMenu* another)
{
    this->leftMenu = another;
}

void MainWindow::setRightMenu(RightMenu* another)
{
    this->rightMenu = another;
}

void MainWindow::setUpperLevelMenu(UpperLevelMenu* another)
{
    this->upperLevelMenu = another;
}

//Getters
QWidget* MainWindow::getLeftMenu() const {
    return this->leftMenu;
}

QWidget* MainWindow::getRightMenu() const {
    return this->rightMenu;
}

QWidget* MainWindow::getUpperLevelMenu() const {
    return this->upperLevelMenu;
}
