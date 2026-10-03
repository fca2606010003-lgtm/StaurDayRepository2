#pragma once

#include"Collision.h"

class Player
{
private:

	//座標

	float x;
	float y;

	//速度

	float velocityX;
	float velocityY;

	//ジャンプ
	bool jumpFlag;
	bool groundFlag;
	bool headHitFlag;
	//ジャンプキー
	bool previousJump;
	//アニメーション

	float animationTimer;

	int animationType;
	int animationPattern;

	//描画位置補正

	int drawOffsetX;
	int drawOffsetY;

	//player画像

	int playerImg[3 * 4];

	Collision collision;
	Collision footCollision;
	Collision headCollision;
public:

	void Init();
	void Update(float deltaTime);

	void Draw();
	void Finelize();

	Collision GetCollision()const;

	Collision GetFootCollision()const;

	Collision GetHeadCollision()const;
	
	void FixCollision(const Collision& collision);

	void SetGraund(bool ground);

	void SetHeadHit(bool hit);

private:
	void Move(float deltaTime);
};