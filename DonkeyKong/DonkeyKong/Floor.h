#pragma once
#include <Siv3D.hpp>

class CFloor
{
private:
	

public:
	CFloor(Float3 pos, Float3 size);
	~CFloor();

	Float3 Pos;
	Float3 Size;

	void Draw();
};

