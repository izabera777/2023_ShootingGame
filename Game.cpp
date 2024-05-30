#include "DxLib.h"
#include "GameObject.h"
#include "Utility.h"
#include "Shot.h"
#include "BG.h"
#include "UI.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"
#include "Sound.h"
#include "Item.h"
#include "Game.h"
#include "MultiEnemy.h"

struct multiEnemy;



//シューティング

//----------------------------//
// ゲームそのものの関数群.
//----------------------------//


//現在のフレーム数　フレーム数を増加
void GetFrameCount(Game& game)
{
	game.gameFrameCount++;		// ゲームフレームカウント
}

// 初期化.
void InitGame(Game& game)
{
	game.gameStartTime = 0;
	game.state = STATE_MENU;
}

// ゲームスタート時の初期化
void InitGameStart(Game& game)
{
	// フォント変更
	ChangeFont("Impact");

	// スコアの初期化
	game.score = 0;
	game.scoreUpFlag = false;

	// パッドの認識
	game.keyPad = GetJoypadInputState(DX_INPUT_KEY_PAD1);	// キーパッド１の入力

	// フレーム数のカウント
	game.gameStartTime = GetNowCount();

	// プレイヤーが死んでからの時間を初期化
	game.player.playerDeathFrameCount = 0;

	// フレーム数を初期化
	game.gameFrameCount = 0;

	// ボスエントリーフラグの初期化
	game.bossEntryFlag = false;

	// メニューライフの初期化
	for (int i = 0; i < STAGE_NUM; i++)
	{
		game.menu.stageMenu[i].life = MENU_LIFE;
	}
	InitItem(game.item);
	InitUI(game.ui);
	InitPlayer(game.player);
	InitEnemy(game.enemy); 
	InitMultiEnemy(game.enemy, multiEnemy, ENEMY_OF_NUMBER,game);

	// グラフィックをロードしてサイズを取得.
	int bgGraph = game.bg[0].obj.graph;
	// 注意！画面のサイズと背景画像のサイズは一緒じゃないとダメ
	bgGraph = LoadGraph("data/texture/backimg.png");

	// ワーニング用横スクロール画像
	int bgGraphHalf = game.bgNext[0].obj.graph;
	if (bgGraphHalf < 0)
	{
		bgGraphHalf = LoadGraph("data/texture/warningGraphLong.png");
	}

	int cityGraph = game.city[0].obj.graph;
	int montainGraph = game.montain[0].obj.graph;
	int cityGraph2 = game.city2[0].obj.graph;
	cityGraph = LoadGraph("data/texture/クリア背景.png");
	montainGraph = LoadGraph("data/texture/山1600.png");
	cityGraph2 = LoadGraph("data/texture/クリア背景.png");

	for (int i = 0; i < BG_NUM; i++)
	{
		InitBG(game.bg[i], bgGraph, i);
		InitCtiyBG(game.city[i], cityGraph, i);
		InitCtiyBG(game.city2[i], cityGraph2, i);
		InitCtiyBG(game.montain[i], montainGraph, i);
		InitBGHorizon(game.bgNext[i], bgGraphHalf, i);
	}
	

	//メニュー画像をロードしてサイズを取得

	int menuGraph = game.menu.obj.graph;
	if (menuGraph < 0)
	{
		menuGraph = LoadGraph("data/texture/backimg.png");
	}
	//メニュー画面初期化
	InitMenu(game.menu, menuGraph);
}

// ステート切り替え.
void ChangeGameState(STATE state, Game& game)
{
	// 即座に切り替わりすぎるので、ちょっと時間を止める.
	WaitTimer(STATE_CHANGE_WAIT);

	// ステートが切り替わった瞬間はキー離した判定をリセット.
	game.keyOn = false;
	game.keyRelease = false;

	game.state = state;

	// ステートが切り替わった瞬間、必要なら初期化などの処理を行う
	switch (game.state)
	{
		// メニュー画面
	case STATE_MENU:
		InitGameStart(game);
		break;
		// ステージ１
	case STATE_STAGE1:
		InitGameStart(game);
		break;
		// ステージ２
	case STATE_STAGE2:
		InitGameStartSTAGE1(game);
		InitMultiEnemySTAGE1(game.enemy, multiEnemy, ENEMY_OF_NUMBER, game);

		break;
		// ステージ３
	case STATE_STAGE3:
		InitGameStartSTAGE2(game);
		InitMultiEnemySTAGE2(game.enemy, multiEnemy, ENEMY_OF_NUMBER, game);

		break;
		// クリア画面.
	case STATE_CLEAR:
		break;
		// ゲームオーバー.
	case STATE_GAMEOVER:
		break;
	default:
		break;
	}
}

