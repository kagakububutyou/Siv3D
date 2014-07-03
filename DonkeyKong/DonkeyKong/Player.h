#pragma once

# include <Siv3D.hpp>

class Player
{
private:

	Float3 Pos;
	Float2 Vec;
	Float2 Speed;
	Float2 Size;
	
public:
	Player();
	~Player();

	void Move();

	void Drwa();
};

