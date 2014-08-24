#pragma once

#include <Siv3D.hpp>
#include <memory>
class CLoad
{
public:
	CLoad();
	~CLoad();

	static std::unique_ptr<CLoad> &GetInstance()
	{
		if (Load == nullptr)
		{
			Load.reset(new CLoad());
		}
		return Load;

	}
	//　グラフィックの種類
	enum GraphicType
	{
		Hoge_Graphic,//（仮）
		Max_Type,
	};

	static String Graphic[GraphicType::Max_Type];
	static Renderer *TextureAddRenderer;
	static Renderer *TextureAlphaRenderer;
private:
	static std::unique_ptr<CLoad> Load;

};