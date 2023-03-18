#include <QQmlApplicationEngine>
#include <QtQml/QQmlEngineExtensionPlugin>

#include <QLayout>
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
#include <QTimeEdit>

#include <QStyledItemDelegate>

extern void qml_register_types_Qml_Widgets();
Q_GHS_KEEP_REFERENCE(qml_register_types_Qml_Widgets);

class QmlWidgetsPlugin : public QQmlEngineExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)

public:
    QmlWidgetsPlugin(QObject *parent = nullptr)
        : QQmlEngineExtensionPlugin{parent}
    {
        volatile auto registration = &qml_register_types_Qml_Widgets;
        Q_UNUSED(registration);

        qmlRegisterAnonymousType<QLayout>("Qml.Widgets", 1);
        qmlRegisterType<QAction>("Qml.Widgets", 1, 0, "Action");

        qmlRegisterUncreatableType<QPalette>("Qml.Widgets", 1, 0, "QPalette",
                                             "Cannot create from QML.");

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

        qmlRegisterType<QErrorMessage>("Qml.Widgets", 1, 0, "ErrorMessage");
        qmlRegisterType<QMessageBox>("Qml.Widgets", 1, 0, "MessageBox");
        qmlRegisterType<QColorDialog>("Qml.Widgets", 1, 0, "ColorDialog");
        qmlRegisterType<QFontDialog>("Qml.Widgets", 1, 0, "FontDialog");
        qmlRegisterType<QFileDialog>("Qml.Widgets", 1, 0, "FileDialog");
        qmlRegisterType<QTimeEdit>("Qml.Widgets", 1, 0, "TimeEdit");

        qmlRegisterType<QStyledItemDelegate>("Qml.Widgets", 1, 0, "StyledItemDelegate");
        qmlRegisterAnonymousType<QAbstractItemDelegate>("Qml.Widgets", 1);
    }
};

#include "plugin.moc"
