#include "app.h"

namespace mp {

	void App::Run()
	{
		while (!m_Window.ShouldClose())
		{
			glfwPollEvents();
		}
	}
}