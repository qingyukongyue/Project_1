#pragma once
#ifndef _P_GRAPHICS_DEVICE_H
#define _P_GRAPHICS_DEVICE_H

#include"include.h"
//
#include"CommandList.h"
//
//#include"Signal.h"
#include"Fence.h"
//
#include"Swapchain.h"



//
namespace Project_ONE {
	//
	typedef VkSemaphore Signal;
	//
	class Queue;
	//
	class DescibePool;
	//
	class Signal;
	class Fence;
	//
	class Swapchain;
	//
	class DLL_EXPORT GraphicsDevice
	{
	public:


		RESULT Create(bool enableValidation);

	protected:
		VkInstance	mInstance = null;
		VkPhysicalDevice mPhysicalDevice = null;

		VkDevice  mDevice = null;
		//
		int32_t mGraphicsIndex = -1;
		//
		Queue mGraphicsQueue;
		Queue mComputeQueue;
		Queue mTransferQueue;
		Queue mSparseBindingQueue;

		VkPhysicalDeviceProperties deviceProperties;
		VkPhysicalDeviceFeatures deviceFeatures;
		VkPhysicalDeviceMemoryProperties deviceMemoryProperties;
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
		virtual Signal CreateSignal();
		//
		virtual Fence* CreateFence();
		//
		virtual RESULT CreateSwapchain(
			Swapchain** ppSwapchain,
			HWND window,
			int backbuffercount,
			VkSurfaceTransformFlagBitsKHR	preTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR,
			VkCompositeAlphaFlagBitsKHR		compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
			VkPresentModeKHR						presentMode = VK_PRESENT_MODE_MAILBOX_KHR,
			VkBool32										clipped = true,
			VkSharingMode							imageSharingMode = VK_SHARING_MODE_EXCLUSIVE,
			VkImageUsageFlags						imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT
		);
		//
	};
	//
	class CommandList;
	//
	class Queue {
	public:

		//
		explicit Queue(VkDevice device, VkQueue queue, VkCommandPool pool);
	protected:
		VkDevice mDevice = nullptr;
		VkQueue mQueue = nullptr;
		VkCommandPool mPool;
	public:
		//
		VkQueue GetQueueHeandle() { return mQueue; }
		//
		virtual RESULT CreateCommandList(CommandList** ppommandList);
		//
		virtual RESULT Submit(uint32_t count, VkSubmitInfo * pSubmits, Fence* pfence);
		//
	};

}
#endif // !_P_GRAPHICS_DEVICE_h