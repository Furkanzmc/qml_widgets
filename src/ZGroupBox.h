#ifndef ZGROUP_BOX_H
#define ZGROUP_BOX_H

#include <QGroupBox>
#include <QLayout>
#include <qqml.h>

class ZGroupBox : public QGroupBox {
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "layout")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(GroupBox)

    Q_PROPERTY(
      QLayout* layout READ layout WRITE setLayoutInternal NOTIFY layoutChanged)
    Q_PROPERTY(QObject* parent READ parent WRITE setParentInternal NOTIFY
                 parentChanged DESIGNABLE false)

public:
    explicit ZGroupBox(QWidget* parent = nullptr);

signals:
    void parentChanged(QPrivateSignal);
    void layoutChanged(QPrivateSignal);

private:
    void setParentInternal(QObject* w);
    void setLayoutInternal(QLayout* ly);
};

#endif
