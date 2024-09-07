#include "Clicker.h"
#include "GraphicalHandler.h"
#include <thread>
#include <iostream>
#include <Windows.h>

HHOOK keyboardHook;

// Function that will be called when a key is pressed
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode == HC_ACTION) 
    {
        KBDLLHOOKSTRUCT* pKeyBoard = (KBDLLHOOKSTRUCT*)lParam;
        
        if (wParam == WM_KEYDOWN && pKeyBoard->vkCode == VK_F7)
            NULL; //graph.DisableClicker();
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void setKeyboardHook() {
    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);
    if (!keyboardHook) 
    {
        throw std::runtime_error("Failed to install hook!");
        return;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) 
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(keyboardHook);
}

int main()
{
    GraphicalHandler graph;
	std::thread hookThread(setKeyboardHook);
    hookThread.detach();

	graph.HandleWindow();

	return 0;
}
