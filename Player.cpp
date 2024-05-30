// プレイヤー
#include "GameObject.h"
#include "Shot.h"
#include "Enemy.h"
#include "Player.h"
#include "Utility.h"
#include "DxLib.h"
#include "BG.h"
#include "UI.h"
#include "Menu.h"
#include "Sound.h"
#include "Item.h"
#include "Game.h"
//#include "MultiEnemy.h"



//----------------------------//
// プレイヤー関数群.
//----------------------------//
// 初期化.
void InitPlayer(Player& player)
{
	// プレイヤーのグラフィックをメモリにロード＆表示座標を初期化
	if (player.obj.graph < 0)
	{
		player.obj.graph = LoadGraph("data/texture/myimgH120.png");
	}
	// プレイヤーの影画像のロード
	if (player.shadowGraph < 0)
	{
		player.shadowGraph = LoadGraph("data/texture/myShadow.png");
	}

	// プレイヤーのブースター画像をメモリにロード
	LoadDivGraph("data/texture/PlayerBooster.png", PLAYER_BOOSTER_X_NUM * PLAYER_BOOSTER_Y_NUM, PLAYER_BOOSTER_X_NUM, PLAYER_BOOSTER_Y_NUM, 64,64,player.boosterGraph);
	// プレイヤーの旋回画像をメモリにロード
	LoadDivGraph("data/texture/playerTruningGraph3.png", PLAYER_TRUNING_X_NUM * PLAYER_TRUNING_Y_NUM, PLAYER_TRUNING_X_NUM,PLAYER_TRUNING_Y_NUM, 90, 110, player.playerTruningGraph);
	// プレイヤーが撃破された際の分割画像
	LoadDivGraph("data/texture/ExplosionGraph160.png", PLAYER_DESTROY_GRAPH_TOTAL, PLAYER_DESTROY_GRAPH_X_NUM, PLAYER_DESTROY_GRAPH_Y_NUM, 160, 160, player.DeathGraph);

	player.obj.pos.x = SCREEN_W / 2;		// 画面の半分（中央）
	player.obj.pos.y = SCREEN_H/2 + 100;		// 画面下-100の位置
	player.obj.pos.z = 0;
	player.obj.speed = 0.0f;
	player.life		 = PLAYER_LIFE;

	// 『ダメージをうけていない』を表すFALSEを代入
	player.damageFlag = false;

	// プレイヤーの画像のサイズを得る
	GetGraphSize(player.obj.graph, &player.obj.w, &player.obj.h);
	player.obj.w = PLAYER_WIDTH;
	player.obj.h = PLAYER_HEIGHT;

	// プレイヤーHP画像をロード
	player.lifeBarGraph = LoadGraph("data/texture/HPbar.png");

	// ショットを初期化
	int shotGraph = player.shot[0].obj.graph;
	int shotW = player.shot[0].obj.w;
	int shotH = player.shot[0].obj.h;

	if (shotGraph < 0)
	{
		shotGraph = LoadGraph("data/texture/playerShotGraph.png");
		GetGraphSize(shotGraph, &player.obj.w, &player.obj.h);
	}
	for (int i = 0; i < PLAYER_SHOT; i++)
	{
		InitShot(player.shot[i], shotGraph, shotW, shotH, 0, PLAYER_SHOT_SPEED, PLAYER_SHOT_POWER);
		InitShot(player.multiShotLeft[i], shotGraph, shotW, shotH, 0, PLAYER_SHOT_SPEED, PLAYER_SHOT_POWER);
		InitShot(player.multiShotRight[i], shotGraph, shotW, shotH, 0, PLAYER_SHOT_SPEED, PLAYER_SHOT_POWER);
	}
	// ミサイルの初期化
	InitShot(player.missile, shotGraph, shotW, shotH, 0, PLAYER_SHOT_SPEED, PLAYER_SHOT_POWER);

	// ボム用ショットの初期化
	int bomShotW = 1600;
	int bomShotH = 1000;
	InitShot(player.bomShot, shotGraph, bomShotW, bomShotH, 0, PLAYER_SHOT_SPEED, PLAYER_BOM_POWER);


	// ステージ開始時に自動的に動作させるフラグの初期化
	player.moveEndFlag = false;

	// 殲滅率の初期化
	player.enemyEliminationCount = 0.0f;

	// プレイヤーアイテム状態の初期化
	player.itemStatus = PLAYER_NO_ITEM;

}

