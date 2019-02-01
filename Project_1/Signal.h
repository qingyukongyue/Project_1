#pragma once
#ifndef _p_SIGNAL_H
#define _p_SIGNAL_H
#include"include.h"
namespace Project_ONE {
	//
	class Signal {
	public:
		explicit Signal(VkDevice device, VkSemaphore signal);
		~Signal();
	protected:
		VkDevice mDevice;
	public:
		VkSemaphore signal = 0;
	};

}

#endif // !_p_SIGNAL_H
