#include "ZGroupBox.h"

#include <QQmlListProperty>
#include <QLayout>

ZGroupBox::ZGroupBox(QWidget* parent)
  : QGroupBox{ parent }
{
}

void ZGroupBox::setLayoutInternal(QLayout* ly)
{
    if (layout() == ly) {
        return;
    }

    setLayout(ly);
    emit layoutChanged(QPrivateSignal{});
}

void ZGroupBox::setParentInternal(QObject* w)
{
    if (parent() == w) {
        return;
    }

    setParent(qobject_cast<QWidget*>(w));
    emit parentChanged(QPrivateSignal{});
}
