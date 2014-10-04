#include "Transform.h"


Transform::Transform(Float3 pos, Float3 scale, Float3 rotation) :
pos(pos), scale(scale), rotation(rotation)
{

}

///	平行移動
void Transform::Translate(const Float3 &value)
{
	pos += value;
}

///	指定座標に変換
void Transform::TransformPoint(const Float3 &value)
{
	pos = value;
}

///	回転軸を移動
void Transform::Rotaion(const Float3 &value)
{
	rotation += value;
}

///	指定軸に変換
void Transform::LookAt(const Float3 &value)
{
	rotation = value;
}

///	スケールを大きくする
void Transform::Scaling(const Float3 &value)
{
	scale += value;
}

///	指定スケールに変換
void Transform::TransformScale(const Float3 &value)
{
	scale = value;
}
