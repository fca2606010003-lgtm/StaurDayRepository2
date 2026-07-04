#include "Map.h"
#include"DxLib.h"

//
//
//
Map::Map(float x, float y)
{
	worldX = x;
	worldY = y;
}
//
//
//
void Map::Draw(float cameraX)
{
	//
	//
	//
	DrawBox((int)localX, (int)worldY, (int)localX + 32, (int)worldY + 32, GetColor(0, 255, 0), TRUE);

	DrawFormatString((int)localX, (int)worldY - 20, GetColor(255, 255, 255), "W:%.0f", worldX);
}