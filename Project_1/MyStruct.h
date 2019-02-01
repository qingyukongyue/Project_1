#pragma once
#ifndef _P_MY_STRUCT_H
#define _P_MY_STRUCT_H

namespace Project_ONE {

	//================
	//
	//================
	struct float2
	{
		float x, y;
	};

	struct float3 
	{
		float x, y, z;
	};

	struct float4
	{
		float x, y, z, w = 1;
	};

	struct RECTI
	{
		int x, y, w, h;
	};
	struct RECTU
	{
		unsigned x, y, w, h;
	};
	struct RECTF
	{
		float x, y, w, h;
	};
}
#endif // !_P_MY_STRUCT_H
