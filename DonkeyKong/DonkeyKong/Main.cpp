
# include <Siv3D.hpp>

#include "Stage.h"

void Main()
{
	Stage *stage = new Stage();

	//	���C�g�̐ݒ�
	Graphics::SetLight(0,Light::Directional(Vec3(0,1,-1)));


	while (System::Update())
	{
		stage->Update();
	}
}
