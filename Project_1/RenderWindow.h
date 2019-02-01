#pragma once
#ifndef _P_RENDER_WINDOW_H
#define _P_RENDER_WINDOW_H
//
#include"NativeWindow.h"
//
#include"GraphicsLayer.h"
//
namespace Project_ONE {
	//
	class DLL_EXPORT RenderWindow : public NativeWindow
	{
	public:
		RenderWindow();
		~RenderWindow();
		//
		virtual RESULT Initial(GraphicsDevice* pDevice, RenderWindow** ppWindow);
		//
	private:
		//
#define VULKAN
#ifdef VULKAN
		//==================================

		VK::Swapchain* mSwapchain = 0;


		//==================================
#endif // VULKAN

		//
	};
}


#endif // !_P_RENDER_WINDOW_H
