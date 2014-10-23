// ------------------------------------------------
//			ライト処理
//					code by shinnnosuke hiratsuka
// ------------------------------------------------
#include "Light.h"

CLight::CLight(int id, Type type, Point pos, float radius, ColorF color) :
id(id), type(type), Transform(pos, Point(0, 0, 0), Point(0, 0, 0)), radius(radius), color(color)
{

}

void CLight::Directional()
{
	if (type != Type::Directional) return;

	Graphics::SetLight(id, Light::Directional(GetPos(), color));
}

void CLight::Point()
{
	if (type != Type::Point) return;

	Graphics::SetLight(id, Light::Point(GetPos(), radius, color));
}

///	アップデート
void CLight::Update()
{
	Directional();
	Point();
}