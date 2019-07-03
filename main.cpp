#include "manapool.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ManaPool w;
    w.show();

    return a.exec();
}
