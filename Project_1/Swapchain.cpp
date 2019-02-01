#include "Swapchain.h"
namespace Project_ONE {

	Swapchain::Swapchain(Queue* pQueue, VkDevice device, VkSurfaceKHR surface, VkSwapchainKHR swapchain, uint32_t imagecount, VkFormat format, VkExtent2D extent)
	{
		_device = device;
		_surface = surface;
		_imagecount = imagecount;
		_format = format;
		_extent = extent;
		//
		this->CreateBuffer();
		//
		_queue->CreateCommandList(&_cmd);
	}

	void Swapchain::CreateBuffer()
	{
		//释放
		for (auto & i : _backs) {
			if (i.view)
			{
				vkDestroyImageView(_device, i.view, nullptr);
			}
		}
		//
		_backs.resize(_imagecount);
		std::vector<VkImage> images(_imagecount);
		
		vkGetSwapchainImagesKHR(_device, _swapchain, &_imagecount, images.data());

		//
		VkImageViewCreateInfo viewCi = {};
		viewCi.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		viewCi.viewType = VkImageViewType::VK_IMAGE_VIEW_TYPE_2D;
		viewCi.format = _format;
		viewCi.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;//VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
		viewCi.subresourceRange.baseMipLevel = 0;
		viewCi.subresourceRange.levelCount = 1;
		viewCi.subresourceRange.baseArrayLayer = 0;
		viewCi.subresourceRange.layerCount = 1;
		viewCi.components = {
			VK_COMPONENT_SWIZZLE_R,
			VK_COMPONENT_SWIZZLE_G,
			VK_COMPONENT_SWIZZLE_B,
			VK_COMPONENT_SWIZZLE_A
		};

		//
		for (size_t i = 0; i < images.size(); i++)
		{
			_backs[i].image = images[i];
			viewCi.image = images[i];
			//
			vkCreateImageView(_device, &viewCi, nullptr, &_backs[i].view);
		}


	}

	void Swapchain::CreateCmd()
	{

	}

	RESULT Swapchain::Resize(int w, int h)
	{
		//
		auto old = _swapchain;
		//
		VkSwapchainCreateInfoKHR swapchainCI = {};
		swapchainCI.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		swapchainCI.surface = _surface;
		swapchainCI.minImageCount = _imagecount;
		swapchainCI.imageFormat = _format;
		swapchainCI.imageColorSpace = VK_COLORSPACE_SRGB_NONLINEAR_KHR;
		swapchainCI.imageExtent = _extent;
		swapchainCI.imageArrayLayers = 1;
		swapchainCI.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
		swapchainCI.preTransform = _preTransform;
		swapchainCI.compositeAlpha = _compositeAlpha;
		swapchainCI.presentMode = _presentMode;
		swapchainCI.imageSharingMode = _imageSharingMode;
		swapchainCI.clipped = _clipped;
		//
		swapchainCI.oldSwapchain = old;
		//
		if (vkCreateSwapchainKHR(_device, &swapchainCI, nullptr, &_swapchain) != VkResult::VK_SUCCESS)
		{
			std::runtime_error("创建交换失败");
			return RESULT::R_FAILED;
		}
		//
		return RESULT::R_SUCCESS;
	}

	RESULT Swapchain::Present(uint32_t waits, Signal * ppWaitSignal, uint32_t sends, Signal * ppSendSignal, uint32_t backimageindex )
	{
		VkSubmitInfo  submitPresent = {};
		submitPresent.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		submitPresent.commandBufferCount = 1;
		submitPresent.pCommandBuffers = &_cmd[backimageindex]->_cmd;
		//
		submitPresent.signalSemaphoreCount = sends;
		submitPresent.pSignalSemaphores = ppSendSignal;
		//
		VkPipelineStageFlags pipe_stage_flags =
			VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT;
		submitPresent.pWaitDstStageMask = &pipe_stage_flags;
		//
		submitPresent.waitSemaphoreCount = waits;
		submitPresent.pWaitSemaphores = ppWaitSignal;
		//
		VkPresentInfoKHR presentInfo = {};
		presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
		presentInfo.pNext = NULL;
		presentInfo.swapchainCount = 1;
		presentInfo.pSwapchains = &_swapchain;
		presentInfo.pImageIndices = &backimageindex;

		_queue->Submit(1, &submitPresent, null);
		//
		vkQueuePresentKHR(_queue->GetQueueHeandle(), &presentInfo);
		//
		return RESULT::R_SUCCESS;
	}


}