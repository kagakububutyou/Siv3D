#include "Floor.h"
/*

		�S��

*/

CFloor::CFloor(Float3 pos, Float3 size)
{
	Pos = pos;
	Size = size;
	color = Color(231, 0, 91);

	if (!TextureAsset(L"Floor"))
	{
		//MessageBox::Show(L"�G���[", L"�ǂݍ��݂Ɏ��s���܂����B");
		TextureAsset::Register(L"Floor", L"engine/Texture/floor.png");
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
