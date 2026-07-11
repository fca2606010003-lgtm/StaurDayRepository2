#include"Game.h"
#include"DxLib.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	/*ウインドウの初期化処理*/
	ChangeWindowMode(TRUE);
	SetGraphMode(640, 480, 32);
	//初期化に失敗時にエラーを吐かせて終了
	if (DxLib_Init() == 1) return -1;
	/*Initialize*/
	while (ProcessMessage() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();//裏画面消す

		game.Update();

		game.Draw();
		/*Update*/
		/*Render*/
		ScreenFlip();//裏画面を表画面にコピー
	}
	/*Finalize*/
	DxLib_End();
	return 0;
}
