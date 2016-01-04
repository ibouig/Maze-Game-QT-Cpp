/*#include "window.h"
#include <QApplication>
#include"prim.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    window w(hard);
    w.show();


    return a.exec();
}
*/
#include<QApplication>
#include"fenetre.h"

int main(int argc, char *argv[])
{
QApplication app(argc, argv);

fenetre fen(380,526);
QGuiApplication::setQuitOnLastWindowClosed(true);
fen.show();
return app.exec();
}
