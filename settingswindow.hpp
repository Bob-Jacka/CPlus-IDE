#ifndef SETTINGSWINDOW_HPP
#define SETTINGSWINDOW_HPP

#include <QSplitter>
#include <QWidget>

class SettingsWindow : public QWidget
{
    Q_OBJECT

private:
    QSplitter *splitter;

    QPushButon *apply_btn;
    QPushButton *cancel_btn;
    QPushButton *ok_btn;

    QLayout *layout;

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow() {}

    void apply_settings();
    void cancel_settings();
    void close_window();

signals:
    void settings_changed();
    void settings_canceled();

public slots:
    void change_settings();
    void cancel_settings();
};

#endif // SETTINGSWINDOW_HPP
