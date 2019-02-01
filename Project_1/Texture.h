#pragma once
#ifndef _P_TEXTURE_H
#define _P_TEXTURE_H
//
#include"include.h"
//
namespace Project_ONE {
	//
	class Swapchain;
	//
	struct TextureInfo;
	//
	class DLL_EXPORT Texture {
	public:
		~Texture();
		explicit Texture(VkDevice device,
			VkImage image,
			VkImageView view,
			TextureInfo info);
		//
	protected:
		//
		VkDevice mDevice = 0;
		VkDeviceMemory mMem = 0;
		//
		TextureInfo mInfo;
		//
	};
	//
	struct TextureInfo :public VkImageCreateInfo {
		//
		TextureInfo() {
			sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
			pNext = 0;
			flags = 0;
			imageType = VK_IMAGE_TYPE_2D;
			mipLevels = 1;
			arrayLayers = 1;
			samples = VK_SAMPLE_COUNT_1_BIT;
			sharingMode = VK_SHARING_MODE_EXCLUSIVE;
			queueFamilyIndexCount = 0;
			pQueueFamilyIndices = 0;
			initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
		}
		//
		VkFormat                 format;
		VkExtent3D               extent;
		uint32_t                 mipLevels;
		uint32_t                 arrayLayers;
		VkImageSubresourceRange    subresourceRange;
		VkSampleCountFlagBits    samples;
		VkImageTiling            tiling;
		VkImageUsageFlags        usage;
		VkSharingMode            sharingMode;
		VkImageLayout            initialLayout;
	};
	//
}
#endif // !_P_TEXTURE_H
