#include "WindowsHandler.h"
#include "GraphicalHandler.h"
#include <thread>
#include <functional>
#include <iostream>

int main()
{
	GraphicalHandler graph;
	std::thread WindowThread(&GraphicalHandler::HandleWindow, std::ref(graph));

	graph.HandleWindow();

	return 0;
}
