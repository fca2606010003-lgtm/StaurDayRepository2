#pragma once
#include<vector>
#include<string>
using namespace std;

class Map
{
private:
	//マップチップ番号
	vector<vector<int>>mapData;
	//当たり判定の情報
	vector<vector<int>>hitData;

	//マップチップの画像
	int chipImage[64];

	//マップの縦横のますの数
	int mapWidth;
	int apHeight;

	//マップの大きさ
	static constexpr int CHIP_SIZE = 64;

	//csvファイルのよみっこみ
	bool LoadCSV(const char* fileName, vector<vector<int>>& data);
public:
	Map();

	/// <summary>
	/// 初期化
	/// </summary>
	/// <returns>読み込み不正</returns>
	bool Init();

	/// <summary>
	/// マップの描画
	/// </summary>
	/// <param name="cameraX">カメラ座標</param>
	/// <param name="cameraY">カメラ座標</param>
	void Draw(float cameraX, float cameraY);
	
	/// <summary>
	/// 通行できるか調べる
	/// </summary>
	/// <param name="tileX">タイル座標X</param>
	/// <param name="tileY">タイル座標Y</param>
	/// <returns>通過可能</returns>
	bool isSolid(int tileX, int tileY);
	/// <summary>
	/// ワールド座標から当たり判定を調べる
	/// </summary>
	/// <param name="worldX">ワールド座標X</param>
	/// <param name="worldY">ワールド座標Y</param>
	/// <returns>ワールド座標当たり判定</returns>
	bool IsSolidAt(float worldX, float worldY);
};