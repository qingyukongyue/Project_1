#include "Signal.h"

Project_ONE::Signal::Signal(VkDevice device, VkSemaphore signal)
{
	signal = signal;
}

Project_ONE::Signal::~Signal()
{
	if (signal)
	{
		vkDestroySemaphore(mDevice, signal, nullptr);
	}
}
