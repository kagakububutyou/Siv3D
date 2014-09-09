#include "Clear.h"
#include "Stage.h"

CClear::CClear()
{
	Logo.reset(new Font(50, Typeface::Default));
	Text.reset(new Font(20, Typeface::Default));
}

void CClear::Draw()
{
	const String clear = L"‚­‚è‚ ";

	Logo->drawCenter(clear, Vec2(Stage::Width / 2, Stage::Height / 3), Color(255, 255, 255));

	const String text = L"‚¨‚ß‚Å‚Æ‚¤";

	static int i = 0;

	i++;
	if (i % 60 <= 30)
	{
		Text->drawCenter(text, Vec2(Stage::Width / 2, Stage::Height * 2 / 3), Color(255, 255, 255));
	}
}