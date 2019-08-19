#include<Windows.h>
#include<iostream>
#include<conio.h>

/*
typedef void(*pfn_hookstart)();
typedef void(*pfn_hookstop)();

int main() {
	HMODULE hModule = ::LoadLibraryW(L"sdwspyplusdll.dll");
	pfn_hookstart hookstart = NULL;
	pfn_hookstop hookstop = NULL;

	if (hModule == NULL) {
		std::wcout << "Load Library Fail" << std::endl;
	}

	hookstart = (pfn_hookstart)::GetProcAddress(hModule, "hookstart");
	hookstop = (pfn_hookstop)::GetProcAddress(hModule, "hookstop");

	hookstart();
	std::cout << "hook start\n\n" << std::endl;

	std::cout << "press q to exit\n" << std::endl;
	while (_getch() != 'q');

	hookstop();
	std::cout << "hook stop" << std::endl;

	FreeLibrary(hModule);

	return 0;
}
*/

POINT ptMouse;

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam) {
	wchar_t buff[255];
	
	if (IsWindowVisible(hWnd)) {
		GetClassNameW(hWnd, (LPWSTR)buff, ARRAYSIZE(buff));
		std::wcout << buff << std::endl;
	}
	/*
	if (IsWindowVisible(hWnd)) {
		GetWindowTextW(hWnd, (LPWSTR)buff, 254);
		std::wcout << buff << std::endl;
	}
	*/

	return TRUE;
}

int main() {
	
	std::wcout << "press q to start" << std::endl;
	while (_getch() != 'q');

	HWND sdwHwnd/*,sdwPHwnd,sdwFHwnd*/ = NULL;

	GetCursorPos(&ptMouse);
	sdwHwnd = WindowFromPoint(ptMouse);
	sdwHwnd = GetAncestor(sdwHwnd,GA_ROOTOWNER);
	/*
	sdwPHwnd = GetParent(sdwHwnd);

	while (sdwPHwnd != NULL) {
		sdwFHwnd = sdwPHwnd;
		sdwPHwnd = GetParent(sdwPHwnd);
		if (sdwPHwnd == NULL)
			break;
	}*/
	EnumChildWindows(sdwHwnd, EnumWindowsProc, NULL);
	
	std::wcout << "press q to exit" << std::endl;
	while (_getch() != 'q');

	return 0;
}