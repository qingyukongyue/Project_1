#include "GraphicsDevice.h"
#include "GraphicsLayer.h"

namespace Project_ONE {



	RESULT GraphicsDevice::Create(bool enableValidation)
	{
		//
		auto errcode = RESULT::R_FAILED_DEVICE;
		//
		//
		std::string name = "A3D Project";
		std::vector<VkPhysicalDevice> physicalDevices;
		//=======================================
		VkApplicationInfo appCI = {};
		appCI.apiVersion = VK_API_VERSION_1_0;
		appCI.applicationVersion = 1;
		appCI.engineVersion = 1;
		appCI.pApplicationName = name.data();
		appCI.pEngineName = name.data();
		appCI.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;

		//Assert only 
		VkResult err;
		//=======================================
		//枚举可用功能
		//=======================================
		std::vector<const char*> instanceLayer;
		std::vector<VkLayerProperties> instanceLayerProps;
		uint32_t  instanceCount = 0;
		err = vkEnumerateInstanceLayerProperties(&instanceCount, nullptr);
		if (err != VkResult::VK_SUCCESS)
		{
			std::runtime_error("创建Vulkan失败");
			return errcode;
		}


		instanceLayerProps.resize(instanceCount);
		vkEnumerateInstanceLayerProperties(&instanceCount, &instanceLayerProps[0]);
		for (auto& j : instanceLayerProps)
		{
			instanceLayer.push_back(j.layerName);
		}

		//实例扩展层
		std::vector<const char*>  instanceExLayer;
		std::vector<VkExtensionProperties> instanceExLayerProps;
		uint32_t  count = 0;
		err = vkEnumerateInstanceExtensionProperties(nullptr, &count, nullptr);
		if (err != VkResult::VK_SUCCESS)
		{
			std::runtime_error("创建Vulkan失败");
			return errcode;
		}

		instanceExLayerProps.resize(count);
		vkEnumerateInstanceExtensionProperties(nullptr, &count, &instanceExLayerProps[0]);
		for (auto&j : instanceExLayerProps)
		{
			instanceExLayer.push_back(j.extensionName);
		}
		//=======================================
		VkInstanceCreateInfo instanceCI = {};
		instanceCI.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		instanceCI.pNext = NULL;
		instanceCI.pApplicationInfo = &appCI;

		if (instanceExLayer.size())
		{
			if (enableValidation)
			{
				if (instanceLayer.size())
				{
					instanceCI.enabledLayerCount = (uint32_t)instanceLayer.size();
					instanceCI.ppEnabledLayerNames = instanceLayer.data();
				}
			}

			instanceCI.enabledExtensionCount = (uint32_t)instanceExLayer.size();
			instanceCI.ppEnabledExtensionNames = instanceExLayer.data();
		}
		//创建实例
		err = vkCreateInstance(&instanceCI, nullptr, &mInstance);
		if (err != VkResult::VK_SUCCESS)
		{
			std::runtime_error("创建设备实例失败");
			return RESULT::R_FAILED_DEVICE;
		}

		//
		//枚举物理设备
		count = 0;
		// Physical device
		uint32_t gpuCount = 0;
		// Get number of available physical devices
		err = vkEnumeratePhysicalDevices(mInstance, &gpuCount, nullptr);
		if (err != VkResult::VK_SUCCESS &&gpuCount < 1)
		{
			std::runtime_error("创建设备实例失败");
			return RESULT::R_FAILED_DEVICE;
		}
		// Enumerate devices
		physicalDevices.resize(gpuCount);
		vkEnumeratePhysicalDevices(mInstance, &gpuCount, physicalDevices.data());
		//
		mPhysicalDevice = physicalDevices[0];
		//
		uint32_t queueCount;
		//
		vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueCount, NULL);
		//
		if (queueCount == 0)
		{
			std::runtime_error("创建设备实例失败");
			return RESULT::R_FAILED_DEVICE;
		}
		//
		std::vector<VkQueueFamilyProperties> queueProps;
		queueProps.resize(queueCount);
		vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueCount, queueProps.data());
		//
		//队列数量
		int qc = 0;
		//
		float queuePriorities = 0.0f;
		std::vector<VkDeviceQueueCreateInfo> queueCIs;
		VkDeviceQueueCreateInfo queueCi = {};
		queueCi.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCi.pQueuePriorities = &queuePriorities;
		//
		for (size_t i = 0; i < queueProps.size(); i++)
		{
			//
			if (queueProps[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
			{
				//
				queueCi.queueCount = queueProps[i].queueCount;
				queueCi.queueFamilyIndex = i;
				queueCIs.push_back(queueCi);
			}
			//
			if (queueProps[i].queueFlags  &  VK_QUEUE_COMPUTE_BIT)
			{
				//
				queueCi.queueCount = queueProps[i].queueCount;
				queueCi.queueFamilyIndex = i;
				queueCIs.push_back(queueCi);
			}
			//
			if (queueProps[i].queueFlags  &  VK_QUEUE_TRANSFER_BIT)
			{
				//
				queueCi.queueCount = queueProps[i].queueCount;
				queueCi.queueFamilyIndex = i;
				queueCIs.push_back(queueCi);
			}
			//
			if (queueProps[i].queueFlags  &  VK_QUEUE_SPARSE_BINDING_BIT)
			{
				//
				queueCi.queueCount = queueProps[i].queueCount;
				queueCi.queueFamilyIndex = i;
				queueCIs.push_back(queueCi);
			}
			//
		}
		//
		VkDeviceCreateInfo deviceCreateInfo = {};
		deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		deviceCreateInfo.pNext = NULL;
		deviceCreateInfo.queueCreateInfoCount = queueCIs.size();
		deviceCreateInfo.pQueueCreateInfos = queueCIs.data();
		deviceCreateInfo.pEnabledFeatures = NULL;
		std::vector<const char*> LayerEx;
		std::vector<const char*> Layer;
		std::vector<VkExtensionProperties> exPros;
		std::vector<VkLayerProperties> pros;
		//
		if (true)
		{

		}
		//
		if (enableValidation)
		{
			uint32_t count = 0;
			err = vkEnumerateDeviceLayerProperties(mPhysicalDevice, &count, nullptr);
			if (err != VkResult::VK_SUCCESS)
			{
				std::runtime_error("创建设备实例失败");
				return RESULT::R_FAILED_DEVICE;
			}
			pros.resize(count);
			vkEnumerateDeviceLayerProperties(mPhysicalDevice, &count, pros.data());
			for (auto &i : pros) {
				Layer.push_back(i.layerName);
			}
			deviceCreateInfo.enabledLayerCount = (uint32_t)Layer.size();
			deviceCreateInfo.ppEnabledLayerNames = Layer.data();
		}
		//
		err = vkCreateDevice(mPhysicalDevice, &deviceCreateInfo, nullptr, &mDevice);
		if (err != VkResult::VK_SUCCESS)
		{
			std::runtime_error("创建设备实例失败");
			return RESULT::R_FAILED_DEVICE;
		}
		//
		//获取物理设备属性
		vkGetPhysicalDeviceProperties(mPhysicalDevice, &deviceProperties);
		vkGetPhysicalDeviceFeatures(mPhysicalDevice, &deviceFeatures);
		vkGetPhysicalDeviceMemoryProperties(mPhysicalDevice, &deviceMemoryProperties);
		//
		VkQueue queue;
		VkCommandPool pool;
		VkCommandPoolCreateInfo poolCi = {};
		poolCi.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
		poolCi.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
		//
		for (size_t i = 0; i < queueProps.size(); i++)
		{
			//
			if (queueProps[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
			{
				//
				mGraphicsIndex = i;
				//
				poolCi.queueFamilyIndex = i;
				err = vkCreateCommandPool(mDevice, &poolCi, null, &pool);
				//
				if (err != VkResult::VK_SUCCESS)
				{
					std::runtime_error("创建设备实例失败");
					return RESULT::R_FAILED_DEVICE;
				}
				//
				vkGetDeviceQueue(mDevice, i, 0, &queue);
				//
				mGraphicsQueue = Queue::Queue(mDevice, queue, pool);
			}
			//
			if (queueProps[i].queueFlags  &  VK_QUEUE_COMPUTE_BIT)
			{
				//
				//
				poolCi.queueFamilyIndex = i;
				err = vkCreateCommandPool(mDevice, &poolCi, null, &pool);
				//
				if (err != VkResult::VK_SUCCESS)
				{
					std::runtime_error("创建设备实例失败");
					return RESULT::R_FAILED_DEVICE;
				}
				//
				vkGetDeviceQueue(mDevice, i, 0, &queue);
				//
				mComputeQueue = Queue::Queue(mDevice, queue, pool);
			}
			//
			if (queueProps[i].queueFlags  &  VK_QUEUE_TRANSFER_BIT)
			{
				//
				//
				poolCi.queueFamilyIndex = i;
				err = vkCreateCommandPool(mDevice, &poolCi, null, &pool);
				//
				if (err != VkResult::VK_SUCCESS)
				{
					std::runtime_error("创建设备实例失败");
					return RESULT::R_FAILED_DEVICE;
				}
				//
				vkGetDeviceQueue(mDevice, i, 0, &queue);
				//
				mTransferQueue = Queue::Queue(mDevice, queue, pool);
			}
			//
			if (queueProps[i].queueFlags  &  VK_QUEUE_SPARSE_BINDING_BIT)
			{
				//
				//
				poolCi.queueFamilyIndex = i;
				err = vkCreateCommandPool(mDevice, &poolCi, null, &pool);
				//
				if (err != VkResult::VK_SUCCESS)
				{
					std::runtime_error("创建设备实例失败");
					return RESULT::R_FAILED_DEVICE;
				}
				//
				vkGetDeviceQueue(mDevice, i, 0, &queue);
				//
				mSparseBindingQueue = Queue::Queue(mDevice, queue, pool);
			}
			//
		}
		//

		//
		return RESULT::R_SUCCESS;
	}

	Signal  GraphicsDevice::CreateSignal()
	{
		//
		VkSemaphore signal;
		//
		VkSemaphoreCreateInfo Ci = {};
		Ci.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
		//
		vkCreateSemaphore(mDevice, &Ci, null, &signal);

		//return new Signal(mDevice, signal);
		return signal;
	}

	Fence * GraphicsDevice::CreateFence()
	{
		//
		VkFenceCreateInfo Ci = {};
		Ci.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
		//
		VkFence fence;
		//
		vkCreateFence(mDevice, &Ci, nullptr, &fence);

		//
		return new Fence(mDevice, fence);
	}

	RESULT GraphicsDevice::CreateSwapchain(Swapchain** ppSwapchain, HWND window, int backcount, VkSurfaceTransformFlagBitsKHR preTransform, VkCompositeAlphaFlagBitsKHR compositeAlpha, VkPresentModeKHR presentMode, VkBool32 clipped, VkSharingMode imageSharingMode, VkImageUsageFlags imageUsage)
	{
		//
		VkSurfaceKHR surface;
		//
		VkSwapchainKHR swapchain;
		//
		VkSurfaceCapabilitiesKHR capabilities;
		//
		VkSwapchainCreateInfoKHR swapchainCI = {};
		swapchainCI.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		swapchainCI.minImageCount = backcount;
		swapchainCI.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
		swapchainCI.imageArrayLayers = 1;
		swapchainCI.imageSharingMode = imageSharingMode;
		swapchainCI.presentMode = presentMode;
		swapchainCI.oldSwapchain = 0;
		swapchainCI.clipped = clipped;
		swapchainCI.compositeAlpha = compositeAlpha;
		swapchainCI.preTransform = preTransform;
		swapchainCI.imageColorSpace = VK_COLORSPACE_SRGB_NONLINEAR_KHR;
		swapchainCI.imageFormat = VK_FORMAT_R8G8B8A8_UNORM;
		//
		VkWin32SurfaceCreateInfoKHR ci = {};
		ci.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
		ci.hinstance = GetModuleHandle(0);
		ci.hwnd = window;

		if (vkCreateWin32SurfaceKHR(mInstance, &ci, null, &surface) != VkResult::VK_SUCCESS)
		{
			std::runtime_error("创建交换失败");
			return RESULT::R_FAILED;
		}
		//
		swapchainCI.surface = surface;

		//
		VkBool32 supports = VK_FALSE;
		if (vkGetPhysicalDeviceSurfaceSupportKHR(mPhysicalDevice, mGraphicsIndex, surface, &supports) != VkResult::VK_SUCCESS)
		{
			std::runtime_error("创建交换失败");
			return RESULT::R_FAILED;
		}

		//
		if (!supports)
		{
			std::runtime_error("创建交换失败");
			return RESULT::R_FAILED;
		}

		//
		uint32_t count = 0;
		//if (vkGetPhysicalDeviceSurfaceFormatsKHR(mPhysicalDevice, surface, &count, nullptr) != VkResult::VK_SUCCESS)
		//{
		//	return RESULT::R_FAILED;
		//}


		//count = 0;

		//if (vkGetPhysicalDeviceSurfacePresentModesKHR(mPhysicalDevice, surface, &count, nullptr) != VkResult::VK_SUCCESS)
		//{
		//	return RESULT::R_FAILED;
		//}

		//std::vector<VkPresentModeKHR> presentModes(count);
		//vkGetPhysicalDeviceSurfacePresentModesKHR(mPhysicalDevice, surface, &count, presentModes.data());



		//for (auto& i : presentModes)
		//{
		//	if (i == VK_PRESENT_MODE_MAILBOX_KHR)
		//	{

		//	}
		//}

		//
		if (vkGetPhysicalDeviceSurfaceCapabilitiesKHR(mPhysicalDevice, surface, &capabilities) != VkResult::VK_SUCCESS)
		{
			return RESULT::R_FAILED;
		}
		//
		swapchainCI.imageExtent = capabilities.currentExtent;
		//
		if (vkCreateSwapchainKHR(mDevice, &swapchainCI, nullptr, &swapchain) != VkResult::VK_SUCCESS)
		{
			std::runtime_error("创建交换失败");
			return RESULT::R_FAILED;
		}
		//
		*ppSwapchain = new Swapchain(&mGraphicsQueue, mDevice, surface, swapchain, backcount, VK_FORMAT_R8G8B8A8_UNORM, capabilities.currentExtent);

		//
		return RESULT::R_SUCCESS;
	}








	RESULT Queue::CreateCommandList(CommandList ** ppommandList)
	{
		//
		VkCommandBuffer cmd;
		//
		VkCommandBufferAllocateInfo Ci = {};
		Ci.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		Ci.commandBufferCount = 1;
		Ci.commandPool = mPool;

		auto err = vkAllocateCommandBuffers(mDevice, &Ci, &cmd);
		//
		if (err != VkResult::VK_SUCCESS)
		{
			return RESULT::R_FAILED;
		}
		//
		*ppommandList = new CommandList(mDevice, mPool, cmd);
		//
		return RESULT::R_SUCCESS;
	}

	RESULT Queue::Submit(uint32_t count, VkSubmitInfo * pSubmits, Fence * pfence)
	{
		//
		if (pfence)
		{
			if (vkQueueSubmit(mQueue, count, pSubmits, pfence->fence) != VkResult::VK_SUCCESS)
			{
				return RESULT::R_INVALID_DEVICE;
			}
		}
		else
		{
			if (vkQueueSubmit(mQueue, count, pSubmits, null) != VkResult::VK_SUCCESS)
			{
				return RESULT::R_INVALID_DEVICE;
			}
		}
	
		//
		return RESULT::R_SUCCESS;
	}

}