#include "Game.h"
#include"Config.h"
#include"DxLib.h"
void Game::Init()
{
	circle.Init();
	sphere.Init();

	//3DƒJƒƒ‰İ’è
	SetCameraNearFar(Config::CAMERA_NEAR, Config::CAMERA_FAR);

	//“Š‘“Š‰e‚Ìİ’èi‹–ìŠp‚U‚O“xj
	SetupCamera_Perspective(Config::PI / 30.0f);

	//ƒJƒƒ‰‚ÌˆÊ’u‚Æ’ˆÓ“_
	VECTOR cameraTarget = VGet(0.0f, 0.0f, Config::CAMERA_TARGET_Z);

	VECTOR cameraPosition = VGet(0.0f, 0.0f, Config::CAMERA_TARGET_Z);

	SetCameraPositionAndTarget_UpVecY(cameraPosition,cameraTarget);
}

void Game::Update(float deltaTime)
{
	circle.Updata(deltaTime);
	sphere.Updata(deltaTime);
}

void Game::Draw()
{
	//2D‚Ì‰~‚ğ•`‰æ
	circle.Draw();
	//3D‚Ì‹…‚ğ•`‰æ
	sphere.Draw();
}

void Game::Reset()
{
	circle.Reset();
	sphere.Reset();
}