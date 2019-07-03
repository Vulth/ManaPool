#ifndef MANAPOOL_H
#define MANAPOOL_H

#include <QWidget>

namespace Ui {
class ManaPool;
}

class ManaPool : public QWidget
{
    Q_OBJECT

public:
    explicit ManaPool(QWidget *parent = nullptr);
    ~ManaPool();

private:
    Ui::ManaPool *ui;
};

#endif // MANAPOOL_H
