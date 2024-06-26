#include "WindowsHandler.h"
#include "GraphicalHandler.h"
#include <iostream>

int main()
{
	std::cout << "Sending Clicks!" << std::endl;
	std::cout.flush();

	for (int i = 0; i < 500; i++) 
	{
		WindowsHandler::SimulateLeftMouseClick();
	}
	return 0;
}