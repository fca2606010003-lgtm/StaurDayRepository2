#include"Game.h"
#include"Config.h"
#include"DxLib.h"

void Game;;Init()
{
	LoadDivGraph("img/AnimationPlayer1.png",
		Config::PLAYER_TOTAL_FRAMES,
		Config::PLAYER_COL,
		Config::PLAYER_COL,
		Config::PLAYER_WIDTH,
		Config::PLAYER_HEIGHT,
		images);

	animations.SetImages(images);

	currentAnim = AnimationType::Idle;
	PlayerAnimation(currentAnim);
	oldSpace = false;
}