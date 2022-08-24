#include "ZMenuBar.h"

namespace {
template<class T>
void dataAppend(QQmlListProperty<QObject>* prop, QObject* object)
{
    if constexpr (std::is_same_v<T, ZMenuBar>) {
        auto* menuBar{ qobject_cast<ZMenuBar*>(prop->object) };
        assert(menuBar);

        auto* menu{ qobject_cast<ZMenu*>(object) };
        assert(menu);
        menuBar->addMenu(menu);
    }
    else {
        auto* menu{ qobject_cast<ZMenu*>(prop->object) };
        assert(menu);

        auto* subMenu{ qobject_cast<ZMenu*>(object) };
        if (subMenu) {
            menu->addMenu(subMenu);
        }
        else {
            assert(qobject_cast<QAction*>(object));
            menu->addAction(qobject_cast<QAction*>(object));
        }
    }
}

template<class T>
qsizetype dataCount(QQmlListProperty<QObject>* prop)
{
    assert(prop);

    if constexpr (std::is_same_v<T, ZMenuBar>) {
        auto* menuBar{ qobject_cast<ZMenuBar*>(prop->object) };
        assert(menuBar);

        return menuBar->actions().size();
    }
    else {
        auto* menu{ qobject_cast<ZMenu*>(prop->object) };
        assert(menu);

        return menu->actions().size();
    }
}

template<class T>
QObject* dataAt(QQmlListProperty<QObject>* prop, qsizetype i)
{
    assert(prop);

    if constexpr (std::is_same_v<T, ZMenuBar>) {
        auto* menuBar{ qobject_cast<ZMenuBar*>(prop->object) };
        assert(menuBar);

        auto* action = menuBar->actions().at(i);
        assert(action);

        return action->menu();
    }
    else {
        auto* menu{ qobject_cast<ZMenu*>(prop->object) };
        assert(menu);

        auto* action = menu->actions().at(i);
        assert(action);

        if (action->menu()) {
            return action->menu();
        }

        return action;
    }
}

template<class T>
void dataClear(QQmlListProperty<QObject>* prop)
{
    assert(prop);

    if constexpr (std::is_same_v<T, ZMenuBar>) {
        auto* menuBar{ qobject_cast<ZMenuBar*>(prop->object) };
        assert(menuBar);
        menuBar->clear();
    }
    else {
        auto* menu{ qobject_cast<ZMenu*>(prop->object) };
        assert(menu);
        menu->clear();
    }
}
}

ZMenuBar::ZMenuBar(QWidget* parent)
  : QMenuBar{ parent }
{
}

QQmlListProperty<QObject> ZMenuBar::data()
{
    return QQmlListProperty<QObject>(this,
                                     nullptr,
                                     dataAppend<ZMenuBar>,
                                     dataCount<ZMenuBar>,
                                     dataAt<ZMenuBar>,
                                     dataClear<ZMenuBar>);
}

ZMenu::ZMenu(QWidget* parent)
  : QMenu{ parent }
{
}

QQmlListProperty<QObject> ZMenu::data()
{
    return QQmlListProperty<QObject>(this,
                                     nullptr,
                                     dataAppend<ZMenu>,
                                     dataCount<ZMenu>,
                                     dataAt<ZMenu>,
                                     dataClear<ZMenu>);
}
