#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QWidget* upperLevelMenu;
    QWidget* leftMenu;
    QWidget* rightMenu;

    void positionate_upper_level_menu();
    void positionate_left_menu();
    void positionate_right_menu();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void goSettings();

    void view_help_menu();

    void hide_left_menu();  //hides left menu in main window of ide
    void hide_right_menu(); //hides right menu in main window of ide

    void init_upper_level_menu(); //initializing process for upper level menu
    void init_left_menu();        //initializing process for left menu
    void init_right_menu();       //initializing process for right menu

private:
    Ui::MainWindow *ui;

signals:
    //
};
#endif // MAINWINDOW_H
