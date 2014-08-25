
# include <Siv3D.hpp>

#include "Stage.h"
/*

		メイン	

*/

void Main()
{
	stage = new Stage();

	Window::Resize(Stage::Width, Stage::Height);

	//	ライトの設定
	Graphics::SetLight(0, Light::Directional(Vec3(0, 1, -1)));
	//	座標,、どこ見るか、角度、ズーム、どっからどこまで見るか
	//		16
	Graphics::SetCamera(Camera(Vec3(0, Stage::Height / 2 - 16, -512), Vec3(0, Stage::Height / 2 - 16, 0), Vec3(0, 1, 0), 47.5, 100, 10000));
	//		8
	//Graphics::SetCamera(Camera(Vec3(0, 0, -512), Vec3(0, Stage::Height / 4, 0), Vec3(0, 1, 0), 27.5, 100, 10000));

	while (System::Update())
	{
		stage->GameMain();
	}
}
