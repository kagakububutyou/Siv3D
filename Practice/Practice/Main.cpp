
# include <Siv3D.hpp>

/*
		��������
*/

void Main()
{
	while (System::Update())
	{
		//	�n�_(50,200)	����	(600,250)	�̐�
		Line({ 50, 200 }, { 600, 250 }).draw();
	}
}
