#pragma once

# include <Siv3D.hpp>

class CPlayer
{
private:

	Float3 Pos;
	Float2 Vec;
	Float2 Speed;
	Float3 Size;
	
public:
	CPlayer();
	~CPlayer();

	void Move();

	void Draw();
};

