
# include <Siv3D.hpp>

/*
		長方形を描く
*/

void Main()
{
	while (System::Update())
	{
		//	座標(50, 100)	から	幅	400	高さ	200の長方形を描く
		Rect(50, 100, 400, 200).draw();
	}
}
