#include "regexptest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    regexptest w;
    w.show();

    return a.exec();
}
