/*

@author shinnnosuke hiratsuka
@date 2014.10.09

*/
#pragma once
#include "Actor.h"


class CMapRead
{
public:

	CMapRead();

	void ObjectRead(const Point index, const int type, std::shared_ptr<CActor> actor, std::shared_ptr<CActor> constructor);

	static const int Width = 40;
	static const int Height = 8;
	static const int Size = 100;

private:
	void WidthRead(TextReader &reader, const int y);
	void HeightRead(TextReader &reader);
	void ReadUpdate(TextReader &reader, const int x ,const int y);

	int MapDate[Height][Width];
	String map_str;
};