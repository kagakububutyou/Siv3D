// ------------------------------------------------
//			カメラの処理
//					code by shinnnnosuke hiratsuka
// ------------------------------------------------
#include "Camera.h"

const float CCamera::Near = 100.0f;		///	見える近い範囲
const float CCamera::Far = 5000.0f;		///	見える遠い範囲
const float CCamera::degree = 45.0f;		///	ズーム
const float CCamera::Speed = 5.0f;		///	速度

CCamera::CCamera(Float3 pos, Float3 lookat) :
upvec(Vec3(0, 1, 0)),
Transform(pos, Float3(0, 0, 0), lookat)
{

}

// -----------------------------------
//　アップデート
// -----------------------------------
void CCamera::Update()
{
	Graphics::SetCamera(Camera(GetPos(), GetRotation(), upvec, degree, Near, Far));
}