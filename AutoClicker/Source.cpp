#include "GraphicalHandler.h"
#include "WindowsHandler.h"

int main()
{
	WindowsHandler handler;
	while (true)
	{
		handler.SimulateMouseClick();
	}
}