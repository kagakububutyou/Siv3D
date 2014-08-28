#include "Floor.h"
/*

		鉄骨

*/

CFloor::CFloor(Float3 pos, Float3 size)
{
	Pos = pos;
	Size = size;
	color = Color(231, 0, 91);

	if (!TextureAsset(L"Floor"))
	{
		//MessageBox::Show(L"エラー", L"読み込みに失敗しました。");
		TextureAsset::Register(L"Floor", L"engine/Texture/floor.png");
		return;
	}

}
void CFloor::Draw()
{
	Box(Pos, Size).draw(TextureAsset(L"Floor"));
}
