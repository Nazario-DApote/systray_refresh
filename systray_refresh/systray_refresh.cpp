// systray_refresh.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <exception>      // std::exception
#include "SysTrayMng.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		wprintf_s(L"Refreshing the System Tray bar ... ");
		SysTrayMng sr;
		sr.Refresh();
		wprintf_s(L"done!");
	}
	catch (exception& e)
	{
		wprintf_s(L"Error: %s", e.what());
		return -1;
	}

	return 0;
}

