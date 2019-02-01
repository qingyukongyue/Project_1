#pragma once
#ifndef _P_ENGINE_H
#define _P_ENGINE_H

#include"GraphicsLayer.h"
//
#include"RenderWindow.h"
//

namespace Project_ONE {

	class DLL_EXPORT Engine {
	public:
		//
		static RESULT Create(Engine** ppEngine);
		//
	private:
		//
		RESULT Initial();
		//
		GraphicsDevice* mDevice = 0;
		//
		GraphicsSwapchain* mSwapchain = 0;
		//
		RenderWindow*  mWindow = 0;

		//
	};
}

#endif // !_P_ENGINE_H
