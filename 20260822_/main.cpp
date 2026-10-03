#include<windows.h>
#include"Dxlib.h"
#include"Config.h"
#include"Player.h"
#include"Map.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);

	SetGraphMode(Config::WINDOW_HEIGHT, Config::WINDOW_HEIGHT, Config::COLOR_BIT);

	if (!DxLib_Init()==-1)
	{
		return -1;
	}

	Player player;
	Map map;

	player.Init();
	map.Init();

	int previousTime = GetNowCount();

	while (ProcessMessage() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		int currentTime = GetNowCount();
		float deltaTime = (currentTime - previousTime) / 1000.0f;

		previousTime = currentTime;

		//çXêV
		player.Update(deltaTime);

		//playerñ{ëÃ
		Collision playerCollision = player.GetCollision();
		if (map.CheckCollision(playerCollision))
		{
			player.FixCollision(playerCollision);
		}

		Collision foot = player.GetFootCollision();

		player.SetGround(map.CheckCollision(foot));

		Collision head = player.GetHeadCollison();

		player.SetHeadHit(map.CheckCollsion(head));

		//ï`âÊ
		clearDrawScreen();

		map.Draw();

		player.Draw();

		ScreenFlip();

	}
	player.Finalize();
	map.Finalize();

	DxLib_End();

	return 0;
}