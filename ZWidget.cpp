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
          auto* parent = static_cast<ZWidget*>(prop->object);
          assert(parent);
          assert(!qobject_cast<ZWidget*>(o));
          auto* layout{ qobject_cast<QLayout*>(o) };
          if (layout && !parent->layout()) {
              parent->setLayout(layout);
          }
      },
      // Count
      [](QQmlListProperty<QObject>* prop) -> qsizetype {
          auto* parent = static_cast<ZWidget*>(prop->object);
          assert(parent);
          return parent->layout() ? 1 : 0;
      },
      // At
      [](QQmlListProperty<QObject>* prop, qsizetype i) -> QObject* {
          auto* parent = static_cast<ZWidget*>(prop->object);
          assert(parent);
          if (!parent->layout()) {
              return nullptr;
          }

          return parent->layout()->itemAt(i)->widget();
      },
      // Clear
      [](QQmlListProperty<QObject>* prop) -> void {});
}

void ZWidget::setParentInternal(QObject* w)
{
    if (parent() == w) {
        return;
    }

    setParent(qobject_cast<QWidget*>(w));
    emit parentChanged(QPrivateSignal{});
}
