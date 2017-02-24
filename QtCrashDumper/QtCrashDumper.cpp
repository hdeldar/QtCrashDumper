#include "stdafx.h"
#include "QtCrashDumper.h"

#ifdef USE_MINI_DUMP
//for enable minidump
MiniDumper g_MiniDumper(PRODUCE_NAME, STR_NUM_VERSION, STR_NUM_BUILD);
#endif

QtCrashDumper::QtCrashDumper(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void QtCrashDumper::on_crashBtn_clicked()
{
	//this example of null ptr crash...
	int *ptr = nullptr;
	*ptr = 12;
}
