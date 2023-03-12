#ifndef ZCOMBO_BOX_H
#define ZCOMBO_BOX_H

#include <QComboBox>
#include <qqml.h>

class ZComboBox : public QComboBox {
  Q_OBJECT

  Q_CLASSINFO("ParentProperty", "parent")
  QML_NAMED_ELEMENT(ComboBox)

  Q_PROPERTY(
      QAbstractItemModel *model READ model WRITE setModel NOTIFY modelChanged)

  Q_PROPERTY(QAbstractItemDelegate *itemDelegate READ itemDelegate WRITE
                 setItemDelegateInternal NOTIFY itemDelegateChanged)

public:
  explicit ZComboBox(QWidget *parent = nullptr);

  void setModel(QAbstractItemModel *md) final;

  void setItemDelegateInternal(QAbstractItemDelegate *dlg);

signals:
  void modelChanged(QPrivateSignal);
  void itemDelegateChanged(QPrivateSignal);
};

#endif
