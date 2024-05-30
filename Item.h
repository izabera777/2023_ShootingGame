#pragma once

// 定数
#define ITEM_SPEED		3	// アイテムの移動速度
#define ITEM_RAND_MAX	2	// アイテムの種類

// 種類
enum ItemType
{
	MULTI_SHOT,		// 3WAYショット
	BOM,			// ボム
	MEDICAL_KIT,	// 回復
	MISSILE			// ミサイル
};


// プロトタイプ宣言
struct GameObject;

// ３WAYショット用
struct ItemMultiShot
{
	GameObject obj;
};

// ボム
struct ItemBom
{
	GameObject obj;
};

// 回復
struct ItemMedicalKits
{
	GameObject obj;
};

// ミサイル
struct ItemMissile
{
	GameObject obj;
};



// アイテム
struct Item
{
	ItemMultiShot		multiShot;		// ３WAYショット
	ItemBom				bom;			// ボム
	ItemMedicalKits		medicalKits;	// 回復パック
	ItemMissile			missile;		// ミサイル
};


// 関数プロトタイプ宣言

/// <summary>
/// アイテムの初期化
/// </summary>
/// <param name="item">アイテム構造体</param>
void InitItem(Item& item);

/// <summary>
/// アイテムとプレイヤーの当たり判定
/// </summary>
/// <param name="item">アイテム構造体</param>
/// <param name="target">プレイヤー構造体</param>
/// <returns>当たったか、当たってないか</returns>
bool IsHitObject(GameObject& item, GameObject& target, Sound& sound);

/// <summary>
/// アイテムの移動
/// </summary>
/// <param name="obj">アイテム構造体</param>
void MoveItem(GameObject& obj);

void UpdateItem(Game& game);


/// <summary>
/// アイテムの描画
/// </summary>
/// <param name="item">アイテム構造体</param>
void DrawItem(Item& item);











