/*

@author shinnnosuke hiratsuka
@date 2014.10.26

*/

#pragma once
#include "Actor.h"

class CMiniMapPlayer :public CActor
{
public:
	CMiniMapPlayer(std::shared_ptr<CTask> task, Point pos);

	void Start();		///	‰‚ß‚ÉŒÄ‚ÔŠÖ”
	void Update();		///	–ˆƒtƒŒ[ƒ€ŒÄ‚ÔŠÖ”
	void Draw();		///	•`‰æŠÖŒW‚ÌŠÖ”

private:
};