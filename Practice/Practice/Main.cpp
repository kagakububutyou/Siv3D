
# include <Siv3D.hpp>

/*
		ƒJƒ‰ƒtƒ‹‚È‰~
*/

void Main()
{
	Graphics::SetBackground(Palette::White);

	while (System::Update())
	{
		for (int i = 0; i<36; i++)
		{
			const double radian = Radians(i*10.0 + System::FrameCount());

			const Vec2 pos = Vec2(Sin(radian), -Cos(radian)) * 200 + Vec2(320, 240);

			RectF(25, 25).setCenter(pos).rotate(radian).draw(HSV(i * 10));
		}
	}
}
