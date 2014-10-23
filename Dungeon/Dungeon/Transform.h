/*
	
	@author shinnnosuke hiratsuka
	@date 2014.10.02

*/
#pragma once
#include <Siv3D.hpp>

///	座標、大きさ、回転
class Transform
{
public:
	Transform(Point pos,Point scale, Point rotation);

	Point GetPos() const { return pos; }
	Point GetRotation()const{ return rotation; }
	Point GetScale() const{ return scale; }

	///	座標平行移動
	void Translate(const Point &value);

	///	指定位置に変換
	void TransformPoint(const Point &value);

	///	回転軸を移動
	void Rotaion(const Point &value);

	///	指定軸に変換
	void LookAt(const Point &value);

	///	スケールを大きくする
	void Scaling(const Point &value);

	///	指定スケールに変換
	void TransformScale(const Point &value);

private:
	Point pos;
	Point scale;
	Point rotation;
};