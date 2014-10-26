#include "Transform.h"


Transform::Transform(Point pos, Point scale, Point rotation) :
pos(pos), scale(scale), rotation(rotation)
{

}

///	���s�ړ�
void Transform::Translate(const Point &value)
{
	pos += value;
}

///	�w����W�ɕϊ�
void Transform::TransformPoint(const Point &value)
{
	pos = value;
}

///	��]�����ړ�
void Transform::Rotaion(const Point &value)
{
	rotation += value;
}

///	�w�莲�ɕϊ�
void Transform::LookAt(const Point &value)
{
	rotation = value;
}

///	�X�P�[����傫������
void Transform::Scaling(const Point &value)
{
	scale += value;
}

///	�w��X�P�[���ɕϊ�
void Transform::TransformScale(const Point &value)
{
	scale = value;
}