// アップデート.
void UpdateGame(Game& game)
{
	// キー離した瞬間を取る.
	if (game.keyOn)
	{
		if (CheckHitKey(KEY_INPUT_SPACE) == 0)
		{
			game.keyOn = false;
			game.keyRelease = true;
		}
	}
	else if (game.prevKeyOn == false && CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		game.keyRelease = false;
		game.keyOn = true;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		game.prevKeyOn = true;
	}
	else
	{
		game.prevKeyOn = false;
	}

	// ステートごとに処理をわける.
	switch (game.state)
	{
		// メニュー./////////////////////////////////////////////////
	case STATE_MENU:
		// タイトルBGM
		PlaySoundMem(game.sound.gameBGM, DX_PLAYTYPE_LOOP, true);


		// 初期化
		// タイトルでイニシャライズを１度だけ行いたいフラグ
		if (game.stateInitFlag == false)
		{
			InitGameStart(game);
			game.player.changeStateFlag = false;
			//game.blendNumFrameCount = 255;
			game.stateInitFlag = true;
		}
		
		//メニュー画面
		UpdateMenu(game.menu,game.sound);
		UpdateMenuPlayer(game,game.player,game.menu);
		DrawPlayer(game.player);
		
		break;

		// ステージ１/////////////////////////////////////////////////
	case STATE_STAGE1:
		// 前のBGMをストップ
		//StopSoundMem(game.sound.menuBGM);

		// ゲームBGM


		// 画面を明るくする
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		ChangeBrightness(game);
		
		// ボス登場演出
		for (int i = 0; i < BG_NUM; i++)
		{
			if (game.gameFrameCount >= BOSS_ENTRY_FRAME - BOSS_ENTRY_DIRECTING_TIME)
			{
				UpdateBGHorizon(game.bgNext[i]);
			}
		}

		// 最初に自動移動を一度だけしたいのでフラグを使用
		if (game.player.moveEndFlag == false)
		{
			// プレイヤーを中央に自動的に移動させる
			if (game.player.obj.pos.y >= GAME_START_FRAME_COUNT)
			{
				game.player.obj.pos.y -= 3;
				game.gameFrameCount--;
			}
			else
			{
				game.player.moveEndFlag = true;
			}
		}
		else
		{
			//ゲームカウントの加算
			GetFrameCount(game);
			// プレイヤー、エネミーの処理
			UpdatePlayer(game.player, multiEnemy,game.enemy,ENEMY_OF_NUMBER,game);
			UpdateMultiEnemy(game.enemy, multiEnemy, game.player, ENEMY_OF_NUMBER,game);
			// アイテムの処理
			UpdateItem(game);
		}

		// ボスの処理（指定フレームカウントまで処理しない）
		if (game.gameFrameCount >= BOSS_ENTRY_FRAME)
		{
			UpdateEnemy(game.enemy, game.player,game);
		}

		// 背景の描画
		for (int i = 0; i < BG_NUM; i++)
		{
			UpdateBG(game.bg[i]);
		}

		// 敵が死んだらクリア状態に
		if (game.enemy.life <= 0)
		{
			game.enemy.bossDestroyTime++;
			// クリアしたら自動的に上に移動
			AutoMoveClearPlayer(game);
			if (game.enemy.bossDestroyTime >= BOSS_DESTROY_TIME)
			{
				ChangeGameState(STATE_CLEAR, game);
			}
		}
		// プレイヤーが死ぬとゲームオーバー
		else if ( game.player.life <= 0)
		{
			game.player.playerDeathFrameCount++;
			if (game.player.playerDeathFrameCount >= 200)
			{
				ChangeGameState(STATE_GAMEOVER, game);
			}
		}

		break;

		// ステージ２/////////////////////////////////////////////////
	case STATE_STAGE2:
		// 画面を明るくする
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		ChangeBrightness(game);


		// 最初に自動移動を一度だけしたいのでフラグを使用
		if (game.player.moveEndFlag == false)
		{
			// プレイヤーを中央に自動的に移動させる
			if (game.player.obj.pos.y >= GAME_START_FRAME_COUNT)
			{
				game.player.obj.pos.y -= 3;
				game.gameFrameCount--;
			}
			else
			{
				game.player.moveEndFlag = true;
			}
		}
		else
		{
			//ゲームカウントの加算
			GetFrameCount(game);
			// プレイヤー、エネミーの処理
			UpdatePlayer(game.player, multiEnemy, game.enemy, ENEMY_NUM_STAGE1,game);
			UpdateMultiEnemy(game.enemy, multiEnemy, game.player, ENEMY_NUM_STAGE1, game);
			// アイテムの処理
			UpdateItem(game);
		}

		// ボスの処理（指定フレームカウントまで処理しない）
		if (game.gameFrameCount >= BOSS_ENTRY_FRAME)
		{
			// ボスの当たり判定がおかしいので直で変更
			game.enemy.obj.w = 200;
			game.enemy.obj.h = 200;
			UpdateEnemy(game.enemy, game.player,game);
		}

		// 背景の描画
		for (int i = 0; i < BG_NUM; i++)
		{
			UpdateBG(game.bg[i]);
			if (game.gameFrameCount >= BOSS_ENTRY_FRAME - BOSS_ENTRY_DIRECTING_TIME)
			{
				UpdateBGHorizon(game.bgNext[i]);
			}
		}

		// 敵が死んだらクリア状態に
		if (game.enemy.life <= 0)
		{
			game.enemy.bossDestroyTime++;
			// クリアしたらプレイヤーを上に移動
			AutoMoveClearPlayer(game);
			if (game.enemy.bossDestroyTime >= BOSS_DESTROY_TIME)
			{
				ChangeGameState(STATE_CLEAR, game);
			}
		}
		// プレイヤーが死ぬとゲームオーバー
		else if (game.player.life <= 0)
		{
			game.player.playerDeathFrameCount++;
			if (game.player.playerDeathFrameCount >= 200)
			{
				ChangeGameState(STATE_GAMEOVER, game);
			}
		}

		break;

		//////////////////////////////////////////////////////////////////
		// ステージ３
		//////////////////////////////////////////////////////////////////
	case STATE_STAGE3:
		// 画面を明るくする
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		ChangeBrightness(game);


		// 最初に自動移動を一度だけしたいのでフラグを使用
			if (game.player.moveEndFlag == false)
			{
				// プレイヤーを中央に自動的に移動させる
				if (game.player.obj.pos.y >= GAME_START_FRAME_COUNT)
				{
					game.player.obj.pos.y -= 3;
					game.gameFrameCount--;
				}
				else
				{
					game.player.moveEndFlag = true;
				}
			}
			else
			{
				//ゲームカウントの加算
				GetFrameCount(game);
				// プレイヤー、エネミーの処理
				UpdatePlayer(game.player, multiEnemy, game.enemy, ENEMY_NUM_STAGE3,game);
				UpdateMultiEnemy(game.enemy, multiEnemy, game.player, ENEMY_NUM_STAGE3, game);
				// アイテムの処理
				UpdateItem(game);
			}

		// ボスの処理（指定フレームカウントまで処理しない）
		if (game.gameFrameCount >= BOSS_ENTRY_FRAME)
		{
			// ボスの当たり判定がおかしいので直で変更
			game.enemy.obj.w = 200;
			game.enemy.obj.h = 200;
			UpdateEnemy(game.enemy, game.player,game);
		}

		// 背景の描画
		for (int i = 0; i < BG_NUM; i++)
		{
			UpdateBG(game.bg[i]);
			if (game.gameFrameCount >= BOSS_ENTRY_FRAME - BOSS_ENTRY_DIRECTING_TIME)
			{
				UpdateBGHorizon(game.bgNext[i]);
			}
		}

		// ステージ変更処理
		// 敵が死んだらクリア状態に
		if (game.enemy.life <= 0)
		{
			game.enemy.bossDestroyTime++;
			// クリアしたら自動的にプレイヤーを上に移動
			AutoMoveClearPlayer(game);
			if (game.enemy.bossDestroyTime >= BOSS_DESTROY_TIME)
			{
				ChangeGameState(STATE_CLEAR, game);
			}
		}
		// プレイヤーが死ぬとゲームオーバー
		else if (game.player.life <= 0)
		{
			game.player.playerDeathFrameCount++;
			if (game.player.playerDeathFrameCount >= 200)
			{
				ChangeGameState(STATE_GAMEOVER, game);
			}
		}

		break;

		// クリア画面./////////////////////////////////////////////////
	case STATE_CLEAR:
		// ゲームクリアサウンド
		//PlaySoundMem(game.sound.gameClaerSE, DX_PLAYTYPE_BACK, true);
		
		// 背景の描画
		for (int i = 0; i < BG_NUM; i++)
		{
			UpdateCityBG(game.montain[i], 1);
			UpdateCityBG(game.city2[i], 2);
			UpdateCityBG(game.city[i], 3);
		}

		// キーが押されたらタイトルへ
		if (CheckHitKey(KEY_INPUT_SPACE) != 0 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)
		{
			game.stateInitFlag = false;
			ChangeGameState(STATE_MENU, game);
		}
		break;

		// ゲームオーバー./////////////////////////////////////////////////
	case STATE_GAMEOVER:
		// ゲームオーバーサウンド
		//PlaySoundMem(game.sound.gameOverSe, DX_PLAYTYPE_BACK, true);

		// 背景の描画
		for (int i = 0; i < BG_NUM; i++)
		{
			UpdateCityBG(game.montain[i],1);
			UpdateCityBG(game.city2[i], 2);
			UpdateCityBG(game.city[i],3);
		}

		

		// キーが押されたらタイトルへ
		if (CheckHitKey(KEY_INPUT_SPACE) != 0 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)
		{
			game.stateInitFlag = false;
			ChangeGameState(STATE_MENU, game);
		}
		break;
	default:
		break;
	}
}

