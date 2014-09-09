#pragma once
#include <Siv3D.hpp>
#include <memory>
class CClear
{
public:
	CClear();
	~CClear(){};

	void Draw();

private:

	std::unique_ptr<Font> Logo;
	std::unique_ptr<Font> Text;

};