// アップデート.
void UpdatePlayer(Player& player, Enemy multiEnemy[],Enemy& enemy,int size,Game& game)
{
	// プレイヤーの操作
	MovePlayer(player);


	// 弾の発射処理
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)
	{
		// ショットの発射インターバルがなくなっていたら撃てる
		if (player.shotIntervalCount == 0)
		{
			// 発射時のサウンドを出す
			PlaySoundMem(game.sound.playerShotSE, DX_PLAYTYPE_BACK, true);

			// 画面上にでていない弾があるか、弾の数だけ繰り返して調べる
			for (int i = 0; i < PLAYER_SHOT; i++)
			{
				// 弾iが画面上にでていない場合はその弾を画面に出す
				if (player.shot[i].visibleFlag == false)
				{
					// 弾iの位置をセット、位置はプレイヤーの中心にする
					player.shot[i].obj.pos.x = (player.obj.w - player.shot[i].obj.w) / 2 + player.obj.pos.x - 20;
					player.shot[i].obj.pos.y = (player.obj.h - player.shot[i].obj.h) / 2 + player.obj.pos.y;

					// 弾iは現時点を持って存在するので、存在状態を保持する変数にtrueを代入する
					player.shot[i].visibleFlag = true;

					// 向きを設定
					player.shot[i].obj.dir = VGet(0, -2, 0);

					// 一つ弾を出したので弾を出すループから抜けます
					break;
				}
			}
			// インターバル用のカウンターを設定.
			player.shotIntervalCount = PLAYER_SHOT_INTERVAL;
		}
	}

	// ショット関連
	for (int i = 0; i < PLAYER_SHOT; i++)
	{
		// ショット移動
		MoveShot(player.shot[i]);

		
		// プレイヤーのショットと敵の当たり判定
		for (int j = 0; j < size; j++)
		{
			if (multiEnemy[j].alive == true)
			{
				if (IsHitShot(player.shot[i], multiEnemy[j].obj))
				{
					// あたってたらショットパワー分ダメージを与える
					multiEnemy[j].life -= player.shot[i].power;
					
					multiEnemy[j].damageCounter = 0;
					multiEnemy[j].damageFlag	= true;
					multiEnemy[j].alive			= false;
					player.enemyEliminationCount++;
					// サウンドの再生
					PlaySoundMem(game.sound.enemyKillsSE, DX_PLAYTYPE_BACK, true);

					// アイテムを出す// 各種設定
					game.player.itemEliminationCount++;		// カウントが20溜まればアイテムゲット
					if (game.player.itemEliminationCount > ITEM_LEAVE_INTERVAL)
					{
						// カウントの初期化
						game.player.itemEliminationCount = 0;

						// どのアイテムを出すか
						int randNum = GetRand(ITEM_RAND_MAX);

						// 出すアイテムの情報の書き込み
						switch (randNum)
						{
						case MULTI_SHOT:
							game.item.multiShot.obj.visibleFlag = true;
							game.item.multiShot.obj.pos.x = multiEnemy[j].obj.pos.x;
							game.item.multiShot.obj.pos.y = multiEnemy[j].obj.pos.y;
							break;
						case BOM:
							game.item.bom.obj.visibleFlag = true;
							game.item.bom.obj.pos.x = multiEnemy[j].obj.pos.x;
							game.item.bom.obj.pos.y = multiEnemy[j].obj.pos.y;
							break;
						case MEDICAL_KIT:
							game.item.medicalKits.obj.visibleFlag = true;
							game.item.medicalKits.obj.pos.x = multiEnemy[j].obj.pos.x;
							game.item.medicalKits.obj.pos.y = multiEnemy[j].obj.pos.y;
							break;
						case MISSILE:
							game.item.missile.obj.visibleFlag = true;
							game.item.missile.obj.pos.x = multiEnemy[j].obj.pos.x;
							game.item.missile.obj.pos.y = multiEnemy[j].obj.pos.y;
							break;
						default:
							break;
						}
					}
					// 連続で当たらないように抜ける
					break;
				}
			}
		}
	}
	// ショット関連
	for (int i = 0; i < PLAYER_SHOT; i++)
	{
		// ショットの移動
		MoveShot(game.player.multiShotLeft[i]);
		MoveShot(game.player.multiShotRight[i]);
	}

	// アイテムの効果
	EffectItem(game);

	// BOSSの当たり判定
	for (int i = 0; i < PLAYER_SHOT; i++)
	{
		if (enemy.alive == true)
		{
			if (IsHitShot(player.shot[i], enemy.obj))
			{
				// 当たっていたらショットパワー分ダメージを与える
				enemy.life -= player.shot[i].power;
				enemy.damageCounter = 0;
				enemy.damageFlag = true;
				enemy.alive = false;

				break;
			}
		}
	}


	// ショットインターバルがゼロでないときゼロまで減らす
	if (player.shotIntervalCount != 0)
	{
		--player.shotIntervalCount;
	}


	// ダメージを受けているかどうかで処理を分岐
	if (player.damageFlag == true)
	{
		player.damageCounter++;

		if (player.damageCounter == 5)
		{
			// 『ダメージをうけていない』を表すFALSEを代入
			player.damageFlag = false;
		}
	}

	// ３WAYショットアイテムを保持している場合
	if (player.itemStatus == MULTI_SHOT)
	{
		// 弾の発射処理
		if (CheckHitKey(KEY_INPUT_SPACE) == 1 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)
		{
			// ショットのインターバル
			if (game.player.shotIntervalCount == 0)
			{
				// 画面上に出ていない弾があるか、弾の数だけ調べる
				// 左のショット
				for (int i = 0; i < PLAYER_SHOT; i++)
				{
					// 弾iが画面上に出ていない場合はその弾を画面に出す
					if (game.player.multiShotLeft[i].visibleFlag == false)
					{
						// 弾iの位置をセット、位置はプレイヤーの中心にする
						game.player.multiShotLeft[i].obj.pos.x = (game.player.obj.w - game.player.shot[i].obj.w) / 2 + game.player.obj.pos.x - 20;
						game.player.multiShotLeft[i].obj.pos.y = (game.player.obj.h - game.player.shot[i].obj.h) / 2 + game.player.obj.pos.y;
						// 弾の存在を書き込む
						game.player.multiShotLeft[i].visibleFlag = true;
						// 向きを設定
						game.player.multiShotLeft[i].obj.dir = VGet(-1, -3, 0);
						// 一つ弾を出したのでループから抜ける
						break;
					}
				}
				// 右のショット
				for (int i = 0; i < PLAYER_SHOT; i++)
				{
					// 弾iが画面上に出ていない場合はその弾を画面に出す
					if (game.player.multiShotRight[i].visibleFlag == false)
					{
						// 弾iの位置をセット、位置はプレイヤーの中心にする
						game.player.multiShotRight[i].obj.pos.x = (game.player.obj.w - game.player.shot[i].obj.w) / 2 + game.player.obj.pos.x - 20;
						game.player.multiShotRight[i].obj.pos.y = (game.player.obj.h - game.player.shot[i].obj.h) / 2 + game.player.obj.pos.y;
						// 弾の存在を書き込む
						game.player.multiShotRight[i].visibleFlag = true;
						// 向きを設定
						game.player.multiShotRight[i].obj.dir = VGet(1, -3, 0);
						// 一つ弾を出したのでループから抜ける
						break;
					}
				}
			}
		}
	}

	// ３WAYショット
	// （左射撃）マルチエネミーとの当たり判定
	for (int i = 0; i < PLAYER_SHOT; i++)
	{
		// プレイヤーのショットとマルチエネミーとの当たり判定
		for (int j = 0; j < ENEMY_OF_NUMBER; j++)
		{
			// エネミーが存在している場合
			if (multiEnemy[j].alive == true)
			{
				// 当たった場合
				// 左
				if (IsHitShot(player.multiShotLeft[i], multiEnemy[j].obj))
				{
					multiEnemy[j].life -= player.multiShotLeft[i].power;
					multiEnemy[j].damageCounter = 0;
					multiEnemy[j].alive = false;
					player.enemyEliminationCount++;
					// サウンドの再生
					PlaySoundMem(game.sound.enemyKillsSE, DX_PLAYTYPE_BACK, true);
					break;
				}
			}
		}
	}
	// （右射撃）マルチエネミーとの当たり判定
	for (int i = 0; i < PLAYER_SHOT; i++)
	{
		// プレイヤーのショットとマルチエネミーとの当たり判定
		for (int j = 0; j < ENEMY_OF_NUMBER; j++)
		{
			// エネミーが存在している場合
			if (multiEnemy[j].alive == true)
			{
				// 当たった場合
				// 右
				if (IsHitShot(player.multiShotRight[i], multiEnemy[j].obj))
				{
					multiEnemy[j].life -= player.multiShotRight[i].power;
					multiEnemy[j].damageCounter = 0;
					multiEnemy[j].alive = false;
					player.enemyEliminationCount++;
					// サウンドの再生
					PlaySoundMem(game.sound.enemyKillsSE, DX_PLAYTYPE_BACK, true);
					break;
				}
			}
		}
	}


	// BOSSとの当たり判定
	for (int i = 0; i < PLAYER_SHOT; i++)
	{
		// 存在していれば
		if (enemy.alive == true)
		{
			// 当たったら
			// 左
			if (IsHitShot(player.multiShotLeft[i], enemy.obj))
			{
				enemy.life -= player.multiShotLeft[i].power;
				enemy.damageCounter = 0;
				enemy.damageFlag = true;
				enemy.alive = false;

				//break;
			}
			// 右
			if (IsHitShot(player.multiShotRight[i], enemy.obj))
			{
				enemy.life -= player.multiShotRight[i].power;
				enemy.damageCounter = 0;
				enemy.damageFlag = true;
				enemy.alive = false;
				break;
			}
		}
	}
	



}

