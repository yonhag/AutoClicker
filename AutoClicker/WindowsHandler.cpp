#include "WindowsHandler.h"
#include <Windows.h>

void WindowsHandler::SimulateMouseClick()
{
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
