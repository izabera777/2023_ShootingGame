// エネミー
#include "GameObject.h"
#include "Shot.h"
#include "Enemy.h"
#include "Utility.h"
#include "DxLib.h"
#include "Player.h"
#include "Menu.h"
#include "BG.h"
#include "UI.h"
#include "Sound.h"
#include "Item.h"
#include "Game.h"




//----------------------------//
// エネミー関数群.
//----------------------------//


// 初期化.
void InitEnemy(Enemy& enemy)
{
	// エネミーのグラフィックをメモリにロード＆表示座標を初期化
	char* enemyGlaphStr = "data/texture/Boss560_2.png";
	
	enemy.obj.graph = LoadGraph(enemyGlaphStr);
	enemy.damageGraph = LoadGraph(enemyGlaphStr);
	if (enemy.lifeBarGraph < 0)
	{
		enemy.lifeBarGraph = LoadGraph("data/texture/BossBar.png");
	}

	// エネミーの撃破時の分割画像メモリにロード (一旦game.enemyから入って1つ分作ってから、マルチエネミーにコピーする)
	LoadDivGraph("data/texture/ExplosionGraph160.png", ENEMY_DESTROY_GRAPH_TOTAL, ENEMY_DESTROY_GRAPH_X_NUM, ENEMY_DESTROY_GRAPH_Y_NUM, 160, 160, enemy.bossDestroyGraph);

	GraphFilter(enemy.damageGraph, DX_GRAPH_FILTER_HSB, 0, 0, 0, 256);
	// 情報の初期化
	enemy.obj.pos.x = 0;
	enemy.obj.pos.y = 50;
	enemy.obj.pos.z = 0;
	enemy.obj.speed = 0;
	enemy.obj.angle = GetRadian(180.0f);
	enemy.alive		= false;
	enemy.life		= BOSS_LIFE;
	enemy.destroyCount = 0;		// BOSS撃破時のカウント保存用

	// 『ダメージをうけていない』を表すFALSEを代入
	enemy.damageFlag = false;

	// ショットを初期化
	int shotGraph	= enemy.shot[0].obj.graph;
	int shotW		= enemy.shot[0].obj.w;
	int shotH		= enemy.shot[0].obj.h;
	if (shotGraph < 0)
	{
		shotGraph = LoadGraph("data/texture/shot5_exp2.png");

		GetGraphSize(shotGraph, &enemy.obj.w, &enemy.obj.h);
	}
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		InitShot(enemy.shot[i], shotGraph, shotW, shotH, GetRadian(180.0f), ENEMY_SHOT_SPEED, ENEMY_SHOT_POWER);
	}

	// ボスショット初期化
	int shotBossGraph	= enemy.extraShot[0].obj.graph;
	int shotBossW		= enemy.extraShot[0].obj.w;
	int shotBossH		= enemy.extraShot[0].obj.h;

	shotBossGraph = LoadGraph("data/texture/BOSS弾.png");
	// ショットのサイズをとる
	for (int i = 0; i < ENEMY_EXTRA_SHOT; i++)
	{
		GetGraphSize(shotBossGraph, &enemy.extraShot[i].obj.w, &enemy.extraShot[i].obj.h);
	}
	// ショットの初期化
	for (int i = 0; i < ENEMY_EXTRA_SHOT; i++)
	{
		InitShot(enemy.extraShot[i], shotBossGraph, shotBossW, shotBossH, GetRadian(180.0f), ENEMY_SHOT_EXTRA_SPEED, ENEMY_SHOT_EXTRA_POWER);
		enemy.extraShot[i].power = 3;
	}

	// ボスミサイルの初期化
	int shotBossMissleGraph = enemy.missile.obj.graph;
	int shotBossMissleW = enemy.missile.obj.w;
	int	shotBossMissleH = enemy.missile.obj.h;
	shotBossMissleGraph = LoadGraph("data/texture/missileGraph.png");
	// ミサイルのサイズをとる
	GetGraphSize(shotBossMissleGraph, &enemy.missile.obj.w, &enemy.missile.obj.h);
	// ボスミサイルの初期化
	InitShot(enemy.missile, shotBossMissleGraph, shotBossMissleW, shotBossMissleH, GetRadian(180.0f), ENEMY_MISSILE_SPEED, ENEMY_MISSILE_POWER);

	enemy.obj.w = 100;		// もともとのサイズだと大きすぎるので修正
	enemy.obj.h = 250;		// もともとのサイズだと大きすぎるので修正
}


