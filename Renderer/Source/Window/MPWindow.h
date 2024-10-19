#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

namespace MP
{
	struct QueueFamilyIndices {
		uint32_t graphicsFamily;
		uint32_t presentFamily;
		bool foundFamily;
		bool foundPresentFamily;

		bool IsComplete() { return foundFamily && foundPresentFamily; }
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	class MPWindow
	{
	public:
		MPWindow(uint32_t width, uint32_t height, std::string& name);
		MPWindow(uint32_t width, uint32_t height, std::string name);
		~MPWindow();

		MPWindow(const MPWindow&) = delete;
		MPWindow& operator=(const MPWindow&) = delete;

		inline bool ShouldClose() const { return glfwWindowShouldClose(m_window); }

	private:
		void InitWindow();
		void InitVulkan();
		void CreateInstance();
		void PickPhysicalDevice();
		bool CheckValidationLayerSupport();
		void CreateLogicalDevice();
		void SetupDebugMessenger();
		void CreateSurface();
		void CreateSwapChain();
		void CreateImageViews();
		void CreateGraphicsPipeline();
		void CreateRenderPass();
		static std::vector<char> readFile(const std::string& fileName);
		VkShaderModule createShaderModule(const std::vector<char>& code);
		bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
		VkRenderPass renderPass; 
		VkPipeline graphicsPipeline;
		VkPipelineLayout pipelineLayout;

		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

		const std::vector<const char*> deviceExtensions = 
		{
			VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};

		static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
			VkDebugUtilsMessageTypeFlagsEXT messageType,
			const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
			void* pUserData);
		std::vector<const char*> GetRequiredExtensions();
		VkDebugUtilsMessengerEXT m_DebugMessenger;
		VkInstance m_instance; 
		VkSwapchainKHR swapChain;
		std::vector<VkImage> swapChainImages;
		VkFormat swapChainImageFormat;
		VkExtent2D swapChainExtent;
		std::vector<VkImageView> swapChainImageViews;


		const uint32_t m_width;
		const uint32_t m_height;

		VkDevice device;
		VkQueue graphicsQueue;
		VkQueue presentQueue;
		VkSurfaceKHR surface;
		QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
		VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;
		bool isDeviceSuitable(VkPhysicalDevice device);
		const std::vector<const char*> m_ValidationLayers =
		{
			"VK_LAYER_KHRONOS_validation"
		};

		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);

		void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
#ifdef NDEBUG
		const bool m_EnableValidationLayers = false;
#else
		const bool m_EnableValidationLayers = true;
#endif

		std::string m_windowName;
		GLFWwindow* m_window;

	};
}