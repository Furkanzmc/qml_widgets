#include "ZComboBox.h"
#include "ZGroupBox.h"
#include "ZInputDialog.h"
#include "ZLayouts.h"
#include "ZMainWindow.h"
#include "ZMenuBar.h"
#include "ZPalette.h"
#include "ZWidget.h"

#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QAction>
#include <QCheckBox>
#include <QColorDialog>
#include <QCommandLinkButton>
#include <QDateEdit>
#include <QDateTimeEdit>
#include <QDial>
#include <QDoubleSpinBox>
#include <QErrorMessage>
#include <QFileDialog>
#include <QFontComboBox>
#include <QFontDialog>
#include <QKeySequenceEdit>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QSlider>
#include <QSpinBox>
#include <QTextEdit>
#include <QToolButton>

#include <QStyledItemDelegate>

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

  QApplication app(argc, argv);

  QQmlApplicationEngine engine;

  const QUrl url{"/Users/furkanzmc/Development/github/qml_widgets/qml/main.qml"};

  qmlRegisterAnonymousType<QLayout>("Qml.Widgets", 1);
  qmlRegisterType<ZWidget>("Qml.Widgets", 1, 0, "Widget");
  qmlRegisterType<QAction>("Qml.Widgets", 1, 0, "Action");

  // Layouts
  qmlRegisterType<ZVBoxLayout>("Qml.Widgets", 1, 0, "VBoxLayout");
  qmlRegisterType<ZHBoxLayout>("Qml.Widgets", 1, 0, "HBoxLayout");
  qmlRegisterType<ZFormLayout>("Qml.Widgets", 1, 0, "FormLayout");
  qmlRegisterType<ZGroupBox>("Qml.Widgets", 1, 0, "GroupBox");
  qmlRegisterType<ZGridLayout>("Qml.Widgets", 1, 0, "GridLayout");
  qmlRegisterType<ZStackedLayout>("Qml.Widgets", 1, 0, "StackLayout");
  qmlRegisterType<ZStackedWidget>("Qml.Widgets", 1, 0, "StackWidget");
  qmlRegisterUncreatableType<ZLayoutAttached>("Qml.Widgets", 1, 0, "Layout",
                                              "Cannot create from QML.");
  qmlRegisterType<ZSpacerItem>("Qml.Widgets", 1, 0, "Spacer");
  qmlRegisterUncreatableType<ZPaletteAttached>("Qml.Widgets", 1, 0, "Palette",
                                               "Cannot create from QML.");
  qmlRegisterType<ZPaletteItem>("Qml.Widgets", 1, 0, "PaletteItem");
  qmlRegisterUncreatableType<QPalette>("Qml.Widgets", 1, 0, "QPalette",
                                       "Cannot create from QML.");

  qmlRegisterType<ZMenuBar>("Qml.Widgets", 1, 0, "MenuBar");
  qmlRegisterType<ZMenu>("Qml.Widgets", 1, 0, "Menu");
  qmlRegisterType<ZToolBox>("Qml.Widgets", 1, 0, "ToolBox");
  qmlRegisterType<ZComboBox>("Qml.Widgets", 1, 0, "ComboBox");
  qmlRegisterType<ZInputDialog>("Qml.Widgets.Dialogs", 1, 0, "InputDialog");
  qmlRegisterType<ZMainWindow>("Qml.Widgets.Window", 1, 0, "MainWindow");

  // Straight Ports
  qmlRegisterUncreatableType<QSizePolicy>("Qml.Widgets", 1, 0, "SizePolicy",
                                          "Cannot create from QML.");

  qmlRegisterType<QLabel>("Qml.Widgets", 1, 0, "Label");
  qmlRegisterType<QPushButton>("Qml.Widgets", 1, 0, "PushButton");
  qmlRegisterType<QCheckBox>("Qml.Widgets", 1, 0, "CheckBox");
  qmlRegisterType<QRadioButton>("Qml.Widgets", 1, 0, "RadioButton");
  qmlRegisterType<QTextEdit>("Qml.Widgets", 1, 0, "TextEdit");
  qmlRegisterType<QLineEdit>("Qml.Widgets", 1, 0, "LineEdit");
  qmlRegisterType<QToolButton>("Qml.Widgets", 1, 0, "ToolButton");
  qmlRegisterType<QPlainTextEdit>("Qml.Widgets", 1, 0, "PlainTextEdit");
  qmlRegisterType<QSpinBox>("Qml.Widgets", 1, 0, "SpinBox");
  qmlRegisterType<QSlider>("Qml.Widgets", 1, 0, "Slider");
  qmlRegisterType<QProgressBar>("Qml.Widgets", 1, 0, "ProgressBar");
  qmlRegisterType<QKeySequenceEdit>("Qml.Widgets", 1, 0, "KeySequenceEdit");
  qmlRegisterType<QCommandLinkButton>("Qml.Widgets", 1, 0, "CommandLinkButton");
  qmlRegisterType<QDial>("Qml.Widgets", 1, 0, "Dial");
  qmlRegisterType<QDateEdit>("Qml.Widgets", 1, 0, "DateEdit");
  qmlRegisterType<QDateTimeEdit>("Qml.Widgets", 1, 0, "DateTimeEdit");
  qmlRegisterType<QDateTimeEdit>("Qml.Widgets", 1, 0, "DateTimeEdit");
  qmlRegisterType<QFontComboBox>("Qml.Widgets", 1, 0, "FontComboBox");
  qmlRegisterType<QDoubleSpinBox>("Qml.Widgets", 1, 0, "DoubleSpinBox");

  qmlRegisterType<QErrorMessage>("Qml.Widgets.Dialogs", 1, 0, "ErrorMessage");
  qmlRegisterType<QMessageBox>("Qml.Widgets.Dialogs", 1, 0, "MessageBox");
  qmlRegisterType<QColorDialog>("Qml.Widgets.Dialogs", 1, 0, "ColorDialog");
  qmlRegisterType<QFontDialog>("Qml.Widgets.Dialogs", 1, 0, "FontDialog");
  qmlRegisterType<QFileDialog>("Qml.Widgets.Dialogs", 1, 0, "FileDialog");

  qmlRegisterType<QStyledItemDelegate>("Qml.Widgets", 1, 0,
                                       "StyledItemDelegate");
  qmlRegisterAnonymousType<QAbstractItemDelegate>("Qml.Widgets", 1);

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