// アップデート.
void UpdateEnemy(Enemy& enemy, Player& player,Game& game)
{
	// エネミーの座標を移動している方向に移動する
	if (enemy.rightMove == true)
	{
		enemy.obj.dir = VGet(1, 0, 0);
	}
	else
	{
		enemy.obj.dir = VGet(-1, 0, 0);
	}
	enemy.obj.speed = ENEMY_SPEED;
	
	//エネミー移動
	MoveGameObject(enemy.obj);

	// エネミーが画面端からでそうになっていたら画面内の座標に戻してあげ、移動する方向も反転する
	if (enemy.obj.pos.x > SCREEN_W - enemy.obj.w)
	{
		enemy.obj.pos.x = (float)(SCREEN_W - enemy.obj.w);
		enemy.rightMove = false;
	}
	else if (enemy.obj.pos.x < 0)
	{
		enemy.obj.pos.x = 0;
		enemy.rightMove = true;
	}

	// 敵の弾の発射処理 //
	// 敵弾が自機の方向を狙うフレーム数
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		enemy.shot[i].canTrunFrameTime++;
		if (enemy.shot[i].canTrunFrameTime >= 16)
		{
			enemy.shot[i].canTrunFrameTime = 0;
		}
	}

	// 生きていたら実行
	if (enemy.life > 0)
	{
		// ショットの発射インターバルがなくなっていたら撃つ
		if (enemy.shotIntervalCount == 0)
		{
			// 画面上にでていない弾があるか、弾の数だけ繰り返して調べる
			for (int i = 0; i < ENEMY_SHOT; i++)
			{
				// 弾iが画面上にでていない場合はその弾を画面に出す
				if (enemy.shot[i].visibleFlag == false)
				{
					// 弾iの位置をセット、位置は敵の中心にする
					// 左右交互に撃たせる処理
					if (i % 2 == 0)
					{
						enemy.shot[i].obj.pos.x = enemy.obj.pos.x + 200;
						enemy.shot[i].obj.pos.y = enemy.obj.pos.y + 200;
					}
					else
					{
						enemy.shot[i].obj.pos.x = enemy.obj.pos.x - 200;
						enemy.shot[i].obj.pos.y = enemy.obj.pos.y + 200;
					}

					// 弾iは現時点を持って存在するので、存在状態を保持する変数にtrueを代入する
					enemy.shot[i].visibleFlag = true;

					// 撃つ方向設定
					//enemy.shot[i].obj.dir = VGet(0, 1, 0);
					// 撃たれてから15フレームの間は敵弾の方向をプレイヤーに向ける
					if (enemy.shot[i].canTrunFrameTime <= 15)
					{
						enemy.shot[i].obj.dir = VSub(player.obj.pos, enemy.shot[i].obj.pos);
					}
					if (VSize(enemy.shot[i].obj.dir) > 0)
					{
						enemy.shot[i].obj.dir = VNorm(enemy.shot[i].obj.dir);
					}
					VECTOR shotVelicity = VScale(enemy.obj.dir, ENEMY_SHOT_SPEED);
					enemy.shot[i].obj.pos = VAdd(enemy.obj.pos, shotVelicity);


					// 一つ弾を出したので弾を出すループから抜けます
					break;
				}
			}

			// インターバル用のカウンターを設定.
			enemy.shotIntervalCount = BOSS_SHOT_INTERVAL;
		}
	}

	// エクストラショット
	// 生きてる、実行インターバル内、ステージ１か、ステージ２のみ
	if (enemy.life > 0 && enemy.extrashotIntervalCount == 0)
	{
		// 画面上に出ていない弾があるかチェック
		for (int i = 0; i < ENEMY_EXTRA_SHOT; i++)
		{
			// 弾iが画面上に出ていない場合はその弾を画面に出す
			if (enemy.extraShot[i].visibleFlag == false)
			{
				// 射撃座標設定
				enemy.extraShot[i].obj.pos.x = enemy.obj.pos.x;
				enemy.extraShot[i].obj.pos.y = enemy.obj.pos.y;

				// この時点を持って存在するので、存在状態を保持する変数をtrueにする
				enemy.extraShot[i].visibleFlag = true;
				// 撃つ方向の設定
				enemy.extraShot[i].obj.dir = VGet(0, 1, 0);
				// 一発出したので弾を出すループから抜け出す
				break;
			}
		}
		// インターバル用のカウンターを設定
		enemy.extrashotIntervalCount = ENEMY_SHOT_EXTRA_INTERVAL;
	}

	// ボスミサイル
	if (enemy.life > 0 && enemy.missleIntervalCount == 0)
	{
		// 画面上に出ていないかチェック
		if (enemy.missile.visibleFlag == false)
		{
			// 射撃座標設定（ボスの座標と同じ）
			enemy.missile.obj.pos.x = enemy.obj.pos.x;
			enemy.missile.obj.pos.y = enemy.obj.pos.y;
			// この時点で弾は存在する
			enemy.missile.visibleFlag = true;

			// 撃つ方向の設定
			// ミサイルからプレイヤーへのベクトルをとる
			VECTOR missileToPlayer = VSub(player.obj.pos, enemy.missile.obj.pos);
			
			// 正規化
			enemy.missile.obj.dir = VNorm(missileToPlayer);

			// 移動量の計算
			VECTOR velocity = VScale(enemy.missile.obj.dir, ENEMY_MISSILE_SPEED);

			// 移動力を加算
			enemy.missile.obj.pos = VAdd(enemy.obj.pos, velocity);

			// インターバル用カウンターを設定
			//enemy.missleIntervalCount = ENEMY_MISSILE_INTERVAL;

			// ミサイル追尾時間の設定
			enemy.missileTracingTime = 0;

		}
		if(enemy.missile.visibleFlag == true)
		{
			// 画面上にある場合
			
			// 追尾時間内である限り
			if (enemy.missileTracingTime < 200)
			{
				// 撃つ方向の設定
				// ミサイルからプレイヤーへのベクトルをとる
				VECTOR missileToPlayer = VSub(player.obj.pos, enemy.missile.obj.pos);

				// 正規化
				enemy.missile.obj.dir = VNorm(missileToPlayer);

				// 移動量の計算
				VECTOR velocity = VScale(enemy.missile.obj.dir, ENEMY_MISSILE_SPEED);

				// 移動力を加算
				enemy.missile.obj.pos = VAdd(enemy.missile.obj.pos, velocity);

				// 追尾時間を更新
				enemy.missileTracingTime++;

			}

			// インターバル用カウンターを設定
			//enemy.missleIntervalCount = ENEMY_MISSILE_INTERVAL;
		}
	}

	// エネミーのショットの連射力を管理
	if (enemy.shotIntervalCount != 0)
	{
		--enemy.shotIntervalCount;
	}
	// エクストラショットの連射力を管理
	if (enemy.extrashotIntervalCount != 0)
	{
		--enemy.extrashotIntervalCount;
	}
	// ボスミサイルの連射力を管理
	if (enemy.missleIntervalCount != 0)
	{
		--enemy.missleIntervalCount;
	}
	

	// エネミーが生きていたら実行
	if (enemy.life > 0 )
	{
		// ショット処理
		for (int i = 0; i < ENEMY_SHOT; i++)
		{
			// ショット移動
			MoveShot(enemy.shot[i]);
			// エネミーのショットとプレイヤーの当たり判定
			if (IsHitShot(enemy.shot[i], player.obj))
			{
				// あたってたらショットパワー分ダメージを与える
				if (player.life >= 0)
				{
					// プレイヤー被弾時のサウンド
					PlaySoundMem(game.sound.playerShotSE, DX_PLAYTYPE_BACK, true);

					player.damageCounter = 0;
					player.damageFlag = true;

					player.life -= enemy.shot[i].power;
					// 連続で当たらないように抜ける
					break;
				}


			}
		}
		// エクストラショット処理
		for (int i = 0; i < ENEMY_EXTRA_SHOT; i++)
		{
			// エクストラショット移動
			MoveShot(enemy.extraShot[i]);
			// エネミーのショットとプレイヤーの当たり判定
			if (IsHitShot(enemy.extraShot[i], player.obj))
			{
				// 当たってからショットパワー分のダメージを与える
				if (player.life >= 0)
				{
					player.life -= enemy.extraShot[i].power;
					player.damageCounter = 0;
					player.damageFlag = true;
				}

				// 連続で当たらないように抜ける
				break;
			}
		}

		// ボスミサイルの処理
		// ボスミサイルの移動
		MoveShot(enemy.missile);
		// ボスミサイルとプレイヤーの当たり判定
		if (IsHitShot(enemy.missile, player.obj))
		{
			// ヒット時にミサイルパワー分ダメージを与える
			if (player.life > 0)
			{
				// ミサイルのヒット時のサウンド
				PlaySoundMem(game.sound.enemyKillsSE, DX_PLAYTYPE_BACK, true);
				// HPを減らす
				player.life -= enemy.missile.power;
				// 連続で当たらないようにカウンタをリセット
				player.damageCounter = 0;
				// ダメージフラグをセット
				player.damageFlag = true;
				// ミサイルが当たった（描画タイミングで使用）
				enemy.missileHitFlag = true;	
			}
			// ミサイルが当たったたら追尾時間をリセット
			enemy.missileTracingTime = 0;
		}
	}

	// ボスミサイルの角度を求める
	enemy.missile.obj.angle = GetAngleOf2Vector(game.enemy.missile.obj.pos,game.player.obj.pos);
	//enemy.missile.obj.angle =  GetAngleOf2Vector(game.player.obj.pos ,game.enemy.missile.obj.pos);


}


