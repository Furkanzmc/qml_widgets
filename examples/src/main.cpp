#include <QApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app{argc, argv};

    QDir pluginDir{argv[0]};
    pluginDir.cdUp();
    pluginDir.cdUp();
    pluginDir.cd("qml/");

    QQmlApplicationEngine engine;
    engine.setPluginPathList({pluginDir.absolutePath(), "."});

    qDebug() << "cpp: pluginPathList:" << engine.pluginPathList();

    const QUrl url{"qrc:/qml/main.qml"};

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
