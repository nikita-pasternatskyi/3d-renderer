#pragma once

#include "Window\MPWindow.h"

namespace MP {
	class App {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 800;

		void Run();

	private:
		MPWindow m_Window{WIDTH, HEIGHT, "Vulkan!"};
	};
}