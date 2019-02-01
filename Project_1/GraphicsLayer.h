#pragma once
#ifndef _P_GRAPHICS_LAYER_H
#define _P_GRAPHICS_LAYER_H

//
#include"include.h"
//
#include"NativeWindow.h"


//
namespace Project_ONE {
	//=================
	//
	class Graphics;
	//
	class GraphicsDevice;
	class GraphicsQueue;
	class GraphicsCommandList;
	class GraphicsSwapchain;
	//=================
	class DLL_EXPORT GraphicsDevice {
	public:
		//
		static RESULT Create(GraphicsDevice** ppDevice);
		//
		virtual RESULT CreateSwapchain(NativeWindow* window) = 0;
		//
	};
	//=================
	namespace VK {
		//=========================
		//声明
		//=========================
		class Device;
		class Queue;
		class CommandList;
		//
		class Swapchain;
		//
		class Buffer;
		class Texture;
		//
		class Pipeline_Graphics;
		class Pipeline_Compute;
		//
		class Shaders;
		//
		class Fence;
		//
		enum class CommandType {
			Graphics,
			Compute,
			Transfer,
			SparseBinding,
		};
		//
		typedef VkSemaphore Signal;
		//
		//=========================
		//VK设备
		//=========================
		class DLL_EXPORT Device : public GraphicsDevice
		{
		public:
			//无实现
			explicit Device();
			~Device();
			static RESULT Create(Device** ppDevice, bool debug = false);
			//
		private:
			//
			explicit Device(
				VkInstance instance,
				VkPhysicalDevice gpu,
				VkDevice device,
				bool debug
				);
			//
			VkInstance	mInstance = null;
			VkPhysicalDevice mPhysicalDevice = null;
			VkDevice  mDevice = null;
			bool mDebug;
			VkPhysicalDeviceProperties deviceProperties;
			VkPhysicalDeviceFeatures deviceFeatures;
			VkPhysicalDeviceMemoryProperties deviceMemoryProperties;
			//
			Queue mGraphicsQueue;
			Queue mComputeQueue;
			Queue mTransferQueue;
			Queue mSparseBindingQueue;
			//
		public:
			//
			virtual Queue* GraphicsQueue() { return &mGraphicsQueue; }
			//
			virtual Queue* ComputeQueue() { return &mComputeQueue; }
			//
			virtual Queue* TransferQueue() { return &mTransferQueue; }
			//
			virtual Queue* SparseBindingQueue() { return &mSparseBindingQueue; }
			//
			virtual RESULT CreateSwapchain(
			
			);


			// 通过 GraphicsDevice 继承
			virtual RESULT CreateSwapchain(NativeWindow * window) override;

			//=================
		};
		//=========================
		//
		//=========================
		class DLL_EXPORT Queue
		{
		public:
			explicit Queue() {}
			explicit Queue(VkDevice device, VkQueue queue, VkCommandPool pool);
			~Queue();
		private:
			VkDevice  mDevice = null;
			VkQueue	mQueue = null;
			VkCommandPool mPool = null;
			VkQueue mGraphicsQueue = 0;
			VkQueue mComputeQueue = 0;
			VkQueue mTransferQueue = 0;
			VkQueue mSparseBindingQueue = 0;
		public:
			//
			VkQueue GetQueueHandle() { return mQueue; }
			//VkCommandPool GetPoolHandle() { return mPool; }
			//
			virtual RESULT Execute(
				uint32_t count,
				CommandList** ppCommandList,
				uint32_t waitCount,
				Signal* waitSignal,
				uint32_t sendCount,
				Signal* sendSignal,
				Fence* pFence
				);
			//
		};
		//=========================
		//
		//=========================
		class DLL_EXPORT CommandList {
		public:
			explicit CommandList() {}
			explicit CommandList(VkDevice device, VkCommandPool pool, VkCommandBuffer cmd, CommandType cmdtype);
			~CommandList();
			//
			VkCommandBuffer mCmd = 0;
			//
			CommandType mCmdType;
			//
		private:
			VkDevice mDevice = 0;
			VkCommandPool mPool = 0;
			
		};
		//=========================
		//
		//=========================
		class DLL_EXPORT Swaphcian
		{
		public:
			explicit Swaphcian(){}
			~Swaphcian();
			//
			explicit Swaphcian(
				VkDevice Device,
				VkSurfaceKHR Surface,
				VkSwapchainKHR Swapchain,
				uint32_t Imagecount,
				VkSurfaceFormatKHR Format,
				VkExtent2D Extent,
				VkSharingMode ImageSharingMode,
				VkPresentModeKHR PresentMode,
				VkSurfaceTransformFlagBitsKHR PreTransform,
				VkCompositeAlphaFlagBitsKHR CompositeAlpha,
				bool Clipped
			);
		private:
			VkDevice mDevice;
			VkSurfaceKHR mSurface;
			VkSwapchainKHR mSwapchain;
			uint32_t mImagecount;
			VkSurfaceFormatKHR mFormat;
			VkExtent2D mExtent;
			VkSharingMode mImageSharingMode;
			VkPresentModeKHR mPresentMode;
			VkSurfaceTransformFlagBitsKHR mPreTransform;
			VkCompositeAlphaFlagBitsKHR mCompositeAlpha;
			bool mClipped;

			//
			std::vector<VkImage> mBackImages;
			std::vector<VkImageView> mBackIViews;
			//
			VkQueue mQueue = 0;
			//
			void CreateBuffers(uint32_t count);
			//
		public:
			//
			virtual RESULT Resize(int w=0, int h = 0);
			//





			//
		};
		//=========================
		//
		//=========================
		class Fence {
		public:
			VkFence mFence = 0;
		};
		//=========================
		//
		//=========================
		//
	}
}
//

#endif // !_P_GRAPHICS_LAYER_H
