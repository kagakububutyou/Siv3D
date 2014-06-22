
# include <Siv3D.hpp>

void Main()
{
		//		フォントサイズ
		const Font font(30);

		//		メインループ
		while (System::Update())
		{
			//		文字描画
			font(L"ようこそ、Siv3D の世界へ！").draw();

			//		マウス座標を中心に半径50の紅色の半透明の円の描画
			Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
		}
}
