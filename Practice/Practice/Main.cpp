
# include <Siv3D.hpp>

void Main()
{
		//		�t�H���g�T�C�Y
		const Font font(30);

		//		���C�����[�v
		while (System::Update())
		{
			//		�����`��
			font(L"�悤�����ASiv3D �̐��E�ցI").draw();

			//		�}�E�X���W�𒆐S�ɔ��a50�̍g�F�̔������̉~�̕`��
			Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
		}
}
