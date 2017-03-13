#include "menu.h"
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    //QDir::setCurrent(QCoreApplication::applicationDirPath());
    QApplication a(argc, argv);
    menu m;
    m.show();

    return a.exec();
}
