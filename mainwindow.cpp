#include "mainwindow.hpp"
#include "ExternalVariable.h"
#include "UtilFuncs.hpp"
#include "componentfactory.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    this->setWindowTitle("C+ compiler IDE");
    this->resize(1600, 1080);
    this->layout = new QVBoxLayout();

    this->upperLevelMenu = new UpperLevelMenu();
    this->leftMenu = new LeftMenu();
    this->rightMenu = new RightMenu();
    this->splitter = new QSplitter();

    this->layout->addWidget(upperLevelMenu);
    this->layout->addWidget(leftMenu);
    this->layout->addWidget(rightMenu);
    this->layout->addWidget(splitter);

    this->setLayout(layout);
    println("Main window was initialized");
}

MainWindow::~MainWindow()
{
    delete this->upperLevelMenu;
    delete this->leftMenu;
    delete this->rightMenu;
    delete this->splitter;
    // delete ui;
}

void MainWindow::goSettings() const {
    ComponentFactory().construct_settings_window(settingsWindow);
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
