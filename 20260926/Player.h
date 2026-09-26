#pragma once
#include "Collision.h"

class Player {
private:
	//プレイヤーの位置
	float x;
	float y;

	//プレイヤーの移動速度
	float velocityX;
	float velocityY;

	//ジャンプフラグ
	bool isJumping;

	//プレイヤーの当たり判定
	Collision collision;

	//足元の当たり判定
	Collision footCollision;

	//頭の当たり判定
	Collision headCollisoin;

	
public:
	Player();
	~Player();

	//初期化
	void Init();
	//更新
	void UpDate();
	//描画
	void Drow();
	//マップとの衝突距離
	void 
	
};