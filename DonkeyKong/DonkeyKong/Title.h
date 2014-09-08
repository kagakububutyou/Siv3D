#pragma once
#include <Siv3D.hpp>
#include <memory>
class CTitle
{
public:
	CTitle();
	~CTitle(){};


	void Draw();

private:

	std::unique_ptr<Font> Logo;
	std::unique_ptr<Font> Text;
};

