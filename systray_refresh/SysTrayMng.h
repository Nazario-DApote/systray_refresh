#pragma once

class SysTrayMng
{
private:
	static HWND g_hToobarTray;
	static BOOL CALLBACK EnumChildProc( HWND hwnd, LPARAM lParam  );

public:
	SysTrayMng(void);
	~SysTrayMng(void);
	void Refresh(void);
};

