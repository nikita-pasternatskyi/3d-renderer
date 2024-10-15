#pragma once

#include "window\mp_window.hpp"

namespace mp {
	class App {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 800;

		void Run();

	private:
		MPWindow m_Window{WIDTH, HEIGHT, "Vulkan!"};
	};
}