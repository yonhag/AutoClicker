#pragma once
#include "Settings.h"
#include <memory>

class Clicker
{
public:
	static void Click(Settings& settings);

private:
	static void LeftClick();
	static void RightClick();

	static const unsigned int ACTIONS_PER_CLICK = 2;
};
