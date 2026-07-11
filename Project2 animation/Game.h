#pragma once

#include"Config.h"
#include"Animation.h"
#include"Animationtype.h"
#include"FrameManager.h"

class Game 
{
private:
	FrameManager framemanager;

	Animation animations;

	int images[Config::PLAYER_TOTAL_FRAMES];

	AnimationType currentAnim;

	bool oldSpace;

	void PlayerAnimation(AnimationType type);

public:
	void Init();

	void Update();

	void Draw();
};