// アイテムの効果
void EffectItem(Game& game)
{
	switch (game.player.itemStatus)
	{
	case MULTI_SHOT:

		break;
	case BOM:

		break;
	case MEDICAL_KIT:

		break;
	case MISSILE:

		break;
	default:
		break;
	}
}




// メニュー時のプレイヤー更新
void UpdateMenuPlayer(Game& game, Player& player, Menu& menu)
{
	// プレイヤーの移動
	MovePlayer(player);


	// ショット関連
	for (int i = 0; i < PLAYER_SHOT; i++)
	{
		// ショット移動
		MoveShot(player.shot[i]);		
	}


	// 弾の発射処理
	if (CheckHitKey(KEY_INPUT_SPACE) != 0 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)
	{

		menu.playerKeyInputIndex = 5;
		// ショットの発射インターバルがなくなっていたら撃てる
		if (player.shotIntervalCount == 0)
		{
			// 発射時のサウンドを出す
			PlaySoundMem(game.sound.playerShotSE, DX_PLAYTYPE_BACK,true);
			// 画面上にでていない弾があるか、弾の数だけ繰り返して調べる
			for (int i = 0; i < PLAYER_SHOT; i++)
			{
				// 弾iが画面上にでていない場合はその弾を画面に出す
				if (player.shot[i].visibleFlag == false)
				{
					// 弾iの位置をセット、位置はプレイヤーの中心にする
					player.shot[i].obj.pos.x = player.obj.pos.x ;
					player.shot[i].obj.pos.y = (player.obj.h - player.shot[i].obj.h) / 2 + player.obj.pos.y;

					// 弾iは現時点を持って存在するので、存在状態を保持する変数にtrueを代入する
					player.shot[i].visibleFlag = true;

					// 向きを設定
					player.shot[i].obj.dir = VGet(0, -1, 0);

					// 一つ弾を出したので弾を出すループから抜けます
					break;
				}
			}

			
			// インターバル用のカウンターを設定.
			player.shotIntervalCount = PLAYER_SHOT_INTERVAL;
		}
	}
	

	// ショット関連////////////////////////////////////////// ステート変更処理 //////////////////////////////////////
	
	// ショットが当たった画像でステートを切り替える
	for (int i = 0; i < PLAYER_SHOT; i++)
	{
		for (int j = 0; j < MENU_STAGE_NUM; j++)
		{
			if (IsHitShot(player.shot[i], menu.objStageGraph[j]))
			{
				// 左の画像の当たり判定
				if (j == 0)
				{
					// ガラスが割れる音
					PlaySoundMem(game.sound.glassCrackSE, DX_PLAYTYPE_BACK, true);
					menu.stageMenu[0].life--;
				}
				// 中央の画像の当たり判定
				if (j == 1)
				{
					// ガラスが割れる音
					PlaySoundMem(game.sound.glassCrackSE, DX_PLAYTYPE_BACK, true);
					menu.stageMenu[1].life--;
				}
				// 右の画像の当たり判定
				if (j == 2)
				{
					// ガラスが割れる音
					PlaySoundMem(game.sound.glassCrackSE, DX_PLAYTYPE_BACK, true);
					menu.stageMenu[2].life--;
				}
			}
		}
	}


	// ステージのライフがゼロになりステートが切り替わったら暗転
	if (player.changeStateFlag == true)
	{
		BlackOutScreen(game);
	}

	// ステージライフがゼロになったらステート切り替え
	if (menu.stageMenu[0].life <= 0)
	{
		if (game.blendNumFrameCount<= 0)
		{
			player.changeStateFlag = false;
			game.blendNumFrameCount = 0;
			// 画面の明るさ調整
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			// ステート切り替え
			ChangeGameState(STATE_STAGE1, game);
		}
		player.changeStateFlag = true;
	}
	if (menu.stageMenu[1].life <= 0)
	{
		if (game.blendNumFrameCount <= 0)
		{
			player.changeStateFlag = false;
			game.blendNumFrameCount = 0;
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			ChangeGameState(STATE_STAGE2, game);
		}
		player.changeStateFlag = true;
	}
	if (menu.stageMenu[2].life <= 0)
	{
		if (game.blendNumFrameCount <= 0)
		{
			player.changeStateFlag = false;
			game.blendNumFrameCount = 0;
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			ChangeGameState(STATE_STAGE3, game);
		}
		player.changeStateFlag = true;
	}



	// ショットのインターバル
	if (player.shotIntervalCount != 0)
	{
		--player.shotIntervalCount;
	}


	// ダメージを受けているかどうかで処理を分岐
	if (player.damageFlag == true)
	{
		player.damageCounter++;

		if (player.damageCounter == 5)
		{
			// 『ダメージをうけていない』を表すFALSEを代入
			player.damageFlag = false;
		}
	}

}


