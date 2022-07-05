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
      [](QQmlListProperty<QObject>* prop, QObject* o) -> void {
          auto* parent = static_cast<ZWidget*>(prop->object);
          assert(parent);
          assert(!qobject_cast<ZWidget*>(o));
          auto* layout{ qobject_cast<QLayout*>(o) };
          if (layout && !parent->layout()) {
              parent->setLayout(layout);
          }
      },
      [](QQmlListProperty<QObject>* prop) -> qsizetype {
          auto* parent = static_cast<ZWidget*>(prop->object);
          assert(parent);
          return parent->layout() ? 1 : 0;
      },
      [](QQmlListProperty<QObject>* prop, qsizetype i) -> QObject* {
          auto* parent = static_cast<ZWidget*>(prop->object);
          assert(parent);
          if (!parent->layout()) {
              return nullptr;
          }

          return parent->layout()->itemAt(i)->widget();
      },
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