// 描画.
void DrawEnemy(Enemy& enemy,Game& game)
{
	if (enemy.life > 0 && enemy.bossEntryFrameCount <= game.gameFrameCount)
	{
		enemy.alive = true;
		// ダメージを受けている場合はダメージ時のグラフィックを描画する
		if (enemy.damageFlag == true)
		{
			//DrawGameObject(enemy.obj, enemy.damageGraph);
			if (enemy.bossDestroyTime <= 65)
			{
				// 本体画像
				DrawGameObject(enemy.obj, enemy.obj.graph);
				// ダメージ演出画像
				//DrawGameObject(enemy.obj, enemy.bossDestroyGraph[enemy.bossDestroyTime / 5]);
				DrawGraph(enemy.obj.pos.x - 100, enemy.obj.pos.y - 20, enemy.destroyGraph[enemy.bossDestroyTime / 5], true);
				DrawGraph(enemy.obj.pos.x - 250, enemy.obj.pos.y + 100, enemy.destroyGraph[(enemy.bossDestroyTime / 5) - 1], true);
				DrawGraph(enemy.obj.pos.x + 230, enemy.obj.pos.y + 20, enemy.destroyGraph[enemy.bossDestroyTime / 5], true);
				DrawGraph(enemy.obj.pos.x + 10, enemy.obj.pos.y + 50, enemy.destroyGraph[(enemy.bossDestroyTime / 5) - 2], true);
				DrawGraph(enemy.obj.pos.x + 10, enemy.obj.pos.y - 50, enemy.destroyGraph[(enemy.bossDestroyTime / 5) - 2], true);
				// ダメージを受けてからの時間
				enemy.bossDestroyTime++;
			}
			if (enemy.bossDestroyTime >= 65)
			{
				enemy.damageFlag = false;
				enemy.bossDestroyTime = 0;
			}
		}
		else
		{
			DrawGameObject(enemy.obj, enemy.obj.graph);
		}

		// ショットも表示
		for (int i = 0; i < ENEMY_SHOT; i++)
		{
			DrawShot(enemy.shot[i]);
		}
		// エクストラショット描画
		for (int i = 0; i < ENEMY_EXTRA_SHOT; i++)
		{
			DrawShot(enemy.extraShot[i]);
		}
		// ボスミサイルの描画
		DrawShot(enemy.missile);
		// ミサイルの先端を回転の中心座標とした場合
		/*DrawRotaGraph(enemy.missile.obj.pos.x, enemy.missile.obj.pos.y + (enemy.missile.obj.h / 2),
			enemy.missile.obj.scale,
			enemy.missile.obj.angle,
			enemy.missile.obj.graph, true);*/

		// ボスミサイルヒット時の爆発エフェクト描画
		if (enemy.missileHitFlag == true)
		{
			if (enemy.missileHitCounter <= 130)
			{
				// 被弾エフェクト描画
				DrawGraph(game.player.obj.pos.x - 70,game.player.obj.pos.y - 64,enemy.bossDestroyGraph[enemy.missileHitCounter / 10],true);

				// カウントの増加
				enemy.missileHitCounter++;
			}
			if (enemy.missileHitCounter == 131)
			{
				enemy.missileHitFlag = false;
				enemy.missileHitCounter = 0;
			}
		}
	}

	// ダメージの破壊描画
	if (enemy.life <= 0 && enemy.destroyCount <=130)
	{
		DrawGraph(enemy.obj.pos.x - 100, enemy.obj.pos.y - 20,	enemy.bossDestroyGraph[(enemy.destroyCount  / 10) - 1], true);
		DrawGraph(enemy.obj.pos.x - 250, enemy.obj.pos.y - 10,	enemy.bossDestroyGraph[ enemy.destroyCount  / 10]	 , true);
		DrawGraph(enemy.obj.pos.x + 230, enemy.obj.pos.y + 20,	enemy.bossDestroyGraph[ enemy.destroyCount  / 10]	 , true);
		DrawGraph(enemy.obj.pos.x +  10, enemy.obj.pos.y - 50,	enemy.bossDestroyGraph[(enemy.destroyCount  / 10) - 2], true);
		DrawGraph(enemy.obj.pos.x	   , enemy.obj.pos.y     ,	enemy.bossDestroyGraph[(enemy.destroyCount  / 10) - 2], true);
		DrawGraph(enemy.obj.pos.x + 100, enemy.obj.pos.y - 50,	enemy.bossDestroyGraph[ enemy.destroyCount  / 10]	 , true);
		DrawGraph(enemy.obj.pos.x -  50, enemy.obj.pos.y + 100,	enemy.bossDestroyGraph[(enemy.destroyCount  / 10)	], true);
		DrawGraph(enemy.obj.pos.x +  30, enemy.obj.pos.y + 200,	enemy.bossDestroyGraph[(enemy.destroyCount  / 10) - 2], true);
		DrawGraph(enemy.obj.pos.x + 200, enemy.obj.pos.y + 200,	enemy.bossDestroyGraph[(enemy.destroyCount  / 10) - 1], true);

		enemy.destroyCount++;
	}

}










