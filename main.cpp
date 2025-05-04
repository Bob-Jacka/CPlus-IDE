#include <QApplication>
#include "componentfactory.h"
#include "ExternalVariable.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ComponentFactory *factory = new ComponentFactory();
    factory->construct_startup_window(startupWindow);
    return app.exec();
}
