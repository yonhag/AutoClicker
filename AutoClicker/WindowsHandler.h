#pragma once
#include "Settings.h"

class WindowsHandler
{
public:
	static void SimulateClick(const Settings& settings);
private:
	static void SimulateLeftClick();
	static void SimulateRightClick();
};
