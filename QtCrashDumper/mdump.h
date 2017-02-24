#if !defined(AFX_MDUMP_H__FCECFEFE6E_FA36_4693_B07C_F8JHT75BB0101B__INCLUDED_)
#define AFX_MDUMP_H__FCECFEFE6E_FA36_4693_B07C_F8JHT75BB0101B__INCLUDED_
#ifdef USE_MINI_DUMP

/**
 * Date: 24st February 2017
 * Modified by Hassan - hassan_Deldar@yahoo.com
 */

/** -------------- How to debug ----------------
1. save pdb file when you compile
2. get dmp file when crash
3. put exe & pdb & dmp file together
4. open dmp file with vs2013, press f5 to run, then you can see the result
*/

#if _MSC_VER < 1300
#define DECLSPEC_DEPRECATED
// VC6: change this path to your Platform SDK headers
//#include "C:\\Program Files\\Microsoft Visual Studio 8\\VC\\PlatformSDK\\Include\\dbghelp.h"			// must be XP version of file
#include "dbghelp.h"			// must be XP version of file
#else
// VC7: ships with updated headers
#include "dbghelp.h"
#endif

// based on dbghelp.h
typedef BOOL (WINAPI *MINIDUMPWRITEDUMP)(HANDLE hProcess, DWORD dwPid, HANDLE hFile, MINIDUMP_TYPE DumpType,
									CONST PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam,
									CONST PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam,
									CONST PMINIDUMP_CALLBACK_INFORMATION CallbackParam
									);

#define MAX_WARNING_MESSAGE_PATH 1024

class MiniDumper
{
private:
	static LPCWSTR m_szAppName;

	static LPWSTR m_szAppVersion;

	static LPWSTR m_szAppBuildNumber;

	static WCHAR m_szMessageText[MAX_WARNING_MESSAGE_PATH];

	static LPWSTR m_szDumpFilePath;	
	
	static LONG WINAPI TopLevelFilter( struct _EXCEPTION_POINTERS *pExceptionInfo );

public:
	MiniDumper( LPCWSTR szAppName ,LPCWSTR szVersion,LPCWSTR szBuildNumber = NULL);
	~MiniDumper();
	static void SetVersion(LPCWSTR szVersion);
	static void SetBuildNumber(LPCWSTR szBuildNumber);
	static void SetDumpFilePath(LPCWSTR szFilePath);
	static int SetWarningMessage(LPCWSTR szMessageText)
	{
		if(szMessageText)
		{
			int iLen = wcslen(szMessageText);
			if(iLen < MAX_WARNING_MESSAGE_PATH - MAX_PATH)
			{
				wcscpy(m_szMessageText,szMessageText);
				return 0;
			}			
		}
		return 1;
	}
};
#endif
#endif