#include "ZMainWindow.h"

#include <QQmlListProperty>
#include <QLayout>
#include <QMenuBar>

ZMainWindow::ZMainWindow(QWidget* parent)
  : QMainWindow{ parent }
{
}

QQmlListProperty<QObject> ZMainWindow::data()
{
    return QQmlListProperty<QObject>(
      this,
      nullptr,
      // Append
      [](QQmlListProperty<QObject>* prop, QObject* object) -> void {
          assert(prop);
          assert(object);
          auto* window = static_cast<ZMainWindow*>(prop->object);
          assert(window);
          if (!window->centralWidget()) {
              window->setCentralWidget(new QWidget{ window });
          }

          auto* layout{ qobject_cast<QLayout*>(object) };
          if (layout && !window->centralWidget()->layout()) {
              window->centralWidget()->setLayout(layout);
          }
          else if (!object->parent()) {
              object->setParent(window);
          }

          if (auto* menuBar = qobject_cast<QMenuBar*>(object)) {
              window->setMenuBar(menuBar);
          }
      },
      // Count
      [](QQmlListProperty<QObject>* prop) -> qsizetype {
          assert(prop);
          auto* window = static_cast<ZMainWindow*>(prop->object);
          assert(window);
          return window->centralWidget() && window->centralWidget()->layout()
                   ? 1
                   : 0;
      },
      // At
      [](QQmlListProperty<QObject>* prop, qsizetype i) -> QObject* {
          assert(prop);
          auto* window = static_cast<ZMainWindow*>(prop->object);
          assert(window);
          if (!window->centralWidget()) {
              return nullptr;
          }

          if (!window->centralWidget()->layout()) {
              return nullptr;
          }

          return window->centralWidget()->layout()->itemAt(i)->widget();
      },
      // Clear
      [](QQmlListProperty<QObject>* prop) -> void { assert(prop); });
}

void ZMainWindow::setParentInternal(QObject* w)
{
    if (parent() == w) {
        return;
    }

    setParent(qobject_cast<QWidget*>(w));
    emit parentChanged(QPrivateSignal{});
}

int ZMainWindow::width() const
{
    return size().width();
}

void ZMainWindow::setWidth(int value)
{
    auto sz{ size() };
    if (sz.width() == value) {
        return;
    }

    sz.setWidth(value);
    resize(sz);
    emit widthChanged(QPrivateSignal{});
}

int ZMainWindow::height() const
{
    return size().height();
}

void ZMainWindow::setHeight(int value)
{
    auto sz{ size() };
    if (sz.height() == value) {
        return;
    }

    sz.setHeight(value);
    resize(sz);
    emit heightChanged(QPrivateSignal{});
}
