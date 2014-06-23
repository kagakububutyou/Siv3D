
# include <Siv3D.hpp>

/*
		ü‚ğ‘‚­
*/

void Main()
{
	while (System::Update())
	{
		//	n“_(50,200)	‚©‚ç	(600,250)	‚Ìü
		Line({ 50, 200 }, { 600, 250 }).draw();
	}
}
