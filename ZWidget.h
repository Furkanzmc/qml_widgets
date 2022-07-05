#ifndef ZWIDGET_H
#define ZWIDGET_H

#include <QWidget>
#include <qqml.h>

class ZWidget : public QWidget {
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(ZWidget)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QObject* parent READ parent WRITE setParentInternal NOTIFY
                 parentChanged DESIGNABLE false)

public:
    explicit ZWidget(QWidget* parent = nullptr);

    QQmlListProperty<QObject> data();

signals:
    void parentChanged(QPrivateSignal);

private:
    void setParentInternal(QObject* w);
};

#endif