///////////////////////////////////////////////////////////////////
// STAGE1
///////////////////////////////////////////////////////////////////

// 初期化.STAGE1
void InitEnemySTAGE1(Enemy& enemy)
{
	// エネミーのグラフィックをメモリにロード＆表示座標を初期化
	char* enemyGlaphStr = "data/texture/戦車Boss.png";

	enemy.obj.graph = LoadGraph(enemyGlaphStr);
	enemy.damageGraph = LoadGraph(enemyGlaphStr);
	enemy.lifeBarGraph = LoadGraph("data/texture/BossBar.png");

	GraphFilter(enemy.damageGraph, DX_GRAPH_FILTER_HSB, 0, 0, 0, 256);
	enemy.obj.pos.x = 0;
	enemy.obj.pos.y = 50;
	enemy.obj.pos.z = 0;
	enemy.obj.speed = 0;
	enemy.obj.angle = GetRadian(180.0f);
	enemy.alive = false;
	enemy.life = BOSS_LIFE;


	// 『ダメージをうけていない』を表すFALSEを代入
	enemy.damageFlag = false;

	// エネミーのグラフィックのサイズを得る
	//GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);

	// ショットを初期化
	int shotGraph = enemy.shot[0].obj.graph;
	int shotW = enemy.shot[0].obj.w;
	int shotH = enemy.shot[0].obj.h;
	shotGraph = LoadGraph("data/texture/shot5_exp2.png");

	GetGraphSize(shotGraph, &enemy.obj.w, &enemy.obj.h);
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		InitShot(enemy.shot[i], shotGraph, shotW, shotH, GetRadian(180.0f), ENEMY_SHOT_SPEED, ENEMY_SHOT_POWER);
	}

	enemy.obj.w = 500;		// もともとのサイズだと大きすぎるので修正
	enemy.obj.h = 500;		// もともとのサイズだと大きすぎるので修正
}



