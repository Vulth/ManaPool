#include "manapool.h"
#include "ui_manapool.h"
#include <QLabel>
#include <QDebug>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Card
{
    QString cardname;
    QString manacost;
    QString set; //Which set the card is from
    int setNumber; //Number of the card within the set
    float cmc; //Converted Mana Cost
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
            if (line != "") //Ignore blank lines to get between main deck and sideboard
            {
                QStringList list = line.split(' ');
                QString cardname = list[1];
                QString set = list[list.length() - 2].remove('(');
                set = set.remove(')');

                for (int i = 2; i < list.length() - 2; i++)
                {
                    cardname = cardname + ' ' + list[i];
                }
                cardlist[cardNumber].cardname = cardname;
                for( int i = 0; i < list[0].toInt();i++)
                {
                    cardlist[cardNumber].cardname = cardname;
                    cardlist[cardNumber].set = set;
                    cardlist[cardNumber].setNumber = list[list.length()-1].toInt();
                    cardNumber++;
                }
            }
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
    ui->label->setText(deck.cardlist[1].cardname);
    ui->label_2->setText(deck.cardlist[1].set);
    ui->label_3->setText(QString::number((deck.cardlist[0].setNumber)));
}

//["4",  "Blood",  "Crypt",  "(RNA)",  "245"]
