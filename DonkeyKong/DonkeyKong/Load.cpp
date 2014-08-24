#include "Load.h"

std::unique_ptr<CLoad> CLoad::Load = nullptr;

String CLoad::Graphic[GraphicType::Max_Type];
Renderer *CLoad::TextureAddRenderer;
Renderer *CLoad::TextureAlphaRenderer;

CLoad::CLoad()
{
	const String Path = L"engine\\data\\";
	const String Extension = L".png";

	//	�z��̒���GraphicType�̒��ɐݒ肵���v�f
	//�@�ǂݍ��ރO���t�B�b�N�̖��O
	//	Graphic[Hoge_Graphic] = L"hoge";

	for (auto& graph : Graphic)
	{
		const String Folder = L"Graph\\";
		const FilePath FileName = Path + Folder + graph + Extension;
		TextureAsset::Register(graph, FileName);
	}


	RendererProperty prop = RendererProperty::Forward();
	RendererProperty prop2 = RendererProperty::Forward();
	prop.forwardBlend = BlendState::Default();
	prop.depthWriteEnable = false;
	prop2.forwardBlend = BlendState::Additive();
	prop2.rasterizer = Rasterizer::NoCull_Solid;
	TextureAddRenderer = new Renderer(prop2);
	TextureAlphaRenderer = new Renderer(prop);
}


CLoad::~CLoad()
{
}