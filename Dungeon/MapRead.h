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

	static const int Width = 109;
	static const int Height = 50;
	static const int Size = 64;

	static const int Floor = 1;						///	��
	static const int PlayerPosition = 2;			///	�v���C���[�̈ʒu
	static const int StaircasePosition = PlayerPosition;	///	�K�i�̈ʒu
	

private:
	void WidthRead(TextReader &reader, const int y);
	void HeightRead(TextReader &reader);
	void ReadUpdate(TextReader &reader, const int x ,const int y);

	int MapDate[Height][Width];
	String map_str;
};