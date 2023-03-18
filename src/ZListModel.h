#ifndef ZLIST_MODEL_H
#define ZLIST_MODEL_H

#include <QAbstractItemModel>

#include <vector>

class ZListModelItem : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
    explicit ZListModelItem(QObject *parent = nullptr);

    QString text() const;
    void setText(const QString &val);

private:
    QString m_text{};

signals:
    void textChanged(QPrivateSignal);
};

class ZListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ZListModel(QObject *parent = nullptr);

    Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex{}) const final;
    Q_INVOKABLE int columnCount(const QModelIndex &parent = QModelIndex{}) const final;

    Q_INVOKABLE QVariant data(const QModelIndex &index,
                              int role = Qt::DisplayRole) const final;

private:
    std::vector<ZListModelItem> m_objects;
};

#endif
