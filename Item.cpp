#include "Utility.h"
#include "DxLib.h"
#include "GameObject.h"
#include "UI.h"
#include "Shot.h"
#include "Player.h"
#include "Enemy.h"
#include "BG.h"
#include "Menu.h"
#include "Sound.h"
#include "Item.h"
#include "Game.h"


// アイテム初期化
void InitItem(Item& item)
{
	// 画像のロード,サイズの取得

	// ３WAYショット用
	if (item.multiShot.obj.graph < 0)
	{
		// 画像のロード
		item.multiShot.obj.graph = LoadGraph("data/texture/MultiShot.png");
		GetGraphSize(item.multiShot.obj.graph, &item.multiShot.obj.w, &item.multiShot.obj.h);
		// ステータス情報
		item.multiShot.obj.visibleFlag = false;
		item.multiShot.obj.angle = 0;
		item.multiShot.obj.speed = ITEM_SPEED;
	}
	// ボム
	if (item.bom.obj.graph < 0)
	{
		item.bom.obj.graph = LoadGraph("data/texture/Bom.png");
		GetGraphSize(item.bom.obj.graph, &item.bom.obj.w, &item.bom.obj.h);
		item.bom.obj.visibleFlag = false;
		item.bom.obj.angle = 0;
		item.bom.obj.speed = ITEM_SPEED;
	}
	// 回復パック
	if (item.medicalKits.obj.graph < 0)
	{
		item.medicalKits.obj.graph = LoadGraph("data/texture/Medical.png");
		GetGraphSize(item.medicalKits.obj.graph, &item.medicalKits.obj.w, &item.medicalKits.obj.h);
		item.medicalKits.obj.visibleFlag = false;
		item.medicalKits.obj.angle = 0;
		item.medicalKits.obj.speed = ITEM_SPEED;
	}
	// ミサイル
	if (item.missile.obj.graph < 0)
	{
		item.missile.obj.graph = LoadGraph("data/texture/Missile.png");
		GetGraphSize(item.missile.obj.graph, &item.medicalKits.obj.w, &item.medicalKits.obj.h);
		item.missile.obj.visibleFlag = true;
		item.missile.obj.angle = 0;
		item.missile.obj.speed = ITEM_SPEED;
	}


}

// アイテムとプレイヤーの当たり判定
bool IsHitObject(GameObject& item, GameObject& target,Sound& sound)
{
	// 当たったか、当たってないか
	bool isHit = false;

	// アイテムの当たり判定
	if (item.visibleFlag == 1)
	{
		// バフ分の当たり判定を持つ
		float itemLeft		= item.pos.x   - item.w   * OBJECT_HIT_BUF;
		float itemRight		= item.pos.x   + item.w   * OBJECT_HIT_BUF;
		float itemTop		= item.pos.y   - item.h   * OBJECT_HIT_BUF;
		float itemBottom	= item.pos.y   + item.h   * OBJECT_HIT_BUF;
		float targetLeft	= target.pos.x - target.w * OBJECT_HIT_BUF;
		float targetRight	= target.pos.x + target.w * OBJECT_HIT_BUF;
		float targetTop		= target.pos.y - target.h * OBJECT_HIT_BUF;
		float targetBottmo	= target.pos.y + target.h;

		// 当たり判定
		if (((itemLeft  > targetLeft && itemLeft   < targetRight ) ||
			(targetLeft > itemLeft   && targetLeft < itemRight  )) &&
			((itemTop   > targetTop  && itemTop    < targetBottmo) ||
			(targetTop  > itemTop    && targetTop  < itemBottom)))
		{
			// 当たった時の効果音を出す
			PlaySoundMem(sound.itemGetSE, DX_PLAYTYPE_BACK, true);

			// 接触している場合は当たったアイテムの存在を消す
			item.visibleFlag = 0;

			// 当たっているフラグを立てる
			isHit = true;
		}
	}

	// 当たったか、当たってないか
	return isHit;
}


// アイテムの移動
void MoveItem(GameObject& obj)
{
	// アイテムの移動ルーチン（存在している変数がtrueのみ行う）
	if (obj.visibleFlag == true)
	{
		// アイテムを移動させる
		MoveGameObject(obj);

		// 画面の外に出てしまった場合は存在状態を保持している変数にfalseを代入
		if (   obj.pos.y < 0        - obj.h * 0.5f
			|| obj.pos.y > SCREEN_H + obj.h * 0.5f
			|| obj.pos.x < 0        - obj.w * 0.5f
			|| obj.pos.x > SCREEN_W + obj.w * 0.5f)
		{
			obj.visibleFlag = false;
		}
	}
}

// アップデートアイテム
void UpdateItem(Game& game)
{
	// アイテムの移動
	MoveItem(game.item.multiShot.obj);		// ３WAYショット
	MoveItem(game.item.bom.obj);			// ボム
	MoveItem(game.item.medicalKits.obj);	// 回復パック
	MoveItem(game.item.missile.obj);		// ミサイル

	// アイテムの当たり判定
	// マルチショット
	if (IsHitObject(game.item.multiShot.obj, game.player.obj, game.sound))
	{
		game.player.itemStatus = MULTI_SHOT;
	}

	// ボム
	if (IsHitObject(game.item.bom.obj, game.player.obj, game.sound))
	{
		game.player.bomCount++;
	}

	// 回復パック
	if (IsHitObject(game.item.medicalKits.obj, game.player.obj, game.sound) && game.player.life <= 29)
	{
		game.player.life += 7;
		// プレイヤーのライフ上限を超えたら
		if (game.player.life >= 29)
		{
			game.player.life = 29;
		}
	}

	// ミサイル
	if (IsHitObject(game.item.missile.obj, game.player.obj, game.sound))
	{
		game.player.itemStatus = MISSILE;
	}



}


// 描画
void DrawItem(Item& item)
{
	// ３WAYショット
	if (item.multiShot.obj.visibleFlag == true)
	{
		DrawGameObject(item.multiShot.obj, item.multiShot.obj.graph);
	}
	// ボム
	if (item.bom.obj.visibleFlag == true)
	{
		DrawGameObject(item.bom.obj, item.bom.obj.graph);
	}
	// 回復パック
	if (item.medicalKits.obj.visibleFlag == true)
	{
		DrawGameObject(item.medicalKits.obj, item.medicalKits.obj.graph);
	}
	// ミサイル
	if (item.missile.obj.visibleFlag == true)
	{
		DrawGameObject(item.missile.obj, item.missile.obj.graph);
	}
}





