#ifndef Z_LAYOUTS_H
#define Z_LAYOUTS_H

#include <QFormLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QStackedLayout>
#include <QStackedWidget>
#include <QToolBox>
#include <QVBoxLayout>

#include <QWidget>
#include <qqml.h>

class ZVBoxLayout : public QVBoxLayout
{
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(VBoxLayout)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QWidget *parent READ parentWidget DESIGNABLE false)

public:
    explicit ZVBoxLayout(QWidget *parent = nullptr);

    QQmlListProperty<QObject> data();
};

class ZHBoxLayout : public QHBoxLayout
{
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(HBoxLayout)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QWidget *parent READ parentWidget DESIGNABLE false)

public:
    explicit ZHBoxLayout(QWidget *parent = nullptr);

    QQmlListProperty<QObject> data();
};

class ZFormLayout : public QFormLayout
{
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(FormLayout)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QWidget *parent READ parentWidget DESIGNABLE false)

public:
    explicit ZFormLayout(QWidget *parent = nullptr);

    QQmlListProperty<QObject> data();
};

class ZGridLayout : public QGridLayout
{
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(GridLayout)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QWidget *parent READ parentWidget DESIGNABLE false)

public:
    explicit ZGridLayout(QWidget *parent = nullptr);

    QQmlListProperty<QObject> data();
};

class ZStackedLayout : public QStackedLayout
{
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(StackedLayout)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QWidget *parent READ parentWidget DESIGNABLE false)

public:
    explicit ZStackedLayout(QWidget *parent = nullptr);

    QQmlListProperty<QObject> data();
};

class ZStackedWidget : public QStackedWidget
{
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(StackLayout)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QWidget *parent READ parentWidget DESIGNABLE false)

public:
    explicit ZStackedWidget(QWidget *parent = nullptr);

    QQmlListProperty<QObject> data();
};

class ZToolBox : public QToolBox
{
    Q_OBJECT

    Q_CLASSINFO("DefaultProperty", "data")
    Q_CLASSINFO("ParentProperty", "parent")
    QML_NAMED_ELEMENT(ToolBox)

    Q_PROPERTY(QQmlListProperty<QObject> data READ data DESIGNABLE false)
    Q_PROPERTY(QWidget *parent READ parentWidget DESIGNABLE false)

public:
    explicit ZToolBox(QWidget *parent = nullptr);

    QQmlListProperty<QObject> data();
};

class ZLayoutAttached : public QObject
{
    Q_OBJECT

    QML_NAMED_ELEMENT(Layout)
    QML_UNCREATABLE("Do not create objects of type Layout.")

    Q_PROPERTY(int row READ row WRITE setRow NOTIFY rowChanged)
    Q_PROPERTY(int column READ column WRITE setColumn NOTIFY columnChanged)
    Q_PROPERTY(int rowSpan READ rowSpan WRITE setRowSpan NOTIFY rowSpanChanged)
    Q_PROPERTY(
        int columnSpan READ columnSpan WRITE setColumnSpan NOTIFY columnSpanChanged)

    Q_PROPERTY(
        Qt::Alignment alignment READ alignment WRITE setAlignment NOTIFY alignmentChanged)

    Q_PROPERTY(qreal margins READ margins WRITE setMargins NOTIFY marginsChanged)

    Q_PROPERTY(qreal leftMargin READ leftMargin WRITE setLeftMargin RESET resetLeftMargin
                   NOTIFY leftMarginChanged)
    Q_PROPERTY(qreal topMargin READ topMargin WRITE setTopMargin RESET resetTopMargin
                   NOTIFY topMarginChanged)
    Q_PROPERTY(qreal rightMargin READ rightMargin WRITE setRightMargin RESET
                   resetRightMargin NOTIFY rightMarginChanged)
    Q_PROPERTY(qreal bottomMargin READ bottomMargin WRITE setBottomMargin RESET
                   resetBottomMargin NOTIFY bottomMarginChanged)

    // Only used with ZFormLayout
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)

    // Alias to label so we can use it for ZToolBox
    Q_PROPERTY(QString title READ label WRITE setLabel NOTIFY labelChanged)

