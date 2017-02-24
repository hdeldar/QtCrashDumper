#include <QtWidgets>

#define PRODUCE_NAME		L"QtCrashDumper"
#define STR_NUM_VERSION		L"1.0.0"
#define STR_NUM_BUILD		L"0004"

#define USE_MINI_DUMP
#ifdef USE_MINI_DUMP
#include "mdump.h"
extern MiniDumper g_MiniDumper;
#endif
