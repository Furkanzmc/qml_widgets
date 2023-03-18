#include "ZInputDialog.h"

ZInputDialog::ZInputDialog(QWidget *parent)
    : QInputDialog{parent}
{
    connect(this, &ZInputDialog::textValueChanged, this,
            &ZInputDialog::textValueChangedInternal);
    connect(this, &ZInputDialog::intValueChanged, this,
            &ZInputDialog::intValueChangedInternal);
    connect(this, &ZInputDialog::doubleValueChanged, this,
            &ZInputDialog::doubleValueChangedInternal);
}

void ZInputDialog::setInputModeInternal(InputMode value)
{
    if (value == inputMode()) {
        return;
    }

    setInputMode(value);
    emit inputModeChanged(QPrivateSignal{});
}

void ZInputDialog::setLabelTextInternal(QString value)
{
    if (value == labelText()) {
        return;
    }

    setLabelText(value);
    emit labelTextChanged(QPrivateSignal{});
}

void ZInputDialog::setOptionsInternal(InputDialogOptions value)
{
    if (value == options()) {
        return;
    }

    setOptions(value);
    emit optionsChanged(QPrivateSignal{});
}

void ZInputDialog::setTextEchoModeInternal(QLineEdit::EchoMode value)
{
    if (value == textEchoMode()) {
        return;
    }

    setTextEchoMode(value);
    emit textEchoModeChanged(QPrivateSignal{});
}

void ZInputDialog::setComboBoxEditableInternal(bool value)
{
    if (value == isComboBoxEditable()) {
        return;
    }

    setComboBoxEditable(value);
    emit comboBoxEditableChanged(QPrivateSignal{});
}

void ZInputDialog::setComboBoxItemsInternal(QStringList value)
{
    if (value == comboBoxItems()) {
        return;
    }

    setComboBoxItems(value);
    emit comboBoxItemsChanged(QPrivateSignal{});
}

void ZInputDialog::setIntMinimumInternal(int value)
{
    if (value == intMinimum()) {
        return;
    }

    setIntMinimum(value);
    emit intMinimumChanged(QPrivateSignal{});
}

void ZInputDialog::setIntMaximumInternal(int value)
{
    if (value == intMaximum()) {
        return;
    }

    setIntMaximum(value);
    emit intMaximumChanged(QPrivateSignal{});
}

void ZInputDialog::setIntStepInternal(int value)
{
    if (value == intStep()) {
        return;
    }

    setIntStep(value);
    emit intStepChanged(QPrivateSignal{});
}

void ZInputDialog::setDoubleMinimumInternal(double value)
{
    if (value == doubleMinimum()) {
        return;
    }

    setDoubleMinimum(value);
    emit doubleMinimumChanged(QPrivateSignal{});
}

void ZInputDialog::setDoubleMaximumInternal(double value)
{
    if (value == doubleMaximum()) {
        return;
    }

    setDoubleMaximum(value);
    emit doubleMaximumChanged(QPrivateSignal{});
}

void ZInputDialog::setDoubleDecimalsInternal(int value)
{
    if (value == doubleDecimals()) {
        return;
    }

    setDoubleDecimals(value);
    emit doubleDecimalsChanged(QPrivateSignal{});
}

void ZInputDialog::setOkButtonTextInternal(QString value)
{
    if (value == okButtonText()) {
        return;
    }

    setOkButtonText(value);
    emit okButtonTextChanged(QPrivateSignal{});
}

void ZInputDialog::setCancelButtonTextInternal(QString value)
{
    if (value == cancelButtonText()) {
        return;
    }

    setCancelButtonText(value);
    emit cancelButtonTextChanged(QPrivateSignal{});
}

void ZInputDialog::setDoubleStepInternal(double value)
{
    if (value == doubleStep()) {
        return;
    }

    setDoubleStep(value);
    emit doubleStepChanged(QPrivateSignal{});
}
