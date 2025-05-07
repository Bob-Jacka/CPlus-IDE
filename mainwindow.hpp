#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QPushButton>
#include <QVBoxLayout>
#include <qsplitter.h>

/*
 * Struct that represents upper menu in ide.
 */
struct UpperLevelMenu : QMenu {
    Q_OBJECT

private:
    QPushButton* run_btn;
    QPushButton* debug_btn;
    QLayout* layout;

public:
    UpperLevelMenu() {
        debug_btn = new QPushButton("debug");
        run_btn = new QPushButton("run");
        layout = new QHBoxLayout();

        layout->addWidget(debug_btn);
        layout->addWidget(run_btn);

        this->setLayout(layout);
        this->show();
    }

    ~UpperLevelMenu() {
        delete this->debug_btn;
        delete this->run_btn;
        delete this->layout;
    }
};

struct LeftMenu : QWidget {
    Q_OBJECT

public:

    LeftMenu() {
        this->setWindowTitle("Left menu");
        this->show();
    }

    ~LeftMenu() {
        //
    }
};

struct RightMenu : QWidget {
    Q_OBJECT

private:
    QPushButton *buildSystem;

public:
    RightMenu() {
        this->setWindowTitle(RIGHT_MENU_TITLE);
        this->buildSystem = new QPushButton();
        this->show();
    }

    ~RightMenu() {
        //
    }
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QMenu* upperLevelMenu;
    LeftMenu* leftMenu;
    RightMenu* rightMenu;
    QSplitter* splitter;

    QLayout *mainLayout; //elements layout of main window.

    Ui::MainWindow *ui;

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void goSettings() const;

    QWidget* getUpperLevelMenu() const;
    QWidget* getLeftMenu() const;
    QWidget* getRightMenu() const;

    void view_help_menu() const;

    void setUpperLevelMenu(UpperLevelMenu*);
    void setLeftMenu(LeftMenu*);
    void setRightMenu(RightMenu*);

    void hide_upper_menu() const;
    void hide_left_menu() const;  //hides left menu in main window of ide
    void hide_right_menu() const; //hides right menu in main window of ide

signals:
    //
};

#endif // MAINWINDOW_H
