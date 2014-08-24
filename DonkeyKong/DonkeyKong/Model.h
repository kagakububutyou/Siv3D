#pragma once
#include <Siv3D.hpp>

class CModel
{
public:
	CModel(const String modelfile, const String texfile = L" ");
	~CModel();

	enum class MODE
	{
		TEX_NORMAL,
		TEX_ALPHA,
		MATERIAL,
	};

	void Draw(const Float3 pos, const Float3 size, const Float3 rota, MODE mode, double alpha = 1.0);

private:
	Model *model;
	Texture *texture;
};