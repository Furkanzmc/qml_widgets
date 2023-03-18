#ifndef ZMENU_BAR_H
#define ZMENU_BAR_H

#include <QMenu>
#include <QMenuBar>
#include <QQmlListProperty>
#include <qqml.h>

class ZMenuBar : public QMenuBar
{
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(MenuBar)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QWidget *parent READ parentWidget DESIGNABLE false)

public:
    explicit ZMenuBar(QWidget *parent = nullptr);

    QQmlListProperty<QObject> data();
};

class ZMenu : public QMenu
{
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(Menu)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QWidget *parent READ parentWidget DESIGNABLE false)

public:
    explicit ZMenu(QWidget *parent = nullptr);

    QQmlListProperty<QObject> data();
};

#endif