// ゲーム描画
void DrawGame(Game& game)
{
	// 各描画関数を呼ぶ.
	// UI以外はゲーム中だけ描画する
	if (game.state == STATE_STAGE1 || game.state == STATE_STAGE2 || game.state == STATE_STAGE3)
	{
		
		for (int i = 0; i < BG_NUM; i++)
		{
			DrawBG(game.bg[i]);
			if (game.gameFrameCount >= BOSS_ENTRY_FRAME - BOSS_ENTRY_DIRECTING_TIME && game.gameFrameCount <= BOSS_ENTRY_FRAME)
			{
				DrawBGH(game.bgNext[i]);
				// ボス演出用SE
				if (game.bossEntryFlag == false)
				{
					PlaySoundMem(game.sound.bossEntrySE, DX_PLAYTYPE_BACK, true);
					game.bossEntryFlag = true;
				}
			}
		}
		// プレイヤーの影の描画（メニュー画面と、STAGE1は空中なので影は無し）
		if (game.state == STATE_STAGE2 || game.state == STATE_STAGE3)
		{
			DrawPlayerShadow(game);
		}
		DrawPlayer(game.player);
		if (game.gameFrameCount >= BOSS_ENTRY_FRAME)
		{
			DrawEnemy(game.enemy,game);
		}
		DrawMultiEnemy(game,multiEnemy, ENEMY_NUM_STAGE3);
	}
	DrawUI(game.ui, game);

	// テスト
	DrawItem(game.item);

	
}


