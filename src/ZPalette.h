#ifndef Z_PALETTE
#define Z_PALETTE

#include <QObject>
#include <QPalette>
#include <qqml.h>

class ZPaletteItem;

class ZPaletteAttached : public QObject
{
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "items")
    QML_NAMED_ELEMENT(Palette)

    Q_PROPERTY(QQmlListProperty<QObject> items READ items DESIGNABLE false)

    Q_PROPERTY(
        ZPaletteAttached *extends READ extends WRITE setExtends NOTIFY extendsChanged)

public:
    explicit ZPaletteAttached(QObject *parent = nullptr);

    static ZPaletteAttached *qmlAttachedProperties(QObject *object);

    QQmlListProperty<QObject> items();

    ZPaletteAttached *extends() const;
    void setExtends(ZPaletteAttached *ext);

    [[nodiscard]] const QPalette &palette() const;

signals:
    void extendsChanged(QPrivateSignal);

private:
    QPalette m_palette{};
    std::vector<ZPaletteItem *> m_items;
    ZPaletteAttached *m_extends{nullptr};
};

class ZPaletteItem : public QObject
{
    Q_OBJECT
    QML_NAMED_ELEMENT(PaletteItem)

    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)

    Q_PROPERTY(QPalette::ColorGroup group READ group WRITE setGroup NOTIFY groupChanged)

    Q_PROPERTY(QPalette::ColorRole role READ role WRITE setRole NOTIFY roleChanged)

public:
    explicit ZPaletteItem(QObject *parent = nullptr);

    QString color() const;
    void setColor(const QString &cl);

    QPalette::ColorGroup group() const;
    void setGroup(QPalette::ColorGroup gr);

    QPalette::ColorRole role() const;
    void setRole(QPalette::ColorRole rl);

private:
    QString m_color{};
    QPalette::ColorGroup m_group{};
    QPalette::ColorRole m_role{};

signals:
    void colorChanged(QPrivateSignal);
    void groupChanged(QPrivateSignal);
    void roleChanged(QPrivateSignal);
};

QML_DECLARE_TYPEINFO(ZPaletteAttached, QML_HAS_ATTACHED_PROPERTIES);

#endif
