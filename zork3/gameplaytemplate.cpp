#include "gameplaytemplate.h"

GameplayTemplate::GameplayTemplate(QObject *parent)
    : QAbstractItemModel(parent)
{}

QVariant GameplayTemplate::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex GameplayTemplate::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex GameplayTemplate::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int GameplayTemplate::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int GameplayTemplate::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant GameplayTemplate::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
