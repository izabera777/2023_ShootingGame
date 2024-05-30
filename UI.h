#pragma once

// プロトタイプ宣言
struct Game;
struct GameObject;

// UIに使う文字列.
#define	TITLE_STR			"Bugs Shot"
#define	GAME_OVER_STR		"ゲームオーバー"
#define	GAME_CLEAR_STR		"ゲームクリア！"
#define	STARTBUTTON_STR		"スペースキーでスタート"
#define	RETURN_TITLE_STR	"スペースキーでタイトルへ"
#define	TIME_STR			"残り："

// UI用位置調整.
#define	TITLE_STR_OFFSET_Y		-100	// 見出し文字のyオフセット.
#define	PRESS_STR_OFFSET_Y		100		// ボタンを押してください系UIのyオフセット.
#define	TIME_STR_OFFSET_X		-100	// 制限時間(「残り」)のxオフセット.
#define	TIME_STR_POS_Y			25		// 残り時間UIのyポジション.
#define	TITLE_FONT_SIZE			64		// 見出し文字のフォントサイズ.
#define	PRESS_STR_FONT_SIZE		24		// ボタンを押してください系UIのサイズ.
#define	TIME_STR_FONT_SIZE		24		// 制限時間(「残り」)のフォントサイズ.
#define	TIME_NUM_STR_FONT_SIZE	40		// 制限時間(数字)のフォントサイズ.
#define	ENEMY_HP_STR_FONT_SIZE	24		// 敵体力のフォントサイズ.
#define	ENEMY_HP_STR_POS_Y		2		// 敵体力文字のyポジション.
#define	ENEMY_HP_STR_POS_X		10		// 敵体力文字のxポジション.
#define	ENEMY_HP_LEFT_OFFSET_X	80		// 敵体力の左からのオフセット.
#define	ENEMY_HP_RIGHT_OSSET_X	30		// 敵体力画像の右からのオフセット.
#define	ENEMY_HP_HIGHT			15		// 敵体力画像の高さ.
#define	PLAYER_HP_FONT_SIZE		10		// プレイヤーの体力サイズ.
#define	PLAYER_HP_OFFSET_Y		45		// プレイヤー体力のオフセット.
#define NUM_SIZE				50		// 数値を表示する際の大きさ

#define STAGE_NUMBER_DRAW_TIME	250		// ステージナンバーを表示する時間
#define STAGE_NUMBER_X			625		// ステージ文字を描画するX座標
#define STAGE_NUMBER_Y			300		// ステージ文字を描画するY座標
#define	ANNIHILATION_RATE_BUFF	100		// 殲滅率のバフ値（％表示にするため）

// プレイヤーの情報
#define PLAYER_SHADOW_ADJUST_Y		100		// プレイヤーの影を描画するためにズラすY値
#define PLAYER_SHADOW_ADJUST_X		20		// プレイヤーの影を描画するためにズラすX値
#define PLAYER_STATUS_POS_X			1425	// 機体情報描画X位置
#define PLAYER_STATUS_POS_Y			800		// 機体情報描画Y位置
#define PLAYER_NAME_POS_X			1450	// 機体名前描画X位置
#define PLAYER_NAME_POS_Y			600		// 機体名前描画Y位置
#define PLAYER_WEAPON_POS_X			1400	// 装備武装描画X位置
#define PLAYER_WEAPON_POS_Y			650		// 装備武装描画Y位置
#define PLAYER_WEAPON_X_BUF			-15		// 装備枠の位置調整バフ値
#define PLAYER_DMG_POS_X			1400	// ダメージ文字描画X位置
#define PLAYER_DMG_POS_Y			700		// ダメージ文字描画Y位置
#define PLAYER_STATUS_TEXT_X_BUF	100		// テキスト情報のX位置をずらすためのバフ値
#define PLAYER_DAMEGE_RATE_POS_X	1500	// 機体損傷率描画X位置
#define PLAYER_DAMEGE_RATE_POS_Y	735		// 機体損傷率描画Y位置
#define USE_WEAPON_TEXT_X			1495	// 装備武装文字X位置
#define USE_WEAPON_TEXT_Y			690		// 装備武装文字Y位置




