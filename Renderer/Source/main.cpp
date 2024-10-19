#include "App.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "debug\DebugLog.h"

int main()
{
	MP::App app{};
	try 
	{
		app.Run();
	}
	catch (const std::exception& e)
	{
		LOG_ERROR("[ENGINE]::" << e.what());
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}