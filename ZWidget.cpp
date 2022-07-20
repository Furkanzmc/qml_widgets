#include "ZWidget.h"

#include <QQmlListProperty>
#include <QLayout>

ZWidget::ZWidget(QWidget* parent)
  : QWidget{ parent }
{
}

QQmlListProperty<QObject> ZWidget::data()
{
    return QQmlListProperty<QObject>(
      this,
      nullptr,
      // Append
      [](QQmlListProperty<QObject>* prop, QObject* object) -> void {
          assert(prop);
          assert(object);
          auto* parent = static_cast<ZWidget*>(prop->object);
          assert(parent);
          assert(!qobject_cast<ZWidget*>(object));
          auto* layout{ qobject_cast<QLayout*>(object) };
          if (layout && !parent->layout()) {
              parent->setLayout(layout);
          }
      },
      // Count
      [](QQmlListProperty<QObject>* prop) -> qsizetype {
          assert(prop);
          auto* parent = static_cast<ZWidget*>(prop->object);
          assert(parent);
          return parent->layout() ? 1 : 0;
      },
      // At
      [](QQmlListProperty<QObject>* prop, qsizetype i) -> QObject* {
          assert(prop);
          auto* parent = static_cast<ZWidget*>(prop->object);
          assert(parent);
          if (!parent->layout()) {
              return nullptr;
          }

          return parent->layout()->itemAt(i)->widget();
      },
      // Clear
      [](QQmlListProperty<QObject>* prop) -> void { assert(prop); });
}

void ZWidget::setParentInternal(QObject* w)
{
    if (parent() == w) {
        return;
    }

    setParent(qobject_cast<QWidget*>(w));
    emit parentChanged(QPrivateSignal{});
}

int ZWidget::width() const
{
    return size().width();
}

void ZWidget::setWidth(int value)
{
    auto sz{ size() };
    if (sz.width() == value) {
        return;
    }

    sz.setWidth(value);
    resize(sz);
    emit widthChanged(QPrivateSignal{});
}

int ZWidget::height() const
{
    return size().height();
}

void ZWidget::setHeight(int value)
{
    auto sz{ size() };
    if (sz.height() == value) {
        return;
    }

    sz.setHeight(value);
    resize(sz);
    emit heightChanged(QPrivateSignal{});
}