public:
    ZLayoutAttached(QObject *parent);

    static ZLayoutAttached *qmlAttachedProperties(QObject *object);

    int row() const;
    void setRow(int value);

    int column() const;
    void setColumn(int value);

    int rowSpan() const;
    void setRowSpan(int value);

    int columnSpan() const;
    void setColumnSpan(int value);

    Qt::Alignment alignment() const;
    void setAlignment(Qt::Alignment value);

    qreal margins() const;
    void setMargins(qreal value);

    qreal leftMargin() const;
    void setLeftMargin(qreal value);
    void resetLeftMargin();

    qreal topMargin() const;
    void setTopMargin(qreal value);
    void resetTopMargin();

    qreal rightMargin() const;
    void setRightMargin(qreal value);
    void resetRightMargin();

    qreal bottomMargin() const;
    void setBottomMargin(qreal value);
    void resetBottomMargin();

    QString label() const;
    void setLabel(const QString &lb);

signals:
    void rowChanged(QPrivateSignal);
    void columnChanged(QPrivateSignal);
    void rowSpanChanged(QPrivateSignal);
    void columnSpanChanged(QPrivateSignal);
    void alignmentChanged(QPrivateSignal);
    void marginsChanged(QPrivateSignal);
    void leftMarginChanged(QPrivateSignal);
    void topMarginChanged(QPrivateSignal);
    void rightMarginChanged(QPrivateSignal);
    void bottomMarginChanged(QPrivateSignal);
    void labelChanged(QPrivateSignal);

private:
    int m_row{};
    int m_column{};
    int m_rowSpan{1};
    int m_columnSpan{1};
    Qt::Alignment m_alignment{};
    qreal m_margins{};
    qreal m_leftMargin{};
    qreal m_topMargin{};
    qreal m_rightMargin{};
    qreal m_bottomMargin{};
    QString m_label{};
};

class ZSpacerItem : public QObject, public QSpacerItem
{

    Q_OBJECT
    QML_NAMED_ELEMENT(Spacer)

    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)

    Q_PROPERTY(QSizePolicy::Policy horizontalSizePolicy READ horizontalSizePolicy WRITE
                   setHorizontalSizePolicy NOTIFY horizontalSizePolicyChanged)
    Q_PROPERTY(QSizePolicy::Policy verticalSizePolicy READ verticalSizePolicy WRITE
                   setVerticalSizePolicy NOTIFY verticalSizePolicyChanged)

    Q_PROPERTY(
        QRect geometry READ geometry WRITE setGeometryInternal NOTIFY geometryChanged)

    Q_PROPERTY(Qt::Orientations expandingDirections READ expandingDirections NOTIFY
                   expandingDirectionsChanged)

    Q_PROPERTY(QSize minimumSize READ minimumSize NOTIFY minimumSizeChanged)
    Q_PROPERTY(QSize maximumSize READ maximumSize NOTIFY maximumSizeChanged)

    Q_PROPERTY(bool empty READ isEmpty CONSTANT)

public:
    explicit ZSpacerItem(QObject *parent = nullptr);

    int width() const;
    void setWidth(int value);

    int height() const;
    void setHeight(int value);

    QSizePolicy::Policy horizontalSizePolicy() const;
    void setHorizontalSizePolicy(QSizePolicy::Policy policy);

    QSizePolicy::Policy verticalSizePolicy() const;
    void setVerticalSizePolicy(QSizePolicy::Policy policy);

    void setGeometryInternal(const QRect &value);

signals:
    void widthChanged(QPrivateSignal);
    void heightChanged(QPrivateSignal);
    void horizontalSizePolicyChanged(QPrivateSignal);
    void verticalSizePolicyChanged(QPrivateSignal);
    void geometryChanged(QPrivateSignal);
    void expandingDirectionsChanged(QPrivateSignal);
    void minimumSizeChanged(QPrivateSignal);
    void maximumSizeChanged(QPrivateSignal);
};

QML_DECLARE_TYPEINFO(ZLayoutAttached, QML_HAS_ATTACHED_PROPERTIES);

#endif
