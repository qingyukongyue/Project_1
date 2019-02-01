#pragma once
#ifndef _P_FENCE_H
#define _P_FENCE_H
#include"include.h"
//
namespace Project_ONE {
	//
	class Fence {
	public:
		//
		explicit Fence(VkDevice device,VkFence fence);
		~Fence();
	protected:
		//
		VkDevice mDevice = 0;
		//
	public:
		//
		VkFence fence = 0;
		//
		virtual RESULT Wait(uint64_t timeout);
		//
		virtual RESULT Status();
		//
		virtual RESULT ResetStatus();
		//
	};
	//
}

#endif // !_P_FENCE_H
