#include"Map.h"
#include"DxLib.h"
#include"Config.h"


//Map::Map()
//{
//	for (int i = 0; i < Config::MAP_IMG_X_NUM * Config::MAP_IMG_Y_NUM; i++)
//	{
//		mapChipImg[i] = -1;
//	}
//}
//
////
//
//Map::~Map()
//{
//	for (int i = 0; i < Config::MAP_IMG_X_NUM * Config::MAP_IMG_Y_NUM; i++)
//	{
//		if (mapChipImg[i] != -1)
//		{
//			DeleteGraph(mapChipImg[i]);
//
//			mapChipImg[i] = -1;
//		}
//	}
//}

//‰Šú‰»

namespace 
{
	const unsigned char mapData
		[Config::MAP_IMG_Y_NUM]
		[Config::MAP_IMG_X_NUM]
		=
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
		{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},
		{1,0,0,1,1,1,0,0,0,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
}

bool Map::Init()
{
	LoadDivGraph(
		"ing/map.png",
		Config::MAP_IMG_X_NUM * Config::MAP_IMG_Y_NUM,
		Config::MAP_IMG_X_NUM, Config::MAP_IMG_Y_NUM,
		Config::MAP_CHIP_SIZE,
		Config::MAP_CHIP_SIZE,
		mapChipImg
	);

}

//

void Map::Draw()
{
	for (
		int y = 0;
		y < Config::MAP_Y_NUM;
		y++)
	{
		for (int x = 0; 
			x < Config::MAP_X_NUM; 
			x++)
		{
			int index = mapData[y][x];


			DrawGraph(x * Config::MAP_CHIP_SIZE, y * Config::MAP_CHIP_SIZE, mapChipImg[index], TRUE);
		}
	}
}

void Map::Finalize()
{
	for (int i = 0; i < Config::MAP_IMG_X_NUM * Config::MAP_IMG_Y_NUM; i++)
	{
		DeleteGraph(mapChipImg[i]);
	}
}

bool Map::CheckCollision(Collision& player)
{
	bool hit = false;
	for (int y = 0; y < Config::MAP_IMG_Y_NUM; y++)
	{
		for (int x = 0; x < Config::MAP_IMG_X_NUM; x++)
		{
			if (mapData[y][x] == 0)
			{
				continue;
			}

			Collision block;

			block.Init(Config::MAP_CHIP_SIZE, Config::MAP_CHIP_SIZE);

			block.SetPosition(x * Config::MAP_CHIP_SIZE, y * Config::MAP_CHIP_SIZE);

			if (player.IsHit(block))
			{
				player.FixPosition(block);
				hit = true;
			}
		}
	}
}