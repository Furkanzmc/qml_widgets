#ifndef ZMAIN_WINDOW_H
#define ZMAIN_WINDOW_H

#include <QMainWindow>
#include <qqml.h>

class ZMainWindow : public QMainWindow
{
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(MainWindow)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QObject *parent READ parent WRITE setParentInternal NOTIFY parentChanged
                   DESIGNABLE false)
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)

public:
    explicit ZMainWindow(QWidget *parent = nullptr);

    QQmlListProperty<QObject> data();

    int width() const;
    void setWidth(int value);

    int height() const;
    void setHeight(int value);

signals:
    void parentChanged(QPrivateSignal);
    void widthChanged(QPrivateSignal);
    void heightChanged(QPrivateSignal);

private:
    void setParentInternal(QObject *w);
};

#endif
