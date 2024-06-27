#include "WindowsHandler.h"
#include <Windows.h>
#include <thread>
#include <chrono>

void WindowsHandler::SimulateClick(const Settings& settings)
{
    std::chrono::milliseconds delay(1000 / settings._cps);

    if (settings._button == MouseButton::Left)
    {
        while (true)
        {
            SimulateLeftClick();
            std::this_thread::sleep_for(delay);
        }
    }
    else
    {
        while (true)
        {
            SimulateRightClick();
            std::this_thread::sleep_for(delay);
        }
    }
}

void WindowsHandler::SimulateLeftClick()
{
    INPUT inputs[2] = { 0 };

    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    SendInput(2, inputs, sizeof(INPUT));
}

void WindowsHandler::SimulateRightClick()
{
    INPUT inputs[2] = { 0 };

    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;

    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;

    SendInput(2, inputs, sizeof(INPUT));
}
