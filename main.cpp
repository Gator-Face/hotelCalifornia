#include "reservation_form.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Reservation_Form w;
    w.show();
    return a.exec();
}