// ベクトルの長さを求める
double GetVectorLength(VECTOR& vector)
{
	// ベクトルの長さは三角関数の定理よりXの２乗+Yの２乗の平方根
	return pow((vector.x * vector.x) + (vector.y * vector.y),0.5);
}

// ベクトルの内積を求める
double GetDotProduct(VECTOR& vector1, VECTOR& vector2)
{
	// ベクトルの内積はX成分、Y成分どおし掛け算
	return ((vector1.x * vector2.x) + (vector1.y * vector2.y));
}

// ベクトルのなす角を求める
double GetAngleOf2Vector(VECTOR& vector1, VECTOR& vector2)
{
	// ベクトルの長さを計算
	double _vector1Length = GetVectorLength(vector1);
	double _vector2Length = GetVectorLength(vector2);

	// 内積とベクトルの長さを使いcosΘを求める
	double _cosSita = GetDotProduct(vector1, vector2) / (_vector1Length * _vector2Length);

	// cosΘから角度Θを求める（ラジアンでの角度）
	double _sita = acos(_cosSita);

	// ラジアンを度数法に変換
	//_sita = _sita * 180.0 / PI;

	return _sita;

}



// 画面の暗転
void BlackOutScreen(Game& game)
{
	// フレーム数をカウント
	if (game.blendNumFrameCount > 0)
	{
		game.blendNumFrameCount-= 5;
	}
	else if (game.blendNumFrameCount <= 0)
	{
		game.blendNumFrameCount = 0;
	}

	// カウント数に応じて暗転
	game.screenBlendNum -= game.blendNumFrameCount;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, game.blendNumFrameCount);
}

