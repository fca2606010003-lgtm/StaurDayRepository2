#include "Camera.h"
#include"DxLib.h"
#include"config.h"

//
//
//
Camera::Camera()
{
	x = 0.0f;
}

//
//
//
void Camera::Update()
{
	//
	if (CheckHitKey(KEY_INPUT_A))
	{
		x -= GameConst::CAMERA_SPEED;
	}
	//
	if (CheckHitKey(KEY_INPUT_D))
	{
		x += GameConst::CAMERA_SPEED;
	}
	//
	if (x < 0) { x = 0; }
	if (x > GameConst::SCREEN_WINDTH) { x = GameConst::SCREEN_WINDTH;}
}
float Camera::GatX()const