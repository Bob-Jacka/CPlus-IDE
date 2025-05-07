#include <QApplication>
#include "componentfactory.h"
#include "ExternalVariable.h"

int main(int argc, char *argv[])
{
    check_cli_arguments();
    QApplication app(argc, argv);
    cfactory = new ComponentFactory();
    factory->construct_startup_window(startupWindow);
    return app.exec();
}
