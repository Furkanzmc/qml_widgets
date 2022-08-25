#ifndef ZCOMBO_BOX_H
#define ZCOMBO_BOX_H

#include <QComboBox>
#include <qqml.h>

class ZComboBox : public QComboBox {
    Q_OBJECT

    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(ComboBox)

    Q_PROPERTY(QAbstractItemModel* model READ model WRITE setModelInternal
                 NOTIFY modelChanged)

public:
    explicit ZComboBox(QWidget* parent = nullptr);

    void setModelInternal(QAbstractItemModel* md);

signals:
    void modelChanged(QPrivateSignal);
};

#endif
