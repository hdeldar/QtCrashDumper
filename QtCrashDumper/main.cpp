#include "stdafx.h"
#include "QtCrashDumper.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtCrashDumper w;
    w.show();
    return a.exec();
}