// UI
struct UI
{
	// HP
	int		hpGraph = -1;
	int		hpBackGraph = -1;

	// プレイヤー 
	int		playerHpBarGraph = -1;			// HPバー
	int		playerHpBarNewGraph = -1;		// HPバー
	int		playerWeaponGraph = -1;			// 武装
	int		playerShadowGraph = -1;			// 影
	int		playerStatusRedGraph = -1;		// プレイヤーのHP状態を表す画像
	int		playerStatusYellowGraph = -1;	// プレイヤーのHP状態を表す画像
	int		playerStatusGreenGraph = -1;	// プレイヤーのHP状態を表す画像
	int		weaponFrameGraph = -1;			// プレイヤー装備武器のアイコンフレーム
	float	playerDamageRate = 0;			// プレイヤーの損傷率

	// ボス
	int		bossHpBarGraph;				// BOSSのHPバー
	int		warningGraph;				// BOSS登場時の画像
	int		bossHpBarNewGraph;
	GameObject	bossHpBarNewGraphObj;	// BOSSのHPバー

	// ステージ
	int		stage1StringGraph;	// ステージ１の文字画像
	int		stage2StringGraph;	// ステージ２の文字画像
	int		stage3StringGraph;	// ステージ３の文字画像

	// リザルト
	int		gameOverGraph;			// ゲームオーバー時の背景画像
	int		gameOverStringGraph;	// ゲームオーバー時の文字画像
	int		gameClearGraph;			// ゲームクリア時の背景画像
	int		gameClearStringGraph;	// ゲームクリア時の文字画像

	// ランク
	int		rankBaseGraph = -1;			// ランクを表示するための土台（紙のイラスト）
	int		rankStringGraph = -1;		// 「RANK」画像
	int		rankGraphSSS = -1;			// ランクSSS画像
	int		rankGraphS = -1;			// ランクS画像
	int		rankGraphA = -1;			// ランクA画像
	int		rankGraphB = -1;			// ランクB画像
	int		rankGraphC = -1;			// ランクC画像
	int		rankDescriptionGraph = -1;	// ランク説明画像

	// ダメージ時
	int		damageScreenGraph;				// プレイヤーがダメージを受けた際の画像
	int		bloodScreenGraphNext[3] = {-1};	// プレイヤーがダメージを受けた際の血がにじむ画像

	// オペレーター
	int		operatorCommentGraph1;	// 「すべての敵を撃破せよ」
	int		operatorCommentGraph2;	// 「その調子だ」
	int		operatorCommentGraph3;	// 「お前の力を見せてやれ」

	// クリア
	int		fireWorksGraph[21];		// 花火の画像
	int		fireWorkusCount = 0;	// 花火の描画したいカウント
	GameObject	clound;				// クリア時の雲
	GameObject	fighter;			// クリア時の戦闘機
	GameObject	mountain;			// クリア時の山の画像

	// 情報画像
	int		playerInfoNameGraph = -1;		// プレイヤーの機体情報
	int		playerInfoDmgGraph = -1;		// プレイヤーダメージ情報
	int		playerInfoWeaponGraph = -1;		// プレイヤー装備武装情報
	int		multiTextGraph = -1;			// multiの文字画像
	int		normalTextGraph = -1;			// normalの文字画像

};

// UI初期化.
void InitUI(UI& ui);

// UI描画.
void DrawUI(UI& ui, Game& game);

// 最終ランクの描画
void DrawFinalRank(UI& ui, Game& game);

// プレイヤー情報の描画
void DrawPlayerInfo(Game& game);

// プレイヤーの影の描画
void DrawPlayerShadow(Game& game);

// ボスHPバー描画
void DrawBossHPBar(Game& game);

// プレイヤーがダメージを受けた際に画面を少し赤くする
void DrawDamageScreen(Game& game);

// クリア時の画像描画
void DrawUpdateCleaer(Game& game);





