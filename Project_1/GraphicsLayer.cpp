#include "GraphicsLayer.h"
namespace Project_ONE {

	//
	RESULT GraphicsDevice::Create(GraphicsDevice ** ppDevice)
	{
		return RESULT::R_SUCCESS;
	}


	namespace VK {
		//



		Device::Device()
		{
		}

		Device::~Device()
		{
			if (true)
			{

			}
			vkDestroyDevice(mDevice, nullptr);
			vkDestroyInstance(mInstance, nullptr);
		}

		RESULT Device::Create(Device** ppDevice, bool debug)
		{
			//
			auto errcode = RESULT::R_FAILED_DEVICE;
			//设备必须对象
			VkInstance	mInstance = null;
			VkPhysicalDevice mPhysicalDevice = null;
			VkDevice  mDevice = null;
			VkPhysicalDeviceProperties deviceProperties;
			VkPhysicalDeviceFeatures deviceFeatures;
			VkPhysicalDeviceMemoryProperties deviceMemoryProperties;
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
			//
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
				if (debug)
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

			//获取队列特征
			count = 0;
			//
			vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &count, NULL);
			//
			if (count == 0)
			{
				std::runtime_error("创建设备实例失败");
				return RESULT::R_FAILED_DEVICE;
			}
			//
			std::vector<VkQueueFamilyProperties> queueProps;
			queueProps.resize(count);
			vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &count, queueProps.data());
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
			count = 0;
			err = vkEnumerateDeviceExtensionProperties(mPhysicalDevice, nullptr, &count, nullptr);
			if (err != VkResult::VK_SUCCESS)
			{
				std::runtime_error("创建设备实例失败");
				return RESULT::R_FAILED_DEVICE;
			}

			exPros.resize(count);
			vkEnumerateDeviceExtensionProperties(mPhysicalDevice, nullptr, &count, exPros.data());
			for (auto& i : exPros) {
				LayerEx.push_back(i.extensionName);
			}
			deviceCreateInfo.enabledExtensionCount = (uint32_t)LayerEx.size();
			deviceCreateInfo.ppEnabledExtensionNames = LayerEx.data();
			//
			if (debug)
			{
				count = 0;
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

			//创建对象
			*ppDevice = new Device(mInstance, mPhysicalDevice, mDevice, debug);
			//
			return RESULT::R_SUCCESS;
		}

