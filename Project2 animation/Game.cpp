#include"Game.h"
#include"Config.h"
#include"DxLib.h"

void Game::Init()
{
	//分割画像の読み込み
	LoadDivGraph("img/AnimationPlayer1.png",
		Config::PLAYER_TOTAL_FRAMES,
		Config::PLAYER_COL,
		Config::PLAYER_COL,
		Config::PLAYER_WIDTH,
		Config::PLAYER_HEIGHT,
		images);
	//アニメーションに分割画像を設定
	animations.SetImages(images);

	currentAnim = AnimationType::Idle;
	PlayerAnimation(currentAnim);
	oldSpace = false;
}

void Game::Draw()
{
	DrawGraph(Config::PLAYER_DRAW_X,
		Config::PLAYER_DRAW_Y,
		animation.getImage(frameManager.GetFrameCounter()),
		TRUE);

	DrawFormatString(
		20, 20, GetColor(255, 255, 255),
		"Frame : %d",
		frameManager.GetFrameCounter());
}

void Game::Update()
{
	//フレームマネージャー更新
	frameManager.Update();
	//スペースキーの押下判定
	bool nowSpace = (CheckHitKey(KEY_INPUT_SPACE));


	if (nowSpace && !oldSpace)
	{
		switch (currentAnim)
		{
		case AnimationType::Idle:
				currentAnim = AnimationType::Walk;
				break;
		case AnimationType::Walk:

		}
	}
}