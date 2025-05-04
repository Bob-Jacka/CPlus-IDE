#ifndef SETTINGSWINDOW_HPP
#define SETTINGSWINDOW_HPP

#include <QWidget>

class SettingsWindow : public QWidget
{
    Q_OBJECT
private:
    //
public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow() {};

    void apply_settings();
    void close_window();
signals:
    //
};

#endif // SETTINGSWINDOW_HPP
