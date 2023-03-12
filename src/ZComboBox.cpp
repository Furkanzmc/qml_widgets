#include "ZComboBox.h"

ZComboBox::ZComboBox(QWidget *parent) : QComboBox{parent} {}

void ZComboBox::setModel(QAbstractItemModel *md) {
  if (model() == md) {
    return;
  }

  QComboBox::setModel(md);
  emit modelChanged(QPrivateSignal{});
}

void ZComboBox::setItemDelegateInternal(QAbstractItemDelegate *dlg) {
  if (itemDelegate() == dlg) {
    return;
  }

  setItemDelegate(dlg);
  emit itemDelegateChanged(QPrivateSignal{});
}
