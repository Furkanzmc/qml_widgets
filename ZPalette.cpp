#include <ZPalette.h>

#include <QWidget>

#include <QDebug>

ZPaletteAttached::ZPaletteAttached(QObject *parent) : QObject{parent} {
  assert(qobject_cast<QWidget *>(parent));
}

ZPaletteAttached *ZPaletteAttached::qmlAttachedProperties(QObject *object) {
  return new ZPaletteAttached{object};
}

QQmlListProperty<QObject> ZPaletteAttached::items() {
  return QQmlListProperty<QObject>(
      this, nullptr,
      [](QQmlListProperty<QObject> *prop, QObject *object) {
        auto *palette{static_cast<ZPaletteAttached *>(prop->object)};
        assert(palette);

        auto *item{qobject_cast<ZPaletteItem *>(object)};
        assert(item);
        item->setParent(palette);
        palette->m_items.push_back(item);
        palette->m_palette.setBrush(item->group(), item->role(),
                                    QBrush{QColor::fromString(item->color())});
        qobject_cast<QWidget *>(palette->parent())
            ->setPalette(palette->palette());
      },
      [](QQmlListProperty<QObject> *prop) -> qsizetype {
        auto *palette{static_cast<ZPaletteAttached *>(prop->object)};
        assert(palette);
        return palette->m_items.size();
      },
      [](QQmlListProperty<QObject> *prop, qsizetype i) -> QObject * {
        auto *palette{static_cast<ZPaletteAttached *>(prop->object)};
        assert(palette);
        assert(i > 0 && i < palette->m_items.size());
        return palette->m_items.at(i);
      },
      [](QQmlListProperty<QObject> *prop) {
        auto *palette{static_cast<ZPaletteAttached *>(prop->object)};
        assert(palette);
        auto &items = palette->m_items;
        std::for_each(items.begin(), items.end(),
                      [](auto *item) { item->deleteLater(); });
        items.clear();
      });
}

ZPaletteAttached *ZPaletteAttached::extends() const { return m_extends; }

void ZPaletteAttached::setExtends(ZPaletteAttached *ext) {
  if (m_extends == ext) {
    return;
  }

  m_extends = ext;
  emit extendsChanged(QPrivateSignal{});
}

const QPalette &ZPaletteAttached::palette() const { return m_palette; }

ZPaletteItem::ZPaletteItem(QObject *parent) : QObject{parent} {}

QString ZPaletteItem::color() const { return m_color; }

void ZPaletteItem::setColor(const QString &cl) {
  if (m_color == cl) {
    return;
  }

  m_color = cl;
  emit colorChanged(QPrivateSignal{});
}

QPalette::ColorGroup ZPaletteItem::group() const { return m_group; }

void ZPaletteItem::setGroup(QPalette::ColorGroup gr) {
  if (m_group == gr) {
    return;
  }

  m_group = gr;
  emit groupChanged(QPrivateSignal{});
}

QPalette::ColorRole ZPaletteItem::role() const { return m_role; }

void ZPaletteItem::setRole(QPalette::ColorRole rl) {
  if (m_role == rl) {
    return;
  }

  m_role = rl;
  emit roleChanged(QPrivateSignal{});
}
