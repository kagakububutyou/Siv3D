/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
# include <Siv3D.hpp>

void Main()
{
	const Font font(30);

	while (System::Update())
	{
		font(L"�悤�����ASiv3D �̐��E�ցI").draw();

		Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
	}
}
