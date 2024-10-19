#include "App.h"

namespace MP {

	void App::Run()
	{
		while (!m_Window.ShouldClose())
		{
			glfwPollEvents();
		}
	}
}