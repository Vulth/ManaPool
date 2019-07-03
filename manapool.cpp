#include "manapool.h"
#include "ui_manapool.h"
#include <QLabel>

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

void ManaPool::on_startButton_clicked()
{
    QString decklist = ui->textEdit->toPlainText();
    QTextStream stream(&decklist);
    QString line = stream.readLine();
    ui->label->setText(line);

}
