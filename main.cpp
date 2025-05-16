#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QCoreApplication::setOrganizationName("QtProject"_L1);
    QCoreApplication::setApplicationName("DocumentViewer"_L1);
    QCoreApplication::setApplicationVersion("1.0"_L1);

    QCommandLineParser parser;
    parser.setApplicationDescription(QApplication::translate("main",
                                                     "A viewer for JSON, PDF and text files"));
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("File"_L1, QApplication::translate("main",
                                                                    "JSON, PDF or text file to open"));
    parser.process(app);

    QQmlApplicationEngine engine;
    PageController p_controller;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed, &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("IDE_gui", "Main");

    return app.exec();
}
