#include "mainwindow.hpp"
#include <QPushButton>
#include <QVBoxLayout>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->init_upper_level_menu();
    this->init_left_menu();
    this->init_right_menu();
    println("Main window was initialized");
}

MainWindow::~MainWindow()
{
    delete this->upperLevelMenu;
    delete this->leftMenu;
    delete this->rightMenu;
    delete ui;
}

/*
 * Initialize main menu in main window.
 */
void MainWindow::init_upper_level_menu()
{
    println("upper level menu is initialized");
    this->upperLevelMenu = new QWidget();
    QPushButton* run_btn = new QPushButton();
    QPushButton* debug_btn = new QPushButton();
    QHBoxLayout layout;
    layout.addWidget(this->upperLevelMenu);
    layout.addWidget(run_btn);
    layout.addWidget(debug_btn);
    this->upperLevelMenu->show();
}

/*
 * Initialize left menu in main window.
 */
void MainWindow::init_left_menu()
{
    println("left menu is initialized");
    this->leftMenu = new QWidget();
    QPushButton *git_btn = new QPushButton("git");
    QPushButton *todo_btn = new QPushButton("To do");
    QVBoxLayout layout;
    layout.addWidget(git_btn);
    layout.addWidget(todo_btn);
    this->leftMenu->show();
}

/*
 * Initialize right menu in main window.
 */
void MainWindow::init_right_menu()
{
    println("right menu is initialized");
    this->rightMenu = new QWidget();
    QVBoxLayout layout;
    this->rightMenu->show();
}
