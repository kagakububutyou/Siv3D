#include "Model.h"
#include "Load.h"

CModel::CModel(const String modelfile, const String texfile)
{
	model = new Model(modelfile);
	texture = new Texture(texfile, Texture::Mipped);
}


CModel::~CModel()
{
}

void CModel::Draw(const Float3 pos, const Float3 size, const Float3 rota, MODE mode, double alpha)
{
	for (auto& node : model->nodes)
	{
		if (mode == MODE::TEX_ALPHA)
			node.mesh.scale(size).rotate(rota).translate(pos).draw(*texture, ColorF(1, 1, 1, alpha), *CLoad::TextureAlphaRenderer);

		else if (mode == MODE::TEX_NORMAL)
			node.mesh.scale(size).rotate(rota).translate(pos).draw(*texture, ColorF(1, 1, 1, alpha));

		else if (mode == MODE::MATERIAL)
			node.mesh.scale(size).rotate(rota).translate(pos).draw(node.material.diffuse.col);
	}
}