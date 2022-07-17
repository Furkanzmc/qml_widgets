#include "ZWidget.h"
#include "ZLayouts.h"
#include "ZGroupBox.h"

#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>

#include <QLabel>
#include <QPushButton>
#include <QErrorMessage>
#include <QMessageBox>
#include <QColorDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QTextEdit>
#include <QLineEdit>

int main(int argc, char* argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl url(
      "/Users/furkanzmc/Development/playground/qml_widget/main.qml");

    qmlRegisterAnonymousType<QLayout>("Qml.Widgets", 1);
    qmlRegisterType<ZWidget>("Qml.Widgets", 1, 0, "Widget");

    // Layouts
    qmlRegisterType<ZVBoxLayout>("Qml.Widgets", 1, 0, "VBoxLayout");
    qmlRegisterType<ZHBoxLayout>("Qml.Widgets", 1, 0, "HBoxLayout");
    qmlRegisterType<ZFormLayout>("Qml.Widgets", 1, 0, "FormLayout");
    qmlRegisterType<ZGroupBox>("Qml.Widgets", 1, 0, "GroupBox");
    qmlRegisterType<ZGridLayout>("Qml.Widgets", 1, 0, "GridLayout");
    qmlRegisterType<ZLayoutAttached>("Qml.Widgets", 1, 0, "Layout");

    qmlRegisterType<QLabel>("Qml.Widgets", 1, 0, "Label");
    qmlRegisterType<QPushButton>("Qml.Widgets", 1, 0, "PushButton");
    qmlRegisterType<QErrorMessage>("Qml.Widgets", 1, 0, "ErrorMessage");
    qmlRegisterType<QMessageBox>("Qml.Widgets", 1, 0, "MessageBox");
    qmlRegisterType<QColorDialog>("Qml.Widgets", 1, 0, "ColorDialog");
    qmlRegisterType<QCheckBox>("Qml.Widgets", 1, 0, "CheckBox");
    qmlRegisterType<QRadioButton>("Qml.Widgets", 1, 0, "RadioButton");
    qmlRegisterType<QTextEdit>("Qml.Widgets", 1, 0, "TextEdit");
    qmlRegisterType<QLineEdit>("Qml.Widgets", 1, 0, "LineEdit");

    QObject::connect(
      &engine,
      &QQmlApplicationEngine::objectCreated,
      &app,
      [url](QObject* obj, const QUrl& objUrl) {
          if (!obj && url == objUrl)
              QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
