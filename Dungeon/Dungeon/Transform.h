/*
	
	@author shinnnosuke hiratsuka
	@date 2014.10.02

*/
#pragma once
#include <Siv3D.hpp>

///	���W�A�傫���A��]
class Transform
{
public:
	Transform(Point pos,Point scale, Point rotation);

	Point GetPos() const { return pos; }
	Point GetRotation()const{ return rotation; }
	Point GetScale() const{ return scale; }

	///	���W���s�ړ�
	void Translate(const Point &value);

	///	�w��ʒu�ɕϊ�
	void TransformPoint(const Point &value);

	///	��]�����ړ�
	void Rotaion(const Point &value);

	///	�w�莲�ɕϊ�
	void LookAt(const Point &value);

	///	�X�P�[����傫������
	void Scaling(const Point &value);

	///	�w��X�P�[���ɕϊ�
	void TransformScale(const Point &value);

private:
	Point pos;
	Point scale;
	Point rotation;
};