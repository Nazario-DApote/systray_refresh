#include "StdAfx.h"
#include "SysTrayMng.h"

HWND SysTrayMng::g_hToobarTray = 0; // static initialization

SysTrayMng::SysTrayMng(void)
{
}

SysTrayMng::~SysTrayMng(void)
{
}

BOOL CALLBACK SysTrayMng::EnumChildProc( HWND hwnd, LPARAM lParam  )
{
	// Unicode version doesn't work here!! 

	CHAR szClass[MAX_PATH];

	int res = ::GetClassNameA(hwnd, szClass, sizeof(szClass));

	if ( strcmp(szClass, "ToolbarWindow32") == 0 )
	{
		g_hToobarTray = hwnd;
		return FALSE;
	}
	return TRUE;
}

void SysTrayMng::Refresh(void)
{
	HWND hTray = ::FindWindow( L"Shell_TrayWnd",0);
	if ( hTray )
	{
		::EnumChildWindows (hTray, EnumChildProc, 0); 
		if ( g_hToobarTray )
		{
			RECT rc;
			::GetClientRect (g_hToobarTray, &rc); 
			for (int i=1; i< rc.right; i++) 
			{
				::SendMessage (g_hToobarTray, WM_MOUSEMOVE, 0, MAKELONG(1,i)); 
				::InvalidateRect(g_hToobarTray, NULL, TRUE);
			}
		}
	}

}
