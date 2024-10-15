#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace mp
{
	class MPWindow
	{
	public:
		MPWindow(int width, int height, std::string& name);
		MPWindow(int width, int height, std::string name);
		~MPWindow();

		MPWindow(const MPWindow&) = delete;
		MPWindow& operator=(const MPWindow&) = delete;

		bool ShouldClose() { return glfwWindowShouldClose(m_window); }

	private:
		void InitWindow();

		const int m_width;
		const int m_height;

		std::string m_windowName;
		GLFWwindow* m_window;

	};
}