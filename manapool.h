#ifndef MANAPOOL_H
#define MANAPOOL_H

#include <QWidget>
#include <QTextStream>

namespace Ui {
class ManaPool;
}

class ManaPool : public QWidget
{
    Q_OBJECT

public:
    explicit ManaPool(QWidget *parent = nullptr);
    ~ManaPool();

private slots:
    void on_startButton_clicked();

private:
    Ui::ManaPool *ui;
};

#endif // MANAPOOL_H
