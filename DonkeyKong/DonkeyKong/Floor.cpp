#include "Floor.h"


CFloor::CFloor(Float3 pos, Float3 size)
{
	Pos = pos;
	Size = size;
	color = Color(231, 0, 91);

	TextureAsset::Register(L"Floor",L"engine/Texture/floor.png");

	if (!TextureAsset(L"Floor"))
	{
		MessageBox::Show(L"ÉGÉâÅ[", L"ì«Ç›çûÇ›Ç…é∏îsÇµÇ‹ÇµÇΩÅB");
		return;
	}

}
void CFloor::Update()
{

}
void CFloor::Draw()
{
	Box(Pos, Size).draw(TextureAsset(L"Floor"));
}
