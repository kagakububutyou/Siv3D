// ------------------------------------------------
//			�J�����̏���
//					code by shinnnnosuke hiratsuka
// ------------------------------------------------
#include "Camera.h"
#include "Scene.h"

#include "Actor.h"
const float CCamera::Near = 100.0f;		///	������߂��͈�
const float CCamera::Far = 5000.0f;		///	�����鉓���͈�
const float CCamera::degree = 45.0f;		///	�Y�[��
const float CCamera::Speed = 5.0f;		///	���x

CCamera::CCamera(Point pos, Point lookat) :
upvec(Vec3(0, 1, 0)),
Transform(pos, Point(0, 0), lookat)
{

}

// -----------------------------------
//�@�A�b�v�f�[�g
// -----------------------------------
void CCamera::Update()
{
	Graphics::SetCamera(Camera(GetPos(), GetRotation(), upvec, degree, Near, Far));
}