///////////////////////////////////////////////////////////////////
// STAGE2
///////////////////////////////////////////////////////////////////

// 初期化.STAGE2
void InitEnemySTAGE2(Enemy& enemy)
{
	// STAGE2_BOSS のグラフィックをメモリにロード＆表示座標を初期化
	char* enemyGlaphStr = "data/texture/BattleShipIowa.png";

	enemy.obj.graph = LoadGraph(enemyGlaphStr);
	enemy.damageGraph = LoadGraph(enemyGlaphStr);
	enemy.lifeBarGraph = LoadGraph("data/texture/BossBar.png");

	GraphFilter(enemy.damageGraph, DX_GRAPH_FILTER_HSB, 0, 0, 0, 256);
	enemy.obj.pos.x = 0;
	enemy.obj.pos.y = 50;
	enemy.obj.pos.z = 0;
	enemy.obj.speed = 0;
	enemy.obj.angle = GetRadian(180.0f);
	enemy.alive = false;
	enemy.life = BOSS_LIFE;


	// 『ダメージをうけていない』を表すFALSEを代入
	enemy.damageFlag = false;

	// エネミーのグラフィックのサイズを得る
	//GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);

	// ショットを初期化
	int shotGraph = enemy.shot[0].obj.graph;
	int shotW = enemy.shot[0].obj.w;
	int shotH = enemy.shot[0].obj.h;
	shotGraph = LoadGraph("data/texture/shot5_exp2.png");

	GetGraphSize(shotGraph, &enemy.obj.w, &enemy.obj.h);
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		InitShot(enemy.shot[i], shotGraph, shotW, shotH, GetRadian(180.0f), ENEMY_SHOT_SPEED, ENEMY_SHOT_POWER);
	}

	enemy.obj.w = 500;		// もともとのサイズだと大きすぎるので修正
	enemy.obj.h = 500;		// もともとのサイズだと大きすぎるので修正
}