// 描画.
void DrawPlayer(Player& player)
{
	if (player.damageFlag == true)
	{
		// ダメージを受けている場合は透明＝表示しない
	}
	else if(player.life > 0)
	{
		//DrawGameObject(player.obj, player.obj.graph);
		DrawGameObject(player.obj, player.playerTruningGraph[player.truningGraphIndex]);
	}
	
	// プレイヤー撃破時の演出
	if (player.life <= 0 && player.playerDeathFrameCount <= 65)
	{
		// 撃破されてからのフレームカウントを10で割り添え字を出す
		DrawGameObject(player.obj, player.DeathGraph[player.playerDeathFrameCount / 5]);
		// プレイヤーが撃破されてからのフレームカウント
		player.playerDeathFrameCount++;
	}


	// プレイヤーのブースター画像を表示
	if (player.life > 0)
	{
		player.boosterCount++;
		int boosterIndex = 0;
		if (player.boosterCount >= 0 && player.boosterCount <= 19)
		{
			boosterIndex = 0;
		}
		if (player.boosterCount >= 20 && player.boosterCount <= 39)
		{
			boosterIndex = 1;
		}
		if (player.boosterCount >= 40 && player.boosterCount <= 59)
		{
			boosterIndex = 2;
		}
		if (player.boosterCount >= 60 && player.boosterCount <= 79)
		{
			boosterIndex = 3;
		}
		if (player.boosterCount >= 80)
		{
			player.boosterCount = 0;
			boosterIndex = 0;
		}
		// ブースターの描画
		DrawRotaGraph(player.obj.pos.x, player.obj.pos.y + 64, 1.0f, 0, player.boosterGraph[boosterIndex], TRUE);

		// ショットも表示
		for (int i = 0; i < PLAYER_SHOT; i++)
		{
			DrawShot(player.shot[i]);
			DrawShot(player.multiShotLeft[i]);
			DrawShot(player.multiShotRight[i]);
			DrawShot(player.missile);
		}
	}

}


// プレイヤーの移動
void MovePlayer(Player& player)
{
	// 加算する方向の初期化
	VECTOR direction = VGet(0, 0, 0);
	float playerSpeed = PLAYER_SPEED;

	// 旋回用タイマーの設定
	if (player.truningTiemer > 0)
	{
		player.truningTiemer -= 2;
	}
	if (player.truningTiemer <= 0)
	{
		player.truningGraphIndex = 0;
	}

	// 矢印キーを押していたらプレイヤーを移動させる
	if (CheckHitKey(KEY_INPUT_LEFT) == 1 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0)
	{
		direction = VAdd(direction, VGet(-1, 0, 0));	// 方向の設定

		// 旋回用画像の添え字の決定
		if (player.truningTiemer <= 119)
		{
			player.truningTiemer += 3;
		}
		if (player.truningTiemer >= 120)
		{
			player.truningTiemer = 0;
		}
		if (player.truningTiemer >= 0 && player.truningTiemer <= 39)
		{
			player.truningGraphIndex = 4;
		}
		if (player.truningTiemer >= 40 && player.truningTiemer <= 79)
		{
			player.truningGraphIndex = 5;
		}
		if (player.truningTiemer >= 80 && player.truningTiemer <= 119)
		{
			player.truningGraphIndex = 6;
		}
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0)
	{
		direction = VAdd(direction, VGet(1, 0, 0));
		// 旋回画像の添え字の決定
		if (player.truningTiemer <= 119)
		{
			player.truningTiemer += 3;
		}
		if (player.truningTiemer >= 120)
		{
			player.truningTiemer = 0;
		}
		if (player.truningTiemer >= 0 && player.truningTiemer <= 39)
		{
			player.truningGraphIndex = 1;
		}
		if (player.truningTiemer >= 40 && player.truningTiemer <= 79)
		{
			player.truningGraphIndex = 2;
		}
		if (player.truningTiemer >= 80 && player.truningTiemer <= 119)
		{
			player.truningGraphIndex = 3;
		}
	}
	// 上方向移動（キーボード↑、パッド十字キー↑）
	if (CheckHitKey(KEY_INPUT_UP) == 1 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP) != 0)
	{
		direction = VAdd(direction, VGet(0, -1, 0));
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN) != 0)
	{
		direction = VAdd(direction, VGet(0, 1, 0));
	}
	if (VSize(direction) > 0)		// 長さがゼロよりも大きい場合のみ
	{
		direction = VNorm(direction);
	}
	// プレイヤー座標の更新
	VECTOR velocity = VScale(direction, playerSpeed);
	player.obj.pos = VAdd(player.obj.pos, velocity);


	// プレイヤーが画面左端からはみ出そうになっていたら画面内の座標に戻してあげる
	if (player.obj.pos.x < player.obj.w * 0.5f)
	{
		player.obj.pos.x = player.obj.w * 0.5f;
	}
	if (player.obj.pos.x > SCREEN_W - player.obj.w * 0.5f)
	{
		player.obj.pos.x = (float)(SCREEN_W - player.obj.w * 0.5f);
	}
	if (player.obj.pos.y < 100)
	{
		player.obj.pos.y = 100;
	}
	if (player.obj.pos.y > SCREEN_H - player.obj.w * 0.5f - PLAYER_MOVING_RANGE_BUFF * 2)
	{
		player.obj.pos.y = (float)(SCREEN_H - player.obj.h * 0.5f - PLAYER_MOVING_RANGE_BUFF * 2);
	}

}

