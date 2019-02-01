#include "Fence.h"

Project_ONE::Fence::Fence(VkDevice device, VkFence fence)
{
	mDevice = device;
	fence = fence;
}

Project_ONE::Fence::~Fence()
{
	if (fence)
	{
		vkDestroyFence(mDevice, fence, nullptr);
	}
}



RESULT Project_ONE::Fence::Wait(uint64_t timeout)
{
	if (this->Status() == RESULT::R_SUCCESS)
	{
		if (vkWaitForFences(mDevice, 1, &fence, true, timeout) != VkResult::VK_SUCCESS)
		{
			return RESULT::R_FAILED_TIMEOUT;
		}
		return RESULT::R_SUCCESS;
	}
	else
	{
		return RESULT::R_NEGATIVE;
	}
}

RESULT Project_ONE::Fence::Status()
{
	if (vkGetFenceStatus(mDevice, fence) != VkResult::VK_SUCCESS) {
		return RESULT::R_NOT_READY;
	}
	else
	{
		return RESULT::R_SUCCESS;
	}
}

RESULT Project_ONE::Fence::ResetStatus()
{
	if (vkResetFences(mDevice, 1, &fence) == VkResult::VK_NOT_READY)
	{
		return RESULT::R_NOT_READY;
	}
	return RESULT::R_INVALID_DEVICE;
}
