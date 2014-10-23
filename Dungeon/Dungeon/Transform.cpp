#include "Transform.h"


Transform::Transform(Point pos, Point scale, Point rotation) :
pos(pos), scale(scale), rotation(rotation)
{

}

///	平行移動
void Transform::Translate(const Point &value)
{
	pos += value;
}

///	指定座標に変換
void Transform::TransformPoint(const Point &value)
{
	pos = value;
}

///	回転軸を移動
void Transform::Rotaion(const Point &value)
{
	rotation += value;
}

///	指定軸に変換
void Transform::LookAt(const Point &value)
{
	rotation = value;
}

///	スケールを大きくする
void Transform::Scaling(const Point &value)
{
	scale += value;
}

///	指定スケールに変換
void Transform::TransformScale(const Point &value)
{
	scale = value;
}
