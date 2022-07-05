#include "ZLayouts.h"

#include <QLayoutItem>
#include <QWidget>

namespace {
template<class Layout>
void dataAppend(QQmlListProperty<QObject>* prop, QObject* o)
{
    auto* layout{ static_cast<Layout*>(prop->object) };
    assert(layout);
    if (layout->parent() && !layout->parentWidget()) {
        if (qobject_cast<QWidget*>(layout->parent())) {
            qobject_cast<QWidget*>(layout->parent())->setLayout(layout);
        }
    }

    auto* widget{ qobject_cast<QWidget*>(o) };
    if (widget) {
        if constexpr (std::is_same_v<Layout, QFormLayout>) {
            layout->addRow(widget);
        }
        else {
            layout->addWidget(widget);
        }
    }
    else {
        auto* childLayout{ qobject_cast<QLayout*>(o) };
        if constexpr (!std::is_same_v<Layout, QFormLayout>) {
            layout->addLayout(childLayout);
        }
        else if constexpr (std::is_same_v<Layout, QFormLayout>) {
            layout->addRow(childLayout);
        }
    }
}

template<class Layout>
qsizetype dataCount(QQmlListProperty<QObject>* prop)
{
    auto* layout{ static_cast<Layout*>(prop->object) };
    assert(layout);
    return layout->count();
}

template<class Layout>
QObject* dataAt(QQmlListProperty<QObject>* prop, qsizetype i)
{
    auto* layout{ static_cast<Layout*>(prop->object) };
    assert(layout);
    return layout->itemAt(i)->widget();
}

template<class Layout>
void dataClear(QQmlListProperty<QObject>* prop)
{
    auto* layout{ static_cast<Layout*>(prop->object) };
    assert(layout);
    // TODO: Clear...
}
}

ZVBoxLayout::ZVBoxLayout(QWidget* parent)
  : QVBoxLayout{ parent }
{
}

QQmlListProperty<QObject> ZVBoxLayout::data()
{
    return QQmlListProperty<QObject>(this,
                                     nullptr,
                                     dataAppend<ZVBoxLayout>,
                                     dataCount<ZVBoxLayout>,
                                     dataAt<ZVBoxLayout>,
                                     dataClear<ZVBoxLayout>);
}

ZHBoxLayout::ZHBoxLayout(QWidget* parent)
  : QHBoxLayout{ parent }
{
}

QQmlListProperty<QObject> ZHBoxLayout::data()
{
    return QQmlListProperty<QObject>(this,
                                     nullptr,
                                     dataAppend<ZVBoxLayout>,
                                     dataCount<ZVBoxLayout>,
                                     dataAt<ZVBoxLayout>,
                                     dataClear<ZVBoxLayout>);
}

ZFormLayout::ZFormLayout(QWidget* parent)
  : QFormLayout{ parent }
{
}

QQmlListProperty<QObject> ZFormLayout::data()
{
    return QQmlListProperty<QObject>(this,
                                     nullptr,
                                     dataAppend<QFormLayout>,
                                     dataCount<QFormLayout>,
                                     dataAt<QFormLayout>,
                                     dataClear<QFormLayout>);
}
