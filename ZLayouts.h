#ifndef Z_LAYOUTS_H
#define Z_LAYOUTS_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>

#include <QWidget>
#include <qqml.h>

class ZVBoxLayout : public QVBoxLayout {
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(ZVBoxLayout)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QWidget* parent READ parentWidget DESIGNABLE false)

public:
    explicit ZVBoxLayout(QWidget* parent = nullptr);

    QQmlListProperty<QObject> data();
};

class ZHBoxLayout : public QHBoxLayout {
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(ZHBoxLayout)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QWidget* parent READ parentWidget DESIGNABLE false)

public:
    explicit ZHBoxLayout(QWidget* parent = nullptr);

    QQmlListProperty<QObject> data();
};

class ZFormLayout : public QFormLayout {
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(ZHBoxLayout)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QWidget* parent READ parentWidget DESIGNABLE false)

public:
    explicit ZFormLayout(QWidget* parent = nullptr);

    QQmlListProperty<QObject> data();
};

#endif
