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

	static const int Width = 50;
	static const int Height = 30;
	static const int Size = 128;

	static const int OutsideMap = 0;				///	マップ外
	static const int Corridor = 1;					///	廊下
	static const int Room = 2;						///	部屋
	static const int Wall = 3;							///	壁
	static const int UpStairsPosition = 4;		///	上り階段の位置
	static const int PlayerPosition = 5;			///	プレイヤーの位置
	static const int DownStairsPosition = 5;	///	下り階段の位置

	static const int SwitchWallPosition = 20;
	static const int SwitchWall1Position = 21;
	static const int SwitchWall2Position = 22;
	static const int SwitchWall3Position = 23;
	

private:
	void WidthRead(TextReader &reader, const int y);
	void HeightRead(TextReader &reader);
	void ReadUpdate(TextReader &reader, const int x ,const int y);

	int MapDate[Height][Width];
	String map_str;
};