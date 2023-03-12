#ifndef ZINPUT_DIALOG_H
#define ZINPUT_DIALOG_H

#include <QInputDialog>
#include <qqml.h>

class ZInputDialog : public QInputDialog {
    Q_OBJECT

    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(InputDialog)

    Q_PROPERTY(InputMode inputMode READ inputMode WRITE setInputMode NOTIFY
                 inputModeChanged)
    Q_PROPERTY(QString labelText READ labelText WRITE setLabelText NOTIFY
                 labelTextChanged)
    Q_PROPERTY(InputDialogOptions options READ options WRITE setOptions NOTIFY
                 optionsChanged)

    Q_PROPERTY(QLineEdit::EchoMode textEchoMode READ textEchoMode WRITE
                 setTextEchoMode NOTIFY textEchoModeChanged)
    Q_PROPERTY(bool comboBoxEditable READ isComboBoxEditable WRITE
                 setComboBoxEditable NOTIFY comboBoxEditableChanged)
    Q_PROPERTY(QStringList comboBoxItems READ comboBoxItems WRITE
                 setComboBoxItems NOTIFY comboBoxItemsChanged)

    Q_PROPERTY(int intMinimum READ intMinimum WRITE setIntMinimum NOTIFY
                 intMinimumChanged)
    Q_PROPERTY(int intMaximum READ intMaximum WRITE setIntMaximum NOTIFY
                 intMaximumChanged)
    Q_PROPERTY(int intStep READ intStep WRITE setIntStep NOTIFY intStepChanged)

    Q_PROPERTY(double doubleMinimum READ doubleMinimum WRITE setDoubleMinimum
                 NOTIFY doubleMinimumChanged)
    Q_PROPERTY(double doubleMaximum READ doubleMaximum WRITE setDoubleMaximum
                 NOTIFY doubleMaximumChanged)
    Q_PROPERTY(int doubleDecimals READ doubleDecimals WRITE setDoubleDecimals
                 NOTIFY doubleDecimalsChanged)

    Q_PROPERTY(QString okButtonText READ okButtonText WRITE setOkButtonText
                 NOTIFY okButtonTextChanged)
    Q_PROPERTY(QString cancelButtonText READ cancelButtonText WRITE
                 setCancelButtonText NOTIFY cancelButtonTextChanged)
    Q_PROPERTY(double doubleStep READ doubleStep WRITE setDoubleStep NOTIFY
                 doubleStepChanged)

    Q_PROPERTY(QString textValue READ textValue WRITE setTextValue NOTIFY
                 textValueChangedInternal)
    Q_PROPERTY(int intValue READ intValue WRITE setIntValue NOTIFY
                 intValueChangedInternal)
    Q_PROPERTY(double doubleValue READ doubleValue WRITE setDoubleValue NOTIFY
                 doubleValueChangedInternal)

public:
    enum InputModeInternal {
        TextInput = InputMode::TextInput,
        IntInput = InputMode::IntInput,
        DoubleInput = InputMode::DoubleInput
    };

    static_assert(sizeof(InputModeInternal) == sizeof(InputMode), "Wrong.");

    Q_ENUM(InputModeInternal);

public:
    explicit ZInputDialog(QWidget* parent = nullptr);

    void setInputModeInternal(InputMode value);
    void setLabelTextInternal(QString value);
    void setOptionsInternal(InputDialogOptions value);
    void setTextEchoModeInternal(QLineEdit::EchoMode value);
    void setComboBoxEditableInternal(bool value);
    void setComboBoxItemsInternal(QStringList value);
    void setIntMinimumInternal(int value);
    void setIntMaximumInternal(int value);
    void setIntStepInternal(int value);
    void setDoubleMinimumInternal(double value);
    void setDoubleMaximumInternal(double value);
    void setDoubleDecimalsInternal(int value);
    void setOkButtonTextInternal(QString value);
    void setCancelButtonTextInternal(QString value);
    void setDoubleStepInternal(double value);

signals:
    void doubleStepChanged(QPrivateSignal);
    void cancelButtonTextChanged(QPrivateSignal);
    void okButtonTextChanged(QPrivateSignal);
    void doubleDecimalsChanged(QPrivateSignal);
    void doubleMaximumChanged(QPrivateSignal);
    void doubleMinimumChanged(QPrivateSignal);
    void intStepChanged(QPrivateSignal);
    void intMaximumChanged(QPrivateSignal);
    void intMinimumChanged(QPrivateSignal);
    void comboBoxItemsChanged(QPrivateSignal);
    void comboBoxEditableChanged(QPrivateSignal);
    void textEchoModeChanged(QPrivateSignal);
    void optionsChanged(QPrivateSignal);
    void labelTextChanged(QPrivateSignal);
    void inputModeChanged(QPrivateSignal);

    void textValueChangedInternal(const QString& text);
    void intValueChangedInternal(int value);
    void doubleValueChangedInternal(double value);
};

#endif
