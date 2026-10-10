#include<iostream>
using namespace std;
class Player
{
public:
	int hp = 100;
	void Damage()
	{
		hp - 10;
	}
};

class Enemy
{
public:
	Player ply;
	Player* pPly = &ply;

};

int main(void)
{
	Player player;
	cout << "Player:HP" << player.hp << endl;

	Player* pPLayer = &player;

	pPLayer->Damage();

	cout << "Player:HP" <<player.hp << endl;
}