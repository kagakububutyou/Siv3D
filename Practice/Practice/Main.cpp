
# include <Siv3D.hpp>

/*
		�����`��`��
*/

void Main()
{
	while (System::Update())
	{
		//	���W(50, 100)	����	��	400	����	200�̒����`��`��
		Rect(50, 100, 400, 200).draw();
	}
}
