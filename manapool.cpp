#include "manapool.h"
#include "ui_manapool.h"
#include <QLabel>

struct Card
{
    QString cardname;
    QString manacost;
    float cmc;
};

class Deck
{
    public:
    Card cardlist[75];

    void fillCardlist(QString decklist)
    {
        int cardNumber = 0;
        QTextStream stream(&decklist);
        while(!stream.atEnd())
        {
            QString line = stream.readLine();
            cardlist[cardNumber].cardname = line;
            cardNumber++;
        }
    }

};

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
    Deck deck;
    deck.fillCardlist(decklist);
    ui->label->setText(deck.cardlist[5].cardname);
}