		Device::Device(VkInstance instance, VkPhysicalDevice gpu, VkDevice device, bool debug)
		{
			//
			mInstance = instance;
			mPhysicalDevice = gpu;
			mDevice = device;
			mDebug = debug;
			//获取物理设备属性
			vkGetPhysicalDeviceProperties(mPhysicalDevice, &deviceProperties);
			vkGetPhysicalDeviceFeatures(mPhysicalDevice, &deviceFeatures);
			vkGetPhysicalDeviceMemoryProperties(mPhysicalDevice, &deviceMemoryProperties);
			//创建队列
			uint32_t queueCount;
			//
			vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueCount, NULL);
			//
			//
			std::vector<VkQueueFamilyProperties> queueProps;
			queueProps.resize(queueCount);
			vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueCount, queueProps.data());
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
					poolCi.queueFamilyIndex = i;
					vkCreateCommandPool(mDevice, &poolCi, null, &pool);
					vkGetDeviceQueue(mDevice, i, 0, &queue);
					//
					mGraphicsQueue = Queue::Queue(mDevice, queue, pool);
				}
				//
				if (queueProps[i].queueFlags  &  VK_QUEUE_COMPUTE_BIT)
				{
					//
					poolCi.queueFamilyIndex = i;
					vkCreateCommandPool(mDevice, &poolCi, null, &pool);
					vkGetDeviceQueue(mDevice, i, 0, &queue);
					mComputeQueue = Queue::Queue(mDevice, queue, pool);
				}
				//
				if (queueProps[i].queueFlags  &  VK_QUEUE_TRANSFER_BIT)
				{
					//
					poolCi.queueFamilyIndex = i;
					vkCreateCommandPool(mDevice, &poolCi, null, &pool);
					vkGetDeviceQueue(mDevice, i, 0, &queue);
					mTransferQueue = Queue::Queue(mDevice, queue, pool);
				}
				//
				if (queueProps[i].queueFlags  &  VK_QUEUE_SPARSE_BINDING_BIT)
				{
					//
					poolCi.queueFamilyIndex = i;
					vkCreateCommandPool(mDevice, &poolCi, null, &pool);
					vkGetDeviceQueue(mDevice, i, 0, &queue);
					mSparseBindingQueue = Queue::Queue(mDevice, queue, pool);
				}
				//
			}
			//
		}

		RESULT Device::CreateSwapchain()
		{
			//
			HWND window;
			//
			VkSurfaceKHR surface;
			//
			VkSwapchainKHR swapchain;
			//
			VkExtent2D extent;
			//
			uint32_t imageCount = 3;
			//auto format = VK_FORMAT_R8G8B8A8_UNORM;
			auto preTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
			auto presentMode = VK_PRESENT_MODE_MAILBOX_KHR;
			auto imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
			bool clipped = true;
			auto  compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
			VkSurfaceFormatKHR format;
			//创建链接对象
			VkWin32SurfaceCreateInfoKHR ci = {};
			ci.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
			ci.hinstance = GetModuleHandle(0);
			ci.hwnd = window;

			if (vkCreateWin32SurfaceKHR(mInstance, &ci, null, &surface) != VkResult::VK_SUCCESS)
			{
				std::runtime_error("创建交换失败");
				return RESULT::R_FAILED;
			}

			//获取索引
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
			uint32_t index;
			for (index = 0; index < queueProps.size(); index++)
			{
				if (queueProps[index].queueFlags&VK_QUEUE_GRAPHICS_BIT)
				{
					break;
				}
			}
			//
			VkBool32 supports = VK_FALSE;
			if (vkGetPhysicalDeviceSurfaceSupportKHR(mPhysicalDevice, index, surface, &supports) != VkResult::VK_SUCCESS)
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
			//
			if (vkGetPhysicalDeviceSurfaceFormatsKHR(mPhysicalDevice, surface, &count, nullptr) != VkResult::VK_SUCCESS)
			{
				return RESULT::R_FAILED;
			}
			std::vector<VkSurfaceFormatKHR> surfaceformat(count);
			vkGetPhysicalDeviceSurfaceFormatsKHR(mPhysicalDevice, surface, &count, surfaceformat.data());
			if (surfaceformat[0].format == VK_FORMAT_UNDEFINED)
			{
				format.format = VK_FORMAT_R8G8B8A8_UNORM;
				format.colorSpace = VK_COLORSPACE_SRGB_NONLINEAR_KHR;
			}
			else
			{
				format = surfaceformat[0];
			}
			//
			count = 0;

			if (vkGetPhysicalDeviceSurfacePresentModesKHR(mPhysicalDevice, surface, &count, nullptr) != VkResult::VK_SUCCESS)
			{
				return RESULT::R_FAILED;
			}

			std::vector<VkPresentModeKHR> presentModes(count);
			vkGetPhysicalDeviceSurfacePresentModesKHR(mPhysicalDevice, surface, &count, presentModes.data());
			bool mailbox = false;
			for (auto& i : presentModes)
			{
				if (i == VK_PRESENT_MODE_MAILBOX_KHR)
				{
					mailbox = true;
				}
			}
			if (!mailbox)
			{
				presentMode = VK_PRESENT_MODE_IMMEDIATE_KHR;
			}
			//
			VkSurfaceCapabilitiesKHR capabilities;
			//
			if (vkGetPhysicalDeviceSurfaceCapabilitiesKHR(mPhysicalDevice, surface, &capabilities) != VkResult::VK_SUCCESS)
			{
				return RESULT::R_FAILED;
			}
			//
			extent = capabilities.currentExtent;
			if (preTransform != VK_SURFACE_TRANSFORM_FLAG_BITS_MAX_ENUM_KHR)
			{
				preTransform = capabilities.currentTransform;
			}
			//
			VkSwapchainCreateInfoKHR swapchainCI = {};
			swapchainCI.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
			swapchainCI.surface = surface;
			swapchainCI.minImageCount = imageCount;;
			swapchainCI.imageColorSpace = format.colorSpace;
			swapchainCI.imageFormat = format.format;
			swapchainCI.imageExtent = extent;
			swapchainCI.imageArrayLayers = 1;
			swapchainCI.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
			swapchainCI.imageSharingMode = imageSharingMode;
			swapchainCI.preTransform = preTransform;
			swapchainCI.presentMode = presentMode;
			swapchainCI.compositeAlpha = compositeAlpha;
			swapchainCI.clipped = clipped;

			if (vkCreateSwapchainKHR(mDevice, &swapchainCI, nullptr, &swapchain) != VkResult::VK_SUCCESS)
			{
				std::runtime_error("创建交换失败");
				return RESULT::R_FAILED;
			}
			//



			//
			return RESULT::R_SUCCESS;
		}

		RESULT Device::CreateSwapchain(NativeWindow * window)
		{
			return RESULT();
		}


		//=======================================================
		//=======================================================
		Queue::Queue(VkDevice device, VkQueue queue, VkCommandPool pool)
		{
			mDevice = device;
			mQueue = queue;
			mPool = pool;

		}

		Queue::~Queue()
		{
			if (mPool)
			{
				vkDestroyCommandPool(mDevice, mPool, null);
			}
		}

		inline RESULT Queue::Execute(uint32_t count, CommandList ** ppCommandList, uint32_t waitCount, Signal * waitSignal, uint32_t sendCount, Signal * sendSignal, Fence * pFence)
		{
			//
			static std::vector<VkCommandBuffer> cmdList(100);
			//
			if (cmdList.size() < count)
			{
				cmdList.resize(count + 10);
			}
			//
			for (uint32_t i = 0; i < count; i++)
			{
				cmdList[i] = ppCommandList[i]->mCmd;
			}
			//
			switch (ppCommandList[0]->mCmdType)
			{
			case Project_ONE::VK::CommandType::Graphics:
				VkSubmitInfo  submit = {};
				submit.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
				submit.commandBufferCount = count;
				submit.pCommandBuffers = cmdList.data();
				//
				submit.signalSemaphoreCount = sendCount;
				submit.pSignalSemaphores = sendSignal;
				//
				static VkPipelineStageFlags pipe_stage_flags =
					VK_PIPELINE_STAGE_ALL_COMMANDS_BIT;
				submit.pWaitDstStageMask = &pipe_stage_flags;
				//
				submit.waitSemaphoreCount = waitCount;
				submit.pWaitSemaphores = waitSignal;
				if (pFence)
				{
					if (vkQueueSubmit(mGraphicsQueue, 1, &submit, pFence->mFence) != VkResult::VK_SUCCESS)
					{
						return RESULT::R_ERROR_COMMAND;
					}
					break;
				}
				if (vkQueueSubmit(mGraphicsQueue, 1, &submit, 0) != VkResult::VK_SUCCESS)
				{
					return RESULT::R_ERROR_COMMAND;
				}
				break;
			case Project_ONE::VK::CommandType::Compute:
				VkSubmitInfo  submit = {};
				submit.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
				submit.commandBufferCount = count;
				submit.pCommandBuffers = cmdList.data();
				//
				submit.signalSemaphoreCount = sendCount;
				submit.pSignalSemaphores = sendSignal;
				//
				static VkPipelineStageFlags pipe_stage_flags =
					VK_PIPELINE_STAGE_ALL_COMMANDS_BIT;
				submit.pWaitDstStageMask = &pipe_stage_flags;
				//
				submit.waitSemaphoreCount = waitCount;
				submit.pWaitSemaphores = waitSignal;
				//
				if (pFence)
				{
					if (vkQueueSubmit(mComputeQueue, 1, &submit, pFence->mFence) != VkResult::VK_SUCCESS)
					{
						return RESULT::R_ERROR_COMMAND;
					}
					break;
				}
				if (vkQueueSubmit(mComputeQueue, 1, &submit, 0) != VkResult::VK_SUCCESS)
				{
					return RESULT::R_ERROR_COMMAND;
				}
				break;
			case Project_ONE::VK::CommandType::Transfer:
				VkSubmitInfo  submit = {};
				submit.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
				submit.commandBufferCount = count;
				submit.pCommandBuffers = cmdList.data();
				//
				submit.signalSemaphoreCount = sendCount;
				submit.pSignalSemaphores = sendSignal;
				//
				static VkPipelineStageFlags pipe_stage_flags =
					VK_PIPELINE_STAGE_ALL_COMMANDS_BIT;
				submit.pWaitDstStageMask = &pipe_stage_flags;
				//
				submit.waitSemaphoreCount = waitCount;
				submit.pWaitSemaphores = waitSignal;
				//
				if (pFence)
				{
					if (vkQueueSubmit(mTransferQueue, 1, &submit, pFence->mFence) != VkResult::VK_SUCCESS)
					{
						return RESULT::R_ERROR_COMMAND;
					}
					break;
				}
				if (vkQueueSubmit(mTransferQueue, 1, &submit, 0) != VkResult::VK_SUCCESS)
				{
					return RESULT::R_ERROR_COMMAND;
				}
				break;
			case Project_ONE::VK::CommandType::SparseBinding:
				VkSubmitInfo  submit = {};
				submit.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
				submit.commandBufferCount = count;
				submit.pCommandBuffers = cmdList.data();
				//
				submit.signalSemaphoreCount = sendCount;
				submit.pSignalSemaphores = sendSignal;
				//
				static VkPipelineStageFlags pipe_stage_flags =
					VK_PIPELINE_STAGE_ALL_COMMANDS_BIT;
				submit.pWaitDstStageMask = &pipe_stage_flags;
				//
				submit.waitSemaphoreCount = waitCount;
				submit.pWaitSemaphores = waitSignal;
				//
				if (pFence)
				{
					if (vkQueueSubmit(mSparseBindingQueue, 1, &submit, pFence->mFence) != VkResult::VK_SUCCESS)
					{
						return RESULT::R_ERROR_COMMAND;
					}
					break;
				}
				if (vkQueueSubmit(mSparseBindingQueue, 1, &submit, 0) != VkResult::VK_SUCCESS)
				{
					return RESULT::R_ERROR_COMMAND;
				}
				break;
			default:
				break;
			}

			return RESULT::R_SUCCESS;
		}

		//=======================================================
		//=======================================================
		CommandList::CommandList(VkDevice device, VkCommandPool pool, VkCommandBuffer cmd, CommandType cmdtype)
		{
			mDevice = device;
			mPool = pool;
			mCmd = cmd;
			mCmdType = cmdtype;
		}

		CommandList::~CommandList()
		{
			if (mCmd)
			{
				vkFreeCommandBuffers(mDevice, mPool, 1, &mCmd);
			}
		}
		//=======================================================
		//=======================================================
		Swaphcian::~Swaphcian()
		{
		}

		Swaphcian::Swaphcian(VkDevice Device, VkSurfaceKHR Surface, VkSwapchainKHR Swapchain, uint32_t Imagecount, VkSurfaceFormatKHR Format, VkExtent2D Extent, VkSharingMode ImageSharingMode, VkPresentModeKHR PresentMode, VkSurfaceTransformFlagBitsKHR PreTransform, VkCompositeAlphaFlagBitsKHR CompositeAlpha, bool Clipped)
		{
			mDevice = Device;
			mSurface = Surface;
			mSwapchain = Swapchain;
			mImagecount = Imagecount;
			mFormat = Format;
			mExtent = Extent;
			mImageSharingMode = ImageSharingMode;
			mPresentMode = PresentMode;
			mPreTransform = PreTransform;
			mCompositeAlpha = CompositeAlpha;
			mClipped = Clipped;
		}

		void Swaphcian::CreateBuffers(uint32_t count)
		{
			//
			for (auto i : mBackIViews)
			{
				vkDestroyImageView(mDevice, i, nullptr);
			}
			//

			//
		}

		RESULT Swaphcian::Resize(int w, int h)
		{
			//
			auto old = mSwapchain;
			//
			VkSwapchainCreateInfoKHR swapchainCI = {};
			swapchainCI.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
			swapchainCI.surface = mSurface;
			swapchainCI.minImageCount = mImagecount;;
			swapchainCI.imageColorSpace = mFormat.colorSpace;
			swapchainCI.imageFormat = mFormat.format;
			swapchainCI.imageExtent = mExtent;
			swapchainCI.imageArrayLayers = 1;
			swapchainCI.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
			swapchainCI.imageSharingMode = mImageSharingMode;
			swapchainCI.preTransform = mPreTransform;
			swapchainCI.presentMode = mPresentMode;
			swapchainCI.compositeAlpha = mCompositeAlpha;
			swapchainCI.clipped = mClipped;
			swapchainCI.oldSwapchain = mSwapchain;

			if (vkCreateSwapchainKHR(mDevice, &swapchainCI, nullptr, &mSwapchain) != VkResult::VK_SUCCESS)
			{
				std::runtime_error("创建交换失败");
				return RESULT::R_FAILED;
			}
			//
			if (old)
			{
				vkDestroySwapchainKHR(mDevice, old, nullptr);
			}
			//
			for (auto i : mBackIViews) {
				vkDestroyImageView(mDevice, i, nullptr);
			}
			//
			return RESULT::R_SUCCESS;
		}

	}

}