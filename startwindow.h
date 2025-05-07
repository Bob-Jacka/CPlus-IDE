#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QObject>
#include <qpushbutton.h>

class StartWindow : public QWidget
{
    Q_OBJECT

private:
    QPushButton* create_new_proj_btn; //button for creating main window.
    QPushButton* open_existing_proj_btn; //button that opens file explorer to open existing project
    QLayout* layout; //layout of the window

public:
    StartWindow();
    ~StartWindow();

signals:
    void createMain();
    void error();
};

#endif // STARTWINDOW_H
