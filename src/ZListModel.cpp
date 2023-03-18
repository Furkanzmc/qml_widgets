#include "ZListModel.h"

ZListModelItem::ZListModelItem(QObject *parent)
    : QObject{parent}
{
}

QString ZListModelItem::text() const
{
    return m_text;
}

void ZListModelItem::setText(const QString &val)
{
    if (m_text == val) {
        return;
    }

    m_text = val;
    emit textChanged(QPrivateSignal{});
}

ZListModel::ZListModel(QObject *parent)
    : QAbstractListModel{parent}
{
}

int ZListModel::rowCount(const QModelIndex &parent) const
{
    return static_cast<int>(m_objects.size());
}

int ZListModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant ZListModel::data(const QModelIndex &index, int role) const
{
    assert(index.isValid());
    assert(index.row() >= 0 && index.row() < m_objects.size());
    return {};
}
