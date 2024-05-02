#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

LRESULT CALLBACK Windowproc(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);

const wchar_t CLASS_NAME[] = L"SDVXCHPKclass";

WNDCLASS wc =  { }

wc.lpfnwndproc = Windowproc;
wc.hInstance = hInstance;
wc.lpszClassname = CLASS_NAME;

RegisterClass(&wc);

HWND hwnd = CreateWindowEx(
    //Window Setup

    0,                      //Optional Window Styles
    CLASS_NAME,             //Window Class
    L"SDVX Chart Picker",   //Window Title
    WS_OVERLAPPEDWINDOW,    //Window Style
    //Window Position&Size
    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
    //Extra Window Settings

    NULL,       //Parent Window
    NULL,       //Menu
    hInstance,  //instance handle
    NULL        //Additional Application Data
);

if (hwnd == NULL)
{
    return 0;
}

ShowWindow(hwnd, nCmdShow);

MSG msg = { };
while (GetMessage(&msg, NULL, 0, 0) > 0)
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
