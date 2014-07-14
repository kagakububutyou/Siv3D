
# include <Siv3D.hpp>

#include "Stage.h"

void Main()
{
	stage = new Stage();

	Window::Resize(Stage::Width, Stage::Height);

	//	ライトの設定
	Graphics::SetLight(0, Light::Directional(Vec3(0, 1, -1)));
	//	座標,、どこ見るか、角度、ズーム、どっからどこまで見るか
	Graphics::SetCamera(Camera(Vec3(0,0,-512),Vec3(0,0,0),Vec3(0,1,0),45,100,10000));


	while (System::Update())
	{
		stage->Update();
	}
}
