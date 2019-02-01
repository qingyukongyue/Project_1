#pragma once
#ifndef _P_SWAPCHAIN_H
#define _P_SWAPCHAIN_H
//
#include"include.h"
//
#include"GraphicsDevice.h"
//

//
namespace Project_ONE {
	//
	class GraphicsDevice;
	//
	struct _SWAPCHAIN_BUFFER
	{
		VkImage image;
		VkImageView view;
	};
	//
	class DLL_EXPORT Swapchain {
	public:
		//
		explicit Swapchain(
			Queue* pQueue,
			VkDevice device,
			VkSurfaceKHR surface,
			VkSwapchainKHR swapchain,
			uint32_t imagecount,
			VkFormat format,
			VkExtent2D _extent
		);
		//
	protected:
		//
		VkDevice _device;
		VkSurfaceKHR _surface;
		VkSwapchainKHR _swapchain;
		uint32_t _imagecount;
		VkFormat _format;
		VkExtent2D _extent;
		VkSharingMode _imageSharingMode;
		VkPresentModeKHR _presentMode;
		VkSurfaceTransformFlagBitsKHR _preTransform;
		VkCompositeAlphaFlagBitsKHR _compositeAlpha;
		bool _clipped;
		//
		Queue* _queue;
		//�任���ֺ��ύ��������
		std::vector<CommandList*> _cmd;
		//��̨����
		std::vector<_SWAPCHAIN_BUFFER> _backs;
		//
		uint32_t _backindex;
		//
		
		//
		void CreateBuffer();
		//
		void CreateCmd();
		//
	public:
		//
		uint32_t GetBackbufferCount() { return _imagecount; }
		//
		VkImage	GetImage(uint32_t index) { return _backs[index].image; }
		//
		VkImageView GetImageView(uint32_t index) { return _backs[index].view; }
		//
		virtual RESULT Resize(int w, int h);
		//
		virtual RESULT Present(
			uint32_t waits, Signal* ppWaitSignal,
			uint32_t sends,Signal* ppSendSignal,
			uint32_t backimageindex	//��̨����
		);
		//
	};
	//
}
#endif // !_P_SWAPCHAIN_H
