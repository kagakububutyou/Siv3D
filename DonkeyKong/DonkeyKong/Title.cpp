#include "Title.h"
#include "Stage.h"


CTitle::CTitle()
{
	Logo.reset(new Font(50, Typeface::Default));
	Text.reset(new Font(20, Typeface::Default));
}


void CTitle::Draw()
{
	
	const String title = L"ÇΩÇ¢Ç∆ÇÈ";

	Logo->drawCenter(title, Vec2(Stage::Width / 2, Stage::Height / 3), Color(255, 255, 255));

	const String text = L"PushÅ@Enter";

	static int i = 0;

	i++;
	if (i % 60 <= 30)
	{
		Text->drawCenter(text, Vec2(Stage::Width / 2, Stage::Height * 2 / 3), Color(255, 255, 255));
	}
}