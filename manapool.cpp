#include "manapool.h"
#include "ui_manapool.h"

ManaPool::ManaPool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManaPool)
{
    ui->setupUi(this);
}

ManaPool::~ManaPool()
{
    delete ui;
}
