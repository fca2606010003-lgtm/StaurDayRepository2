#include"Game.h"
#include"DxLib.h"
#include"Config.h"
Game::Game()
{
	nowCount = 0;
	prevCount = 0;
}

Game::~Game()
{
	DxLib_End;
}

//

bool Game::Init()
{
	ChangeWindowMode(TRUE);

	SetGraphMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT,Config::COLOR_BIT);

	if (DxLib_Init() == -1)
	{
		return false;
	}

	//player

	if (!player.Init())
	{
		return false;
	}

	//Map

	if (!map.Init())
	{
		return false;
	}

	//

	nowCount = GetNowCount();
	prevCount = nowCount;

	return true;
}

//ゲームループ

void Game::Run()
{
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//DeltaTime

		nowCount = GetNowCount();

		float deltaTime = (nowCount - prevCount) / 1000.0f;

		//

		Update(deltaTime);

		//

		ClearDrawScreen();

		Draw();

		ScreenFlip();
		
		prevCount = nowCount;
	}
}

//更新

void Game::Update(float deltaTime)
{
	player.Update(deltaTime);
}

//

void Game::Draw()
{
	map.Draw();

	player.Draw();
}