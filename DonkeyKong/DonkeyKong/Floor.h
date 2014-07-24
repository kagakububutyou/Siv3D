#pragma once
#include <Siv3D.hpp>

#include "OBJECT.h"

class CFloor:public COBJECT
{
private:

	//const Texture texture(L"Example/d6-red-dots.png");

public:

	enum class FLOORTYPE
	{
		STEEL_FRAME,	//	ìSçú


		ALL_TYPES,		//	ëSéÌóﬁ
	};

	FLOORTYPE FloorType;


	CFloor(Float3 pos, Float3 size);
	~CFloor(){};

	void Draw(Color color);
};

