/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once

///	仮想コントローラー
class CharacterController
{
public:
	static bool LeftMoveKey();
	static bool RightMoveKey();
	static bool UpMoveKey();
	static bool DownMoveKey();
	static bool ChangeSceneKey();
	static bool DisplayMiniMapKey();

};