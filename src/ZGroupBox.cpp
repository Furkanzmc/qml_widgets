#include "ZGroupBox.h"

#include <QLayout>
#include <QQmlListProperty>

ZGroupBox::ZGroupBox(QWidget *parent)
    : QGroupBox{parent}
{
}

void ZGroupBox::setLayoutInternal(QObject *wgt)
{
    if (layout() == wgt) {
        return;
    }

    auto *lyt = [wgt]() -> QLayout * {
        if (auto *lyt = qobject_cast<QLayout *>(wgt)) {
            return lyt;
        }

        if (auto *frame = qobject_cast<QFrame *>(wgt)) {
            return frame->layout();
        }

        return nullptr;
    }();

    assert(lyt);
    setLayout(lyt);
    emit layoutChanged(QPrivateSignal{});
}

void ZGroupBox::setParentInternal(QObject *w)
{
    if (parent() == w) {
        return;
    }

    setParent(qobject_cast<QWidget *>(w));
    emit parentChanged(QPrivateSignal{});
}
