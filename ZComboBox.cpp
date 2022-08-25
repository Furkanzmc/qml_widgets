#include "ZComboBox.h"

ZComboBox::ZComboBox(QWidget* parent)
  : QComboBox{ parent }
{
}

void ZComboBox::setModelInternal(QAbstractItemModel* md)
{
    if (model() == md) {
        return;
    }

    setModel(md);
    emit modelChanged(QPrivateSignal{});
}
