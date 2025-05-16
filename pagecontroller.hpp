#ifndef PAGECONTROLLER_HPP
#define PAGECONTROLLER_HPP

#define LOADER_ID "pageLoader"
#define LOADER_PROPERTY "source"

class PageController : public QObject
{
    QML_ELEMENT

public:
    PageController(QQmlApplicationEngine *engine, QObject *parent = nullptr)
        : QObject(parent)
        , m_engine(engine);
    ~PageController();

public slots:
    void goToPage(const QString &page)
    {
        m_engine->rootObjects().first()->findChild<QObject *>(LOADER_ID)->setProperty(LOADER_PROPERTY,
                                                                                      page);
        //Add logger dependencie to log page
    }

private:
    QQmlApplicationEngine *m_engine;
};

#endif // PAGECONTROLLER_HPP
