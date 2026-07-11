#include"Animation.h"

Animation::Animation()
{
	images = nullptr;
	startFrame = 0;
	speed = 10;
	startTime = 0;


}
//分割画像設定
void Animation::SetImages(int* img)
{
	//分割の画像を読み込み
	images = img;
}
//アニメーション再生
void Animation::Play(int start, int frame, int spd)
{
	//アニメーションの開始位置設定
	startFrame = start;
	//再生するフレーム数を設定
	frameCount = frame;
	//アニメーション速度を設定
	speed = spd;
}
//現在描画する画像設定
int Animation::GetImage(int currentTime)
{
	//アニメーション番号計算
	int fram = (currentTime / speed) % frameCount;
	return images[startFrame + fram];
}