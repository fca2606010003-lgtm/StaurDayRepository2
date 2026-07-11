#include"FrameManager.h"
//=================
//コンストラクタ
//=================
FrameManager::FrameManager()
{
	frameCounter = 0;
}
//=====================
//更新
//======================
void FrameManager::Update()
{
	frameCounter++;
}
//========================--
//現在フレーム取得
//===========================
int FrameManager::GetFrameCounter()const
{
	//フレームカウンターを返す
	return frameCounter;
}