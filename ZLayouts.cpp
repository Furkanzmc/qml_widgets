#include "ZLayouts.h"

#include <QLayoutItem>
#include <QWidget>

namespace {
template<class Layout>
void dataAppend(QQmlListProperty<QObject>* prop, QObject* o)
{
    auto* layout{ static_cast<Layout*>(prop->object) };
    assert(layout);
    if (layout->count() == 0) {
        // NOTE: If there's a parent and the parent was not passed in in the
        // ctor, widget creation fails and a warning log is out put from
        // QLayout::parentWidget()
        layout->setParent(nullptr);
    }

    auto* widget{ qobject_cast<QWidget*>(o) };
    if (widget) {
        if constexpr (std::is_same_v<Layout, ZFormLayout>) {
            layout->addRow(widget);
        }
        else if constexpr (std::is_same_v<Layout, ZGridLayout>) {
            auto layoutAtt = qobject_cast<ZLayoutAttached*>(
              qmlAttachedPropertiesObject<ZLayoutAttached>(widget, false));
            assert(layoutAtt);
            layout->addWidget(widget, layoutAtt->row(), layoutAtt->column());
        }
        else {
            layout->addWidget(widget);
        }
    }
    else {
        auto* childLayout{ qobject_cast<QLayout*>(o) };
        if constexpr (std::is_same_v<Layout, ZGridLayout>) {
            auto layoutAtt = qobject_cast<ZLayoutAttached*>(
              qmlAttachedPropertiesObject<ZLayoutAttached>(widget, false));
            assert(layoutAtt);
            layout->addLayout(
              childLayout, layoutAtt->row(), layoutAtt->column());
        }
        else if constexpr (std::is_same_v<Layout, ZFormLayout>) {
            layout->addRow(childLayout);
        }
        else if constexpr (!std::is_same_v<Layout, ZStackedLayout> &&
                           !std::is_same_v<Layout, ZStackedWidget>) {
            layout->addLayout(childLayout);
        }
        else {
            assert(false);
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
    if constexpr (std::is_same_v<Layout, ZStackedWidget>) {
        return layout->widget(i);
    }
    else {
        return layout->itemAt(i)->widget();
    }
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
                                     dataAppend<ZFormLayout>,
                                     dataCount<ZFormLayout>,
                                     dataAt<ZFormLayout>,
                                     dataClear<ZFormLayout>);
}

ZGridLayout::ZGridLayout(QWidget* parent)
  : QGridLayout{ parent }
{
}

QQmlListProperty<QObject> ZGridLayout::data()
{
    return QQmlListProperty<QObject>(this,
                                     nullptr,
                                     dataAppend<ZGridLayout>,
                                     dataCount<ZGridLayout>,
                                     dataAt<ZGridLayout>,
                                     dataClear<ZGridLayout>);
}

ZStackedLayout::ZStackedLayout(QWidget* parent)
  : QStackedLayout{ parent }
{
}

QQmlListProperty<QObject> ZStackedLayout::data()
{
    return QQmlListProperty<QObject>(this,
                                     nullptr,
                                     dataAppend<ZStackedLayout>,
                                     dataCount<ZStackedLayout>,
                                     dataAt<ZStackedLayout>,
                                     dataClear<ZStackedLayout>);
}

ZStackedWidget::ZStackedWidget(QWidget* parent)
  : QStackedWidget{ parent }
{
}

QQmlListProperty<QObject> ZStackedWidget::data()
{
    return QQmlListProperty<QObject>(this,
                                     nullptr,
                                     dataAppend<ZStackedWidget>,
                                     dataCount<ZStackedWidget>,
                                     dataAt<ZStackedWidget>,
                                     dataClear<ZStackedWidget>);
}

ZLayoutAttached::ZLayoutAttached(QObject* parent)
  : QObject{ parent }
{
}

ZLayoutAttached* ZLayoutAttached::qmlAttachedProperties(QObject* object)
{
    return new ZLayoutAttached(object);
}

int ZLayoutAttached::row() const
{
    return m_row;
}

void ZLayoutAttached::setRow(int value)
{
    if (m_row == value) {
        return;
    }

    m_row = value;
    emit rowChanged(QPrivateSignal{});
}

int ZLayoutAttached::column() const
{
    return m_column;
}

void ZLayoutAttached::setColumn(int value)
{
    if (m_column == value) {
        return;
    }

    m_column = value;
    emit columnChanged(QPrivateSignal{});
}

int ZLayoutAttached::rowSpan() const
{
    return m_rowSpan;
}
void ZLayoutAttached::setRowSpan(int value)
{
    if (m_rowSpan == value) {
        return;
    }

    m_rowSpan = value;
    emit rowSpanChanged(QPrivateSignal{});
}

int ZLayoutAttached::columnSpan() const
{
    return m_columnSpan;
}

void ZLayoutAttached::setColumnSpan(int value)
{
    if (m_columnSpan == value) {
        return;
    }

    m_columnSpan = value;
    emit columnSpanChanged(QPrivateSignal{});
}

Qt::Alignment ZLayoutAttached::alignment() const
{
    return m_alignment;
}

void ZLayoutAttached::setAlignment(Qt::Alignment value)
{
    if (m_alignment == value) {
        return;
    }

    m_alignment = value;
    emit alignmentChanged(QPrivateSignal{});
}

qreal ZLayoutAttached::margins() const
{
    return m_margins;
}

void ZLayoutAttached::setMargins(qreal value)
{
    if (m_margins == value) {
        return;
    }

    m_margins = value;
    emit marginsChanged(QPrivateSignal{});
}

qreal ZLayoutAttached::leftMargin() const
{
    return m_leftMargin;
}

void ZLayoutAttached::setLeftMargin(qreal value)
{
    if (m_leftMargin == value) {
        return;
    }
    m_leftMargin = value;
    emit leftMarginChanged(QPrivateSignal{});
}

void ZLayoutAttached::resetLeftMargin()
{
    setLeftMargin(0);
}

qreal ZLayoutAttached::topMargin() const
{
    return m_topMargin;
}
void ZLayoutAttached::setTopMargin(qreal value)
{
    if (m_topMargin == value) {
        return;
    }

    m_topMargin = value;
    emit topMarginChanged(QPrivateSignal{});
}

void ZLayoutAttached::resetTopMargin()
{
    setTopMargin(0);
}

qreal ZLayoutAttached::rightMargin() const
{
    return m_rightMargin;
}

void ZLayoutAttached::setRightMargin(qreal value)
{
    if (m_rightMargin == value) {
        return;
    }

    m_rightMargin = value;
    emit rightMarginChanged(QPrivateSignal{});
}

void ZLayoutAttached::resetRightMargin()
{
    setRightMargin(0);
}

qreal ZLayoutAttached::bottomMargin() const
{
    return m_bottomMargin;
}

void ZLayoutAttached::setBottomMargin(qreal value)
{
    if (m_bottomMargin == value) {
        return;
    }

    m_bottomMargin = value;
    emit bottomMarginChanged(QPrivateSignal{});
}

void ZLayoutAttached::resetBottomMargin()
{
    setBottomMargin(0);
}
