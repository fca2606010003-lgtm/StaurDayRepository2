#pragma once
#include"Collision.h"

class Map
{
private:

	int mapChipImg[2];

public:
	//
	bool Init();
	//
    void Draw();
	//
	void Finalize();
	//
	bool CheckCollision(Collision& collision);
};