#include "Clicker.h"
#include <Windows.h>
#include <thread>
#include <chrono>

enum ClickActions { ButtonDown, ButtonUp };

void Clicker::Click(Settings& settings)
{
    std::chrono::milliseconds delay(1000 / settings._cps);

    if (settings._button == MouseButton::Left)
    {
        while (settings._activated)
        {
            LeftClick();
            std::this_thread::sleep_for(delay);
        }
    }
    else
    {
        while (settings._activated)
        {
            RightClick();
            std::this_thread::sleep_for(delay);
        }
    }
}

void Clicker::LeftClick()
{
    INPUT inputs[ACTIONS_PER_CLICK] = { 0 };

    inputs[ButtonDown].type = INPUT_MOUSE;
    inputs[ButtonDown].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    inputs[ButtonUp].type = INPUT_MOUSE;
    inputs[ButtonUp].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    SendInput(2, inputs, sizeof(INPUT));
}

void Clicker::RightClick()
{
    INPUT inputs[ACTIONS_PER_CLICK] = { 0 };

    inputs[ButtonDown].type = INPUT_MOUSE;
    inputs[ButtonDown].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;

    inputs[ButtonUp].type = INPUT_MOUSE;
    inputs[ButtonUp].mi.dwFlags = MOUSEEVENTF_RIGHTUP;

    SendInput(2, inputs, sizeof(INPUT));
}