// 画面を明るくする
void ChangeBrightness(Game& game)
{
	// フレーム数をカウント
	if (game.blendNumFrameCount < 255)
	{
		game.blendNumFrameCount+= 5;
	}
	// カウント数に応じて明るく
	game.screenBlendNum += game.blendNumFrameCount;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, game.blendNumFrameCount);


}




////////////////////////////////////////////////////////////////////////////////////////
// STAGE1
////////////////////////////////////////////////////////////////////////////////////////


void InitGameStartSTAGE1(Game& game)
{
	game.gameStartTime = GetNowCount();

	// ボスエントリーフラグの初期化
	game.bossEntryFlag = false;

	// フレーム数を初期化
	game.gameFrameCount = 0;

	InitUI(game.ui);
	InitPlayer(game.player);
	InitEnemySTAGE1(game.enemy);
	InitMultiEnemySTAGE1(game.enemy, multiEnemy, ENEMY_OF_NUMBER, game);

	// グラフィックをロードしてサイズを取得.
	int bgGraph = game.bg[0].obj.graph;

	// 注意！画面のサイズと背景画像のサイズは一緒じゃないとダメ
	bgGraph = LoadGraph("data/texture/GroundBG.png");
	
	// ワーニング用横スクロール画像
	int bgGraphHalf = game.bgNext[0].obj.graph;
	if (bgGraphHalf < 0)
	{
		bgGraphHalf = LoadGraph("data/texture/warningGraphLong.png");
	}

	for (int i = 0; i < BG_NUM; i++)
	{
		InitBG(game.bg[i], bgGraph, i);
		InitBGHorizon(game.bgNext[i], bgGraphHalf, i);
	}


	//メニュー画像をロードしてサイズを取得

	int menuGraph = game.menu.obj.graph;
	if (menuGraph < 0)
	{
		menuGraph = LoadGraph("data/texture/backimg.png");
	}
	//メニュー画面初期化
	InitMenu(game.menu, menuGraph);
}







////////////////////////////////////////////////////////////////////////////////////////
// STAGE2
////////////////////////////////////////////////////////////////////////////////////////

void InitGameStartSTAGE2(Game& game)
{
	game.gameStartTime = GetNowCount();

	// フレーム数を初期化
	game.gameFrameCount = 0;

	// ボスエントリーフラグの初期化
	game.bossEntryFlag = false;

	InitUI(game.ui);
	InitPlayer(game.player);
	InitEnemySTAGE2(game.enemy);
	InitMultiEnemySTAGE2(game.enemy, multiEnemy, ENEMY_NUM_STAGE3, game);

	// グラフィックをロードしてサイズを取得.
	int bgGraph = game.bg[0].obj.graph;

	// 注意！画面のサイズと背景画像のサイズは一緒じゃないとダメ
	bgGraph = LoadGraph("data/texture/STAGE2BGImg.png");

	// ワーニング用横スクロール画像
	int bgGraphHalf = game.bgNext[0].obj.graph;
	if (bgGraphHalf < 0)
	{
		bgGraphHalf = LoadGraph("data/texture/warningGraphLong.png");
	}

	for (int i = 0; i < BG_NUM; i++)
	{
		InitBG(game.bg[i], bgGraph, i);
		InitBGHorizon(game.bgNext[i], bgGraphHalf, i);
	}


	//メニュー画像をロードしてサイズを取得

	int menuGraph = game.menu.obj.graph;
	if (menuGraph < 0)
	{
		menuGraph = LoadGraph("data/texture/backimg.png");
	}
	//メニュー画面初期化
	InitMenu(game.menu, menuGraph);
}



// クリア時プレイヤーを自動的に移動させる
void AutoMoveClearPlayer(Game& game)
{
	// 画面中央に自動移動
	if (game.player.obj.pos.x >= 800)	// 画面の右側にいる
	{
		game.player.obj.pos.x -= 10;
	}
	if (game.player.obj.pos.x <= 800)	// 画面の左側にいる
	{
		game.player.obj.pos.x += 10;
	}
	if (game.player.obj.pos.y <= 480 && game.player.moveClearFlag == false)	// 画面の上にいる
	{
		game.player.obj.pos.y += 10;
	}
	else if(game.player.obj.pos.y <= 960)
	{
		game.player.obj.pos.y -= 2;
		game.player.moveClearFlag = true;
		// プレイヤーが画面上限上に到着したら、移動制限を超えて上に移動させる
		if (game.player.obj.pos.y >= 950)
		{
			game.player.obj.pos.y = 1200;
		}
	}

	

}

