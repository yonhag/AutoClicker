#include "WindowsHandler.h"
#include "GraphicalHandler.h"
#include <iostream>

int main()
{
	std::cout << "Sending Clicks!" << std::endl;
	std::cout.flush();

	Settings settings(Button::Right, 1);

	WindowsHandler::SimulateClick(settings);

	return 0;
}