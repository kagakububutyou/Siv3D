
# include <Siv3D.hpp>

/*
		線を書く
*/

void Main()
{
	while (System::Update())
	{
		//	始点(50,200)	から	(600,250)	の線
		Line({ 50, 200 }, { 600, 250 }).draw();
	}
}
