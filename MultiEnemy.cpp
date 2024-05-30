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


struct multiEnemy;

// エネミー出現テーブル
EnemyEntry enemyEntryDataBese[ENEMY_NUM_STAGE1] =
{
	// １０区切り

	// フレーム数　 x座標　  y座標  xスピード  ルーチンタイプ
	{        300,   500,   -100,      5,      VERTICAL_FIGHTER},
	{        325,   400,   -100,      5,      VERTICAL_FIGHTER},
	{        350,   300,   -100,      5,      VERTICAL_FIGHTER},
	{        400,  1100,   -100,      5,      VERTICAL_FIGHTER},
	{        425,  1200,   -100,      5,      VERTICAL_FIGHTER},
	{        450,  1300,   -100,      5,      VERTICAL_FIGHTER},
	{        500,   400,   -300,      5,      VERTICAL_FIGHTER},
	{        525,   600,   -200,      5,      VERTICAL_FIGHTER},
	{        525,  1000,   -200,      5,      VERTICAL_FIGHTER},
	{        500,  1200,   -300,      5,      VERTICAL_FIGHTER},
	// 10
	{        600,  -100,    480,      6,       HORIZON_FIGHTER},
	{        625,  -100,    380,      6,       HORIZON_FIGHTER},
	{        650,  -100,    280,      6,       HORIZON_FIGHTER},
	{        675,  -100,    180,      6,       HORIZON_FIGHTER},
	{        800,  -100,    300,      6,       HORIZON_FIGHTER},
	{        825,  -100,    300,      6,       HORIZON_FIGHTER},
	{        850,  -100,    300,      6,       HORIZON_FIGHTER},
	{        900,  -100,    150,      6,       HORIZON_FIGHTER},
	{        925,  -100,    150,      6,       HORIZON_FIGHTER},
	{        950,  -100,    150,      6,       HORIZON_FIGHTER},
	// 20
	{       1000,   200,   -150,      6,      VERTICAL_FIGHTER},
	{       1025,   300,   -150,      6,      VERTICAL_FIGHTER},
	{       1050,   400,   -150,      6,      VERTICAL_FIGHTER},
	{       1075,   300,   -150,      6,      VERTICAL_FIGHTER},
	{       1100,   200,   -150,      6,      VERTICAL_FIGHTER},
	{       1225,  1400,   -150,      6,      VERTICAL_FIGHTER},
	{       1250,  1300,   -150,      6,      VERTICAL_FIGHTER},
	{       1275,  1200,   -150,      6,      VERTICAL_FIGHTER},
	{       1300,  1300,   -150,      6,      VERTICAL_FIGHTER},
	{       1325,  1400,   -150,      6,      VERTICAL_FIGHTER},
	// 30
	{       1400,   800,   -150,      6,      VERTICAL_FIGHTER},
	{       1425,   700,   -150,      6,      VERTICAL_FIGHTER},
	{       1425,   900,   -150,      6,      VERTICAL_FIGHTER},
	{       1450,   600,   -150,      6,      VERTICAL_FIGHTER},
	{       1450,   800,   -150,      6,      VERTICAL_FIGHTER},
	{       1450,  1000,   -150,      6,      VERTICAL_FIGHTER},
	{       1475,   500,   -150,      6,      VERTICAL_FIGHTER},
	{       1475,   700,   -150,      6,      VERTICAL_FIGHTER},
	{       1475,   900,   -150,      6,      VERTICAL_FIGHTER},
	{       1475,  1100,   -150,      6,      VERTICAL_FIGHTER},
	// 40
	{       1600,  -100,    200,      5,      HORIZON_FIGHTER},
	{       1625,  -100,    200,      5,      HORIZON_FIGHTER},
	{       1650,  -100,    200,      5,      HORIZON_FIGHTER},
	{       1675,  -100,    200,      5,      HORIZON_FIGHTER},
	{       1700,  -100,    200,      5,      HORIZON_FIGHTER},
	{       1725,  1700,    400,      5,      HORIZON_REVERSE_FIGHTER},
	{       1750,  1700,    400,      5,      HORIZON_REVERSE_FIGHTER},
	{       1775,  1700,    400,      5,      HORIZON_REVERSE_FIGHTER},
	{       1800,  1700,    400,      5,      HORIZON_REVERSE_FIGHTER},
	{       1825,  1700,    400,      5,      HORIZON_REVERSE_FIGHTER},
	// 50
	{       1900,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       1925,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       1950,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       1975,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       2000,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       2025,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       2050,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       2075,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       2100,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       2125,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	// 60
	{       2100,   900,   -150,      6,      VERTICAL_FIGHTER},
	{       2125,   400,   -150,      6,      VERTICAL_FIGHTER},
	{       2150,   700,   -150,      6,      VERTICAL_FIGHTER},
	{       2175,  1000,   -150,      6,      VERTICAL_FIGHTER},
	{       2200,   250,   -150,      6,      VERTICAL_FIGHTER},
	{       2225,  1200,   -150,      6,      VERTICAL_FIGHTER},
	{       2250,   800,   -150,      6,      VERTICAL_FIGHTER},
	{       2275,   700,   -150,      6,      VERTICAL_FIGHTER},
	{       2300,   600,   -150,      6,      VERTICAL_FIGHTER},
	{       2325,   500,   -150,      6,      VERTICAL_FIGHTER},
	// 70
	{       2400,   400,   -100,      6,      VERTICAL_FIGHTER},
	{       2425,   200,   -100,      6,      VERTICAL_FIGHTER},
	{       2450,   300,   -100,      6,      VERTICAL_FIGHTER},
	{       2475,   400,   -100,      6,      VERTICAL_FIGHTER},
	{       2500,   500,   -100,      6,      VERTICAL_FIGHTER},
	{       2525,   600,   -100,      6,      VERTICAL_FIGHTER},
	{       2550,   700,   -100,      6,      VERTICAL_FIGHTER},
	{       2575,   800,   -100,      6,      VERTICAL_FIGHTER},
	{       2600,   900,   -100,      6,      VERTICAL_FIGHTER},
	{       2625,   800,   -100,      6,      VERTICAL_FIGHTER},
	// 80
	{       2725,   100,   -150,      5,      VERTICAL_FIGHTER},
	{       2750,   200,   -150,      5,      VERTICAL_FIGHTER},
	{       2775,   300,   -150,      5,      VERTICAL_FIGHTER},
	{       2800,   400,   -150,      5,      VERTICAL_FIGHTER},
	{       2825,   500,   -150,      5,      VERTICAL_FIGHTER},
	{       2850,   600,   -150,      5,      VERTICAL_FIGHTER},
	{       2875,   700,   -150,      5,      VERTICAL_FIGHTER},
	{       2900,   800,   -150,      5,      VERTICAL_FIGHTER},
	{       2925,   900,   -150,      5,      VERTICAL_FIGHTER},
	{       2950,  1000,   -150,      5,      VERTICAL_FIGHTER},
	// 90
	{       3000,   900,   -150,      3,      VERTICAL_FIGHTER},
	{       3025,   400,   -150,      3,      VERTICAL_FIGHTER},
	{       3050,   700,   -150,      3,      VERTICAL_FIGHTER},
	{       3075,  1000,   -150,      3,      VERTICAL_FIGHTER},
	{       3100,  -250,   -150,      3,      VERTICAL_FIGHTER},
	{       3000,   100,   -150,      3,      EDGE_MOVE_GROUND_WEAPON },
	{		3025,   100,   -150,      3,      EDGE_MOVE_GROUND_WEAPON },
	{		3050,   100,   -150,      3,      EDGE_MOVE_GROUND_WEAPON },
	{		3075,   100,   -150,      3,      EDGE_MOVE_GROUND_WEAPON },
	{		3100,   100,   -150,      3,      EDGE_MOVE_GROUND_WEAPON },
	// 100

};




// ステージ１のマルチエネミーのエントリー情報（ステージ１は地上）
EnemyEntry enemyEntryDataBeseSTAGE1[ENEMY_NUM_STAGE2] =
{
	// １０区切り

	// フレーム数　 x座標　  y座標   スピード  ルーチンタイプ
	{        200,  1500,   -100,     10,       EDGE_MOVE_GROUND_WEAPON},
	{        225,  1500,   -100,     10,       EDGE_MOVE_GROUND_WEAPON},
	{        250,  1500,   -100,     10,       EDGE_MOVE_GROUND_WEAPON},
	{        275,  1500,   -100,     10,       EDGE_MOVE_GROUND_WEAPON},
	{        300,  1500,   -100,     10,       EDGE_MOVE_GROUND_WEAPON},
	{        352,  1500,   -100,     10,       EDGE_MOVE_GROUND_WEAPON},
	{        500,   400,   -300,      6,       VERTICAL_GROUND_WEAPON},
	{        525,   600,   -200,      6,       VERTICAL_GROUND_WEAPON},
	{        525,  1000,   -200,      6,       VERTICAL_GROUND_WEAPON},
	{        500,  1200,   -300,      6,       VERTICAL_GROUND_WEAPON},
	// 10
	{        800,  -100,    200,      1,       SUB_BOSS_DUAL_USE},
	{        825,  -100,    380,      6,       HORIZON_GROUND_WEAPON},
	{        850,  -100,    280,      6,       HORIZON_GROUND_WEAPON},
	{        875,  -100,    180,      6,       HORIZON_GROUND_WEAPON},
	{        900,  -100,    300,      6,       HORIZON_GROUND_WEAPON},
	{        925,  -100,    300,      6,       HORIZON_GROUND_WEAPON},
	{        950,  -100,    300,      6,       HORIZON_GROUND_WEAPON},
	{        975,  -100,    150,      6,       HORIZON_GROUND_WEAPON},
	{       1000,  -100,    150,      6,       HORIZON_GROUND_WEAPON},
	{       1025,  -100,    150,      6,       HORIZON_GROUND_WEAPON},
	// 20
	{       1100,   200,   -150,      6,       VERTICAL_GROUND_WEAPON},
	{       1125,   300,   -150,      6,       VERTICAL_GROUND_WEAPON},
	{       1150,   400,   -150,      6,       VERTICAL_GROUND_WEAPON},
	{       1175,   300,   -150,      6,       VERTICAL_GROUND_WEAPON},
	{       1200,   200,   -150,      6,       VERTICAL_GROUND_WEAPON},
	{       1225,  1400,   -150,      6,       VERTICAL_GROUND_WEAPON},
	{       1250,  1300,   -150,      6,       VERTICAL_GROUND_WEAPON},
	{       1275,  1200,   -150,      6,       VERTICAL_GROUND_WEAPON},
	{       1300,  1300,   -150,      6,       VERTICAL_GROUND_WEAPON},
	{       1325,  1400,   -150,      6,       VERTICAL_GROUND_WEAPON},
	// 30
	{       1400,   800,   -150,      8,       VERTICAL_GROUND_WEAPON},
	{       1425,   700,   -150,      8,       VERTICAL_GROUND_WEAPON},
	{       1450,   900,   -150,      8,       VERTICAL_GROUND_WEAPON},
	{       1475,   600,   -150,      8,       VERTICAL_GROUND_WEAPON},
	{       1500,   800,   -150,      8,       VERTICAL_GROUND_WEAPON},
	{       1525,  1000,   -150,      8,       VERTICAL_GROUND_WEAPON},
	{       1550,   500,   -150,      8,       VERTICAL_GROUND_WEAPON},
	{       1575,   700,   -150,      8,       VERTICAL_GROUND_WEAPON},
	{       1600,   900,   -150,      8,       VERTICAL_GROUND_WEAPON},
	{       1625,  1100,   -150,      8,       VERTICAL_GROUND_WEAPON},
	// 40
	{       1700,  -100,    200,      6,      HORIZON_GROUND_WEAPON},
	{       1725,  -100,    200,      6,      HORIZON_GROUND_WEAPON},
	{       1750,  -100,    200,      6,      HORIZON_GROUND_WEAPON},
	{       1775,  -100,    200,      6,      HORIZON_GROUND_WEAPON},
	{       1800,  -100,    200,      6,      HORIZON_GROUND_WEAPON},
	{       1825,  1700,    400,      6,      HORIZON_REVERSE_FIGHTER},
	{       1850,  1700,    400,      6,      HORIZON_REVERSE_FIGHTER},
	{       1875,  1700,    400,      6,      HORIZON_REVERSE_FIGHTER},
	{       1900,  1700,    400,      6,      HORIZON_REVERSE_FIGHTER},
	{       1925,  1700,    400,      6,      HORIZON_REVERSE_FIGHTER},
	// 50
	{       2000,   1400,   -150,      6,      EDGE_MOVE_GROUND_WEAPON},
	{       2025,   1400,   -150,      6,      EDGE_MOVE_GROUND_WEAPON},
	{       2050,   1400,   -150,      6,      EDGE_MOVE_GROUND_WEAPON},
	{       2075,   1400,   -150,      6,      EDGE_MOVE_GROUND_WEAPON},
	{       2100,   1400,   -150,      6,      EDGE_MOVE_GROUND_WEAPON},
	{       2125,   1400,   -150,      6,      EDGE_MOVE_GROUND_WEAPON},
	{       2150,   1400,   -150,      6,      EDGE_MOVE_GROUND_WEAPON},
	{       2175,   1400,   -150,      6,      EDGE_MOVE_GROUND_WEAPON},
	{       2200,   1400,   -150,      6,      EDGE_MOVE_GROUND_WEAPON},
	{       2225,   1400,   -150,      6,      EDGE_MOVE_GROUND_WEAPON},
	//60 
	{       2300,   1500,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2325,   1500,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2350,   1500,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2375,   1500,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2400,   1500,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2425,   1400,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2450,   1400,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2475,   1400,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2500,   1400,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2525,   1400,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	// 70
	{       2600,   900,   -150,      6,      VERTICAL_GROUND_WEAPON},
	{       2625,   400,   -150,      6,      VERTICAL_GROUND_WEAPON},
	{       2650,   700,   -150,      6,      VERTICAL_GROUND_WEAPON},
	{       2675,  1000,   -150,      6,      VERTICAL_GROUND_WEAPON},
	{       2700,  1250,   -150,      6,      VERTICAL_GROUND_WEAPON},
	{       2725,  1200,   -150,      6,      VERTICAL_GROUND_WEAPON},
	{       2750,   800,   -150,      6,      VERTICAL_FIGHTER},
	{       2775,   100,   -150,      6,      VERTICAL_FIGHTER},
	{       2800,   200,   -150,      6,      VERTICAL_FIGHTER},
	{       2825,   600,   -150,      6,      VERTICAL_FIGHTER},
	// 80
	{       2900,   900,   -150,      6,      VERTICAL_GROUND_WEAPON},
	{       2925,   400,   -150,      6,      VERTICAL_GROUND_WEAPON},
	{       2950,   700,   -150,      6,      VERTICAL_GROUND_WEAPON},
	{       2975,  1000,   -150,      6,      VERTICAL_GROUND_WEAPON},
	{       3000,  1250,   -150,      6,      VERTICAL_GROUND_WEAPON},
	{       3025,  1200,   -150,      6,      VERTICAL_GROUND_WEAPON},
	{       3050,   800,   -150,      6,      VERTICAL_FIGHTER},
	{       3075,   100,   -150,      6,      VERTICAL_FIGHTER},
	{       3100,   200,   -150,      6,      VERTICAL_FIGHTER},
	{       3125,   600,   -150,      6,      VERTICAL_FIGHTER},
	// 90
	{		3200,   900,   -150,      6,      VERTICAL_GROUND_WEAPON },
	{		3225,   400,   -150,      6,      VERTICAL_GROUND_WEAPON },
	{		3250,   700,   -150,      6,      VERTICAL_GROUND_WEAPON },
	{		3275,  1000,   -150,      6,      VERTICAL_GROUND_WEAPON },
	{		3300,  1250,   -150,      6,      VERTICAL_GROUND_WEAPON },
	{		3325,  1200,   -150,      6,      VERTICAL_GROUND_WEAPON },
	{		3350,   800,   -150,      6,      VERTICAL_GROUND_WEAPON },
	{		3375,   100,   -150,      6,      VERTICAL_GROUND_WEAPON },
	{		3400,   200,   -150,      6,      VERTICAL_GROUND_WEAPON },
	{		3425,   600,   -150,      6,      VERTICAL_GROUND_WEAPON },
	// 100

};



// ステージ２のエネミー登場テーブル
EnemyEntry enemyEntryDataBeseSTAGE2[ENEMY_NUM_STAGE3] =
{
	// １０区切り

	// フレーム数　 x座標　  y座標  xスピード  ルーチンタイプ
	{        200,   500,   -100,      6,      VERTICAL_FIGHTER},
	{        225,  -600,    200,      2,      SUB_BOSS_CRUISERS},
	{        250,   300,   -100,      6,      VERTICAL_FIGHTER},
	{        325,  1100,   -100,      6,      VERTICAL_FIGHTER},
	{        350,  1200,   -100,      6,      VERTICAL_FIGHTER},
	{        375,  1300,   -100,      6,      VERTICAL_FIGHTER},
	{        400,   400,   -300,      6,      VERTICAL_FIGHTER},
	{        450,   600,   -200,      11,      VERTICAL_FIGHTER},
	{        450,  1000,   -200,      11,      VERTICAL_FIGHTER},
	{        400,  1200,   -300,      11,      VERTICAL_FIGHTER},
	// 10
	{        500,  -100,    480,      6,       HORIZON_FIGHTER},
	{        525,  -100,    380,      6,       HORIZON_FIGHTER},
	{        550,  -100,    280,      6,       HORIZON_FIGHTER},
	{        575,  -100,    180,      6,       HORIZON_FIGHTER},
	{        600,  -100,    300,      6,       HORIZON_FIGHTER},
	{        500,  -100,    300,      10,       HORIZON_FIGHTER},
	{        525,  -100,    300,      10,       HORIZON_FIGHTER},
	{        550,  -100,    150,      10,       HORIZON_FIGHTER},
	{        575,  -100,    150,      10,       HORIZON_FIGHTER},
	{        600,  -100,    150,      10,       HORIZON_FIGHTER},
	// 20
	{        700,   1500,   -150,     15,      EDGE_MOVE_GROUND_WEAPON},
	{        725,   1500,   -150,     15,      EDGE_MOVE_GROUND_WEAPON},
	{        750,   1500,   -150,     15,      EDGE_MOVE_GROUND_WEAPON},
	{        775,   1500,   -150,     15,      EDGE_MOVE_GROUND_WEAPON},
	{        800,   1500,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{        825,   1200,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{        850,   1200,   -150,     18,      EDGE_MOVE_GROUND_WEAPON},
	{        875,   1200,   -150,     18,      EDGE_MOVE_GROUND_WEAPON},
	{        900,   1200,   -150,     18,      EDGE_MOVE_GROUND_WEAPON},
	{        925,   1200,   -150,     18,      EDGE_MOVE_GROUND_WEAPON},
	// 30
	{       1000,  1100,   -150,      12,      VERTICAL_FIGHTER},
	{       1025,  1000,   -150,      12,      VERTICAL_FIGHTER},
	{       1050,   900,   -150,      4,       VERTICAL_FIGHTER},
	{       1050,   900,   -150,      4,       VERTICAL_FIGHTER},
	{       1075,   800,   -150,      6,       VERTICAL_FIGHTER},
	{       1075,   800,   -150,      6,       VERTICAL_FIGHTER},
	{       1100,   700,   -150,      10,      VERTICAL_FIGHTER},
	{       1100,   700,   -150,      10,      VERTICAL_FIGHTER},
	{       1125,   600,   -150,      9,       VERTICAL_FIGHTER},
	{       1125,   500,   -150,      9,       VERTICAL_FIGHTER},
	// 40
	{       1200,  -100,    200,      6,      HORIZON_FIGHTER},
	{       1225,  -100,    200,      6,      HORIZON_FIGHTER},
	{       1250,  -100,    200,      6,      HORIZON_FIGHTER},
	{       1275,  -700,    200,      2,      SUB_BOSS_CRUISERS},
	{       1350,  -600,    500,      1,      SUB_BOSS_CRUISERS},
	{       1200,  1700,    400,      9,      HORIZON_REVERSE_FIGHTER},
	{       1225,  1700,    400,      9,      HORIZON_REVERSE_FIGHTER},
	{       1250,  1700,    400,      9,      HORIZON_REVERSE_FIGHTER},
	{       1275,  1700,    400,      9,      HORIZON_REVERSE_FIGHTER},
	{       1300,  1700,    400,      9,      HORIZON_REVERSE_FIGHTER},
	// 50
	{       1400,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       1425,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       1450,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       1475,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       1500,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       1525,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       1550,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       1575,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       1600,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	{       1625,  -100,    100,      6,      RIGHT_ANGLE_FIGHTER},
	// 60
	{       1800,   800,   -150,      6,      VERTICAL_FIGHTER},
	{       1800,   700,   -175,      6,      VERTICAL_FIGHTER},
	{       1800,   900,   -175,      6,      VERTICAL_FIGHTER},
	{       1800,   600,   -200,      6,      VERTICAL_FIGHTER},
	{       1800,   800,   -200,      6,      VERTICAL_FIGHTER},
	{       1800,  1000,   -200,      6,      VERTICAL_FIGHTER},
	{       1800,   500,   -150,      6,      VERTICAL_FIGHTER},
	{       1800,   700,   -150,      6,      VERTICAL_FIGHTER},
	{       1800,   900,   -150,      6,      VERTICAL_FIGHTER},
	{       1800,  1100,   -150,      6,      VERTICAL_FIGHTER},
	// 70
	{       1900,   300,   -150,      7,      VERTICAL_FIGHTER},
	{       1925,   300,   -150,      6,      VERTICAL_FIGHTER},
	{       1950,   300,   -150,      7,      VERTICAL_FIGHTER},
	{       1975,   300,   -150,      6,      VERTICAL_FIGHTER},
	{       2000,   300,   -150,      7,      VERTICAL_FIGHTER},
	{       1900,  1200,   -150,      6,      VERTICAL_FIGHTER},
	{       1925,  1200,   -150,      6,      VERTICAL_FIGHTER},
	{       1950,  1200,   -150,      6,      VERTICAL_FIGHTER},
	{       1975,  1200,   -150,      6,      VERTICAL_FIGHTER},
	{       2000,  -600,   500,      1,      SUB_BOSS_CRUISERS},
	// 80
	{       2000,   800,   -150,      8,      VERTICAL_FIGHTER},
	{       2025,   900,   -150,      8,      VERTICAL_FIGHTER},
	{       2050,  1000,   -150,      8,      VERTICAL_FIGHTER},
	{       2075,   800,   -250,      8,      VERTICAL_FIGHTER},
	{       2000,  -600,    200,      4,     SUB_BOSS_CRUISERS},
	{       2025,  -100,   -150,      6,      HORIZON_FIGHTER},
	{       2050,  -100,   -150,      6,      HORIZON_FIGHTER},
	{       2075,  1700,   -150,      6,      HORIZON_REVERSE_FIGHTER},
	{       2100,  1700,   -150,      6,      HORIZON_REVERSE_FIGHTER},
	{       2125,  1700,   -150,      6,      HORIZON_REVERSE_FIGHTER },
	// 90
	{       2200,  1500,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2225,  1500,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2250,  1500,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2275,  1500,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2300,  1500,   -150,     10,      EDGE_MOVE_GROUND_WEAPON},
	{       2250,  -100,    200,      3,      SUB_BOSS_DUAL_USE},
	{       2375,  1400,   -150,      6,      VERTICAL_FIGHTER},
	{       2400,  1300,   -150,      6,      VERTICAL_FIGHTER},
	{       2425,  1200,   -150,      6,      VERTICAL_FIGHTER},
	{       2450,  1100,   -150,      6,      VERTICAL_FIGHTER},
	// 100

};









//----------------------------//
// エネミー関数群.
//----------------------------//


// 初期化.
void InitMultiEnemy(Enemy& enemy,Enemy multiEnemy[], int size,Game& game)
{
	//初期位置の設定
	for (int i = 0; i < size; i++)
	{
		//multiEnemy[i].obj.pos.x = enemyEntryDataBese[i].x + (i * ENEMY_MOVE_MARGIN);
		multiEnemy[i].obj.pos.x = enemyEntryDataBese[i].x;
		multiEnemy[i].obj.pos.y = enemyEntryDataBese[i].y + 10;
		multiEnemy[i].obj.speed = enemyEntryDataBese[i].speed;
		multiEnemy[i].obj.angle = GetRadian(180.0f);
		multiEnemy[i].life		= ENEMY_LIFE;
		multiEnemy[i].alive		= false;			// エントリーフレーム時間になるまでは生きていない
		multiEnemy[i].enemyEntry.routine = enemyEntryDataBese[i].routine;
	}

	// エネミーのグラフィックをメモリにロード＆表示座標を初期化
	char* enemyGlaphStr				= "data/texture/SubBossDamege.png";


	char* enemyVerticalGraph		= "data/texture/enemyVertical.png";			// 垂直敵
	char* enemyHorizonGraph			= "data/texture/enemyHorizon.png";			// 平行
	char* enemyHorizonReverseGraph	= "data/texture/enemyHorizonReverse.png";	// 逆平行
	char* enemyRightAngleGraph		= "data/texture/enemyRightAngle.png";		// 


	for (int i = 0; i < size; i++)
	{
		// 垂直移動エネミー画像ロード
		if (multiEnemy[i].enemyEntry.routine == VERTICAL_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyVerticalGraph);
		}
		if ( multiEnemy[i].enemyEntry.routine == HORIZON_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyHorizonGraph);
		}
		if ( multiEnemy[i].enemyEntry.routine == HORIZON_REVERSE_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyHorizonReverseGraph);
		}
		if ( multiEnemy[i].enemyEntry.routine == RIGHT_ANGLE_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyRightAngleGraph);
		}
		if (multiEnemy[i].damageGraph < 0)
		{
			multiEnemy[i].damageGraph = LoadGraph(enemyGlaphStr);
		}
	}

	// エネミーの撃破時の分割画像メモリにロード (一旦game.enemyから入って1つ分作ってから、マルチエネミーにコピーする)
	LoadDivGraph("data/texture/ExplosionGraph.png", ENEMY_DESTROY_GRAPH_TOTAL, ENEMY_DESTROY_GRAPH_X_NUM, ENEMY_DESTROY_GRAPH_Y_NUM, 64, 64, game.enemy.destroyGraph);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < ENEMY_DESTROY_GRAPH_TOTAL; j++)
		{
			// エネミー撃破時の画像表示のためのフレーム保持関数の初期化
			multiEnemy[i].destroyFlameCount = 0;
		}
	}
	
	// エネミー撃破時に獲得数スコアの分割画像をメモリにロード
	LoadDivGraph("data/texture/pointGraph.png", SCORE_IMAGES_TOTAL, SCORE_IMAGES_X_NUM, SCORE_IMAGES_Y_NUM, SCORE_IMAGES_SIZE_X, SCORE_IMAGES_SIZE_Y, enemy.scoreDestroyGraph);

	// 『ダメージをうけていない』を表すFALSEを代入
	for (int i = 0; i < size; i++)
	{
		multiEnemy[i].damageFlag = false;
	}
	
	// エネミーの登場テーブルの設定
	for (int i = 0; i < size; i++)
	{
		multiEnemy[i].enemyEntry.frame = enemyEntryDataBese[i].frame;
	}
	
	//// エネミーのグラフィックのサイズを得る
	//GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);

	// マルチエネミー用のグラフィックサイズを得る
	int multiEnemyGraphSize;
	//multiEnemyGraphSize = GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);
	for (int i = 0; i < size; i++)
	{
		GetGraphSize(multiEnemy[i].obj.graph, &multiEnemy[i].obj.w, &multiEnemy[i].obj.h);
	}


	// ショットを初期化
	int shotGraph	= enemy.shot[0].obj.graph;
	int shotW		= enemy.shot[0].obj.w;
	int shotH		= enemy.shot[0].obj.h;
	if (shotGraph < 0)
	{
		shotGraph	= LoadGraph("data/texture/SuperEnemyShot.png");
		GetGraphSize(shotGraph, &enemy.obj.w, &enemy.obj.h);
	}
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		InitShot(enemy.shot[i], shotGraph, shotW, shotH, GetRadian(180.0f), ENEMY_SHOT_SPEED, ENEMY_SHOT_POWER);
	}

	// マルチエネミーのショットの初期化
	for (int i = 0; i < size; i++)
	{
		shotGraph = LoadGraph("data/texture/enemyShotGraph.png");
		GetGraphSize(shotGraph, &multiEnemy[i].obj.w, &multiEnemy[i].obj.h);
	}

	// ショットのパワーの設定
	for (int i = 0; i < size; i++)
	{
		InitShot(multiEnemy[i].shot[i], shotGraph, shotW, shotH, GetRadian(180.0f), ENEMY_SHOT_SPEED, ENEMY_SHOT_POWER);
	}
}


// マルチエネミーの移動ルーチンに沿ったベクトルの調節
// ここでは方向のみ設定
void MoveRoutinesMultiEnemy(Enemy multiEnemy[], int size)
{
	// 移動ルーチンの参照
	// チュートリアル
	for (int i = 0; i < size; i++)
	{
		// 垂直移動（上→下）
		if (VERTICAL_FIGHTER == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(0, 1, 0);
		}
		// 平行移動（左→右）
		if (HORIZON_FIGHTER == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(1, 0, 0);
		}
		// 平行移動（右→左）
		if (HORIZON_REVERSE_FIGHTER == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(-1, 0, 0);
		}
		// 直角移動（右→下）
		if (RIGHT_ANGLE_FIGHTER == multiEnemy[i].enemyEntry.routine)
		{
			if (multiEnemy[i].obj.pos.x <= 800)
			{
				multiEnemy[i].obj.dir = VGet(1, 0, 0);
			}
			if (multiEnemy[i].obj.pos.x >= 800)
			{
				multiEnemy[i].obj.dir = VGet(0, 1, 0);
			}

			
		}

		// 地上兵器（STAGE1）
		// 垂直移動（上→下）
		if (VERTICAL_GROUND_WEAPON == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(0, 1, 0);
		}
		// 平行移動（左→右）
		if (HORIZON_GROUND_WEAPON == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(1, 0, 0);
		}
		// 平行移動（右→左）
		if (RIGHT_DIAGONAL_GRAOUND_WEAPON == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(-1, 0, 0);
		}
		// 直角移動（右→下）
		if (ZIGZAG_GROUND_WEAPON == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].moveCount++;
			if (multiEnemy[i].moveCount < 400)
			{
				multiEnemy[i].obj.dir = VGet(2, 0, 0);
			}
			if (multiEnemy[i].moveCount > 400)
			{
				multiEnemy[i].obj.dir = VGet(0, 1, 0);
			}
			if (multiEnemy[i].moveCount >= 800)
			{
				multiEnemy[i].moveCount = 0;
			}
		}

		// U字移動
		if (EDGE_MOVE_GROUND_WEAPON == multiEnemy[i].enemyEntry.routine)
		{
			if (multiEnemy[i].obj.pos.y <= 600)
			{
				multiEnemy[i].obj.dir = VGet(0, 1, 0);
			}
			if(multiEnemy[i].obj.pos.y >= 600)
			{
				multiEnemy[i].obj.dir = VGet(-1, 0, 0);
			}
			if (multiEnemy[i].obj.pos.x <= 100)
			{
				multiEnemy[i].obj.dir = VGet(0, -1, 0);
			}

		}

		// 中ボス
		if (SUB_BOSS_DUAL_USE == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet( 1, 0, 0);
		}

		// 巡洋艦	左から右移動
		if (SUB_BOSS_CRUISERS == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(1, 0, 0);
			multiEnemy[i].obj.w = 400;
			multiEnemy[i].obj.h = 50;
		}


		// 移動スピードはエントリー情報を参照

	}
}



// アップデート.
void UpdateMultiEnemy(Enemy& enemy,Enemy multiEnemy[], Player& player,int size,Game& game)
{
	// マルチエネミーの移動ルーチンに沿ったベクトルの調節(方向)
	MoveRoutinesMultiEnemy(multiEnemy, size);

	//エネミー移動
	for (int i = 0; i < size; i++)
	{
		if (multiEnemy[i].alive == true)
		{
			MoveGameObject(multiEnemy[i].obj);
		}
	}

	// エネミー画面外に出ている、HPが０の時 alive = false
	for (int i = 0; i < size; i++)
	{
		// HPがない場合
		if (multiEnemy[i].life <= 0)
		{
			multiEnemy[i].alive = false;
		}
		//右端に出た場合
		if (multiEnemy[i].obj.pos.x > SCREEN_W - multiEnemy[i].obj.w)
		{
			multiEnemy[i].alive = false;
		}
		else if (multiEnemy[i].obj.pos.x < 0)
		{
			multiEnemy[i].alive = false;
		}

	}

	// 敵弾が自機の方向を狙うフレーム数
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < ENEMY_SHOT; j++)
		{
			multiEnemy[i].shot[j].canTrunFrameTime++;		
			if (multiEnemy[i].shot[j].canTrunFrameTime >= 30)
			{
				multiEnemy[i].shot[j].canTrunFrameTime = 0;
			}
		}
	}
	// 敵の弾の発射処理
	for (int i = 0; i < size; i++)
	{
		// ショットの発射インターバルがなくなっていたら撃つ
		if (multiEnemy[i].shotIntervalCount == 0 && multiEnemy[i].life > 0)
		{
			// 画面上にでていない弾があるか、弾の数だけ繰り返して調べる
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < ENEMY_SHOT; j++)
				{
					// 弾iが画面上にでていない場合はその弾を画面に出す
					if (multiEnemy[i].shot[j].visibleFlag == false)
					{
						if (multiEnemy[i].life != 0 && multiEnemy[i].alive == true)
						{
							// 弾iの位置をセット、位置は敵の中心にする
							multiEnemy[i].shot[j].obj.pos.x = multiEnemy[i].obj.pos.x;
							multiEnemy[i].shot[j].obj.pos.y = multiEnemy[i].obj.pos.y;

							// 弾iは現時点を持って存在するので、存在状態を保持する変数にtrueを代入する
							multiEnemy[i].shot[j].visibleFlag = true;

							// 打つ方向の設定
							// 打たれてから15フレームの間は敵弾の方向をプレイヤーに向ける
							if (multiEnemy[i].shot[j].canTrunFrameTime <= 15)
							{
								//	プレイヤー　- ショット   ベクトルAB = B - A
								multiEnemy[i].shot[j].obj.dir = VSub(player.obj.pos, multiEnemy[i].shot[j].obj.pos);
							}
							if (VSize(multiEnemy[i].obj.dir) > 0)
							{
								multiEnemy[i].shot[j].obj.dir = VNorm(multiEnemy[i].shot[j].obj.dir);
							}
							VECTOR shotVelocity = VScale(multiEnemy[i].obj.dir, ENEMY_SHOT_SPEED);
							multiEnemy[i].shot[j].obj.pos = VAdd(multiEnemy[i].obj.pos, shotVelocity);

							// 一つ弾を出したので弾を出すループから抜けます
							break;
						}
					}
				}
			}

			// インターバル用のカウンターを設定.
			if (multiEnemy[i].enemyEntry.routine == SUB_BOSS_CRUISERS)
			{
				multiEnemy[i].shotIntervalCount = 5;
			}
			else
			{
				multiEnemy[i].shotIntervalCount = ENEMY_SHOT_INTERVAL;
			}
		}
	}
	// エネミーのショットの連射力を管理
	for (int i = 0; i < size; i++)
	{
		if (multiEnemy[i].shotIntervalCount != 0)
		{
			--multiEnemy[i].shotIntervalCount;
		}
	}

	// 当たり判定
	// ショット処理
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < ENEMY_SHOT; j++)
		{
			// ショット移動
			MoveShot(multiEnemy[i].shot[j]);
			
			// エネミーのショットとプレイヤーの当たり判定
			if (IsHitShot(multiEnemy[i].shot[j], player.obj))
			{
				// あたってたらショットパワー分ダメージを与える
				if (player.life > 0)
				{
					// プレイヤー被弾時のサウンド
					PlaySoundMem(game.sound.playerShotSE, DX_PLAYTYPE_BACK, true);

					player.life -= multiEnemy[i].shot[j].power;
					player.damageCounter	= 0;
					player.damageFlag		= true;
					// 連続で当たらないように抜ける
					break;
				}

				

			}
		}
	}

	// ダメージを受けているかどうかで処理を分岐
	for (int i = 0; i < size; i++)
	{
		if (multiEnemy[i].damageFlag == true)
		{
			multiEnemy[i].damageCounter++;

			if (multiEnemy[i].damageCounter == 5)
			{
				// 『ダメージをうけていない』を表すFALSEを代入
				multiEnemy[i].damageFlag = false;
			}
		}
	}
}


// 描画.
void DrawMultiEnemy(Game& game,Enemy multiEnemy[], int size)
{
	
	int _destroyIndex = 0;	// エネミー撃破時の画像の添え字

	for (int i = 0; i < size; i++)
	{
		// 自分のフレーム時間かつ、HPがある時、画面上に存在している時かつ
		if (game.gameFrameCount >= multiEnemy[i].enemyEntry.frame && 0 < multiEnemy[i].life)
		{
			// エントリーフレーム時間になったら生きている
			multiEnemy[i].alive = true;
			// ダメージを受けている場合はダメージ時のグラフィックを描画する
			if (multiEnemy[i].damageFlag == true)
			{
				// 普通の画像も描画
				DrawGameObject(multiEnemy[i].obj, multiEnemy[i].obj.graph);
				
				// サブボスだった場合添え字を抽出
				if (multiEnemy[i].enemyEntry.routine == SUB_BOSS_CRUISERS || multiEnemy[i].enemyEntry.routine == SUB_BOSS_DUAL_USE)
				{
					game.subBossIndex = i;
				}

				// 撃破時の画像表示
				if (multiEnemy[i].destroyFlameCount <= 65)
				{
					// 撃破されてからのフレームカウントを１０で割り添え字を出す
					DrawGameObject(multiEnemy[i].obj, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT]);
					DrawGraph(multiEnemy[i].obj.pos.x - 100, multiEnemy[i].obj.pos.y -  20, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT], true);
					DrawGraph(multiEnemy[i].obj.pos.x - 250, multiEnemy[i].obj.pos.y + 100, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT], true);
					DrawGraph(multiEnemy[i].obj.pos.x + 230, multiEnemy[i].obj.pos.y +  20, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT], true);
					DrawGraph(multiEnemy[i].obj.pos.x +  10, multiEnemy[i].obj.pos.y +   50, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT], true);
					DrawGraph(multiEnemy[i].obj.pos.x +  10, multiEnemy[i].obj.pos.y -   50, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT], true);

					// エネミーが撃破されてからのフレームカウント
					multiEnemy[i].destroyFlameCount++;
				}

			}
			else if(multiEnemy[i].alive == true)
			{
				DrawGameObject(multiEnemy[i].obj, multiEnemy[i].obj.graph);
			}
		}

		if (multiEnemy[game.subBossIndex].destroyFlameCount <= 65)
		{
			DrawGameObject(multiEnemy[game.subBossIndex].obj, game.enemy.destroyGraph[multiEnemy[game.subBossIndex].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT]);
		}


		// 撃破時の画像表示
		if (multiEnemy[i].life <= 0 && multiEnemy[i].destroyFlameCount <= 65)	
		{
			// 撃破されてからのフレームカウントを5で割り添え字を出す
			DrawGameObject(multiEnemy[i].obj, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT]);
			
			if (multiEnemy[i].life <= 0 && multiEnemy[i].destroyFlameCount < 50)
			{
				// 描画位置を撃破位置の少し上に移動
				CopySocreObject(game.enemy, multiEnemy, i);

				// 撃破時のスコア演出（画像描画）
				DrawGameObject(game.enemy.scoreObj, game.enemy.scoreDestroyGraph[multiEnemy[i].destroyFlameCount / SCORE_IMAGES_DRAW_COUNT]);
			}

			// エネミーが撃破されてからのフレームカウント
			multiEnemy[i].destroyFlameCount++;
		}
	}

	// ショットの表示
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < ENEMY_SHOT; j++)
		{
			// ショットも表示
			DrawShot(multiEnemy[i].shot[j]);
		}
	}
}


// スコア描画位置を調整するため、scoreObjに実際の情報をコピー
void CopySocreObject(Enemy& enemy,Enemy multiEnemy[],int arrayNum)
{
	// 少し上にずらす
	enemy.scoreObj.pos.x = multiEnemy[arrayNum].obj.pos.x;
	enemy.scoreObj.pos.y = multiEnemy[arrayNum].obj.pos.y - SCORE_IMAGES_SHIFT_BUF;
	enemy.scoreObj.scale = multiEnemy[arrayNum].obj.scale;
	enemy.scoreObj.angle = multiEnemy[arrayNum].obj.angle;
}





//////////////////////////////////////////////////////////////////////
// STAGE１
//////////////////////////////////////////////////////////////////////

// ステージ１初期化
void InitMultiEnemySTAGE1(Enemy& enemy, Enemy multiEnemy[], int size, Game& game)
{
	// エントリー情報を本体に書き込む
	// 初期位置の設定
	for (int i = 0; i < size; i++)
	{
		//multiEnemy[i].obj.pos.x = enemyEntryDataBese[i].x + (i * ENEMY_MOVE_MARGIN);
		multiEnemy[i].obj.pos.x = enemyEntryDataBeseSTAGE1[i].x;
		multiEnemy[i].obj.pos.y = enemyEntryDataBeseSTAGE1[i].y + 10;
		multiEnemy[i].obj.speed = enemyEntryDataBeseSTAGE1[i].speed;
		multiEnemy[i].obj.angle = GetRadian(180.0f);
		multiEnemy[i].life = ENEMY_LIFE;
		multiEnemy[i].alive = false;			// エントリーフレーム時間になるまでは生きていない
		multiEnemy[i].enemyEntry.routine = enemyEntryDataBeseSTAGE1[i].routine;
	}

	// エネミーのグラフィックをメモリにロード＆表示座標を初期化
	char* enemyGlaphStr = "data/texture/SubBossDamege.png";

	// 空中
	char* enemyVerticalGraph		= "data/texture/enemyVertical.png";			// 垂直敵
	char* enemyHorizonGraph			= "data/texture/enemyHorizon.png";			// 平行
	char* enemyHorizonReverseGraph	= "data/texture/enemyHorizonReverse.png";	// 逆平行
	char* enemyRightAngleGraph		= "data/texture/enemyRightAngle.png";		// 
	
	// 地上
	char* enemyVerticalGroundGraph	= "data/texture/VERTICAL_GROUND_WEAPON.png";		// 垂直敵
	char* enemyHorizonGroundGraph	= "data/texture/HORIZON_GROUND_WEAPON.png";			// 平行
	char* enemyRightDiagonalGraph	= "data/texture/RIGHT_DIAGONAL_GRAOUND_WEAPON.png";	// 逆平行
	char* enemyZigzagGroundGraph	= "data/texture/STAGE1BossGraph.png";			// 直下移動

	// 中ボス
	char* subBossDualUse			= "data/texture/SubBoss.png";	// 中ボス水陸両用戦闘機

	for (int i = 0; i < size; i++)
	{
		// 地上
		// 垂直移動エネミー画像ロード
		if (multiEnemy[i].enemyEntry.routine == VERTICAL_GROUND_WEAPON)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyVerticalGroundGraph);
		}
		if (multiEnemy[i].enemyEntry.routine == HORIZON_GROUND_WEAPON)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyHorizonGroundGraph);
		}
		if (multiEnemy[i].enemyEntry.routine == HORIZON_REVERSE_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyRightDiagonalGraph);
		}
		if (multiEnemy[i].enemyEntry.routine == ZIGZAG_GROUND_WEAPON)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyZigzagGroundGraph);
		}
		/*if (multiEnemy[i].damageGraph < 0)
		{
			multiEnemy[i].damageGraph = LoadGraph(enemyGlaphStr);
		}*/

		// 空中
		// 垂直移動エネミー画像ロード
		if (multiEnemy[i].enemyEntry.routine == VERTICAL_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyVerticalGraph);
		}
		if (multiEnemy[i].enemyEntry.routine == HORIZON_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyHorizonGraph);
		}
		if (multiEnemy[i].enemyEntry.routine == HORIZON_REVERSE_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyHorizonReverseGraph);
		}
		if (multiEnemy[i].enemyEntry.routine == RIGHT_ANGLE_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyRightAngleGraph);
		}
		multiEnemy[i].damageGraph = LoadGraph(enemyGlaphStr);

			// 中ボス
		if (multiEnemy[i].enemyEntry.routine == SUB_BOSS_DUAL_USE)
		{
			multiEnemy[i].obj.graph = LoadGraph(subBossDualUse);
			multiEnemy[i].life = SUB_BOSS_LIFE;
			multiEnemy[i].shotIntervalCount = SUB_BOSS_SHOT_INTERVAL;
		}
		

	}

	// エネミーの撃破時の分割画像メモリにロード (一旦game.enemyから入って1つ分作ってから、マルチエネミーにコピーする)
	LoadDivGraph("data/texture/ExplosionGraph.png", ENEMY_DESTROY_GRAPH_TOTAL,ENEMY_DESTROY_GRAPH_X_NUM, ENEMY_DESTROY_GRAPH_Y_NUM, 64, 64, game.enemy.destroyGraph);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < ENEMY_DESTROY_GRAPH_TOTAL; j++)
		{
			// エネミー撃破時の画像表示のためのフレーム保持関数の初期化
			multiEnemy[i].destroyFlameCount = 0;
		}
	}


	// 『ダメージをうけていない』を表すFALSEを代入
	for (int i = 0; i < size; i++)
	{
		multiEnemy[i].damageFlag = false;
	}

	// エネミーの登場テーブルの設定
	for (int i = 0; i < size; i++)
	{
		multiEnemy[i].enemyEntry.frame = enemyEntryDataBeseSTAGE1[i].frame;
	}

	//// エネミーのグラフィックのサイズを得る
	//GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);

	// マルチエネミー用のグラフィックサイズを得る
	int multiEnemyGraphSize;
	//multiEnemyGraphSize = GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);
	for (int i = 0; i < size; i++)
	{
		GetGraphSize(multiEnemy[i].obj.graph, &multiEnemy[i].obj.w, &multiEnemy[i].obj.h);
	}


	// ショットを初期化
	int shotGraph = enemy.shot[0].obj.graph;
	int shotW = enemy.shot[0].obj.w;
	int shotH = enemy.shot[0].obj.h;
	if (shotGraph < 0)
	{
		shotGraph = LoadGraph("data/texture/SuperEnemyShot.png");
		GetGraphSize(shotGraph, &enemy.obj.w, &enemy.obj.h);
	}
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		InitShot(enemy.shot[i], shotGraph, shotW, shotH, GetRadian(180.0f), ENEMY_SHOT_SPEED, ENEMY_SHOT_POWER);
	}
	// マルチエネミーのショットの初期化
	for (int i = 0; i < size; i++)
	{
		shotGraph = LoadGraph("data/texture/enemyShotGraph.png");
		GetGraphSize(shotGraph, &multiEnemy[i].obj.w, &multiEnemy[i].obj.h);
	}
	// ショットのパワーの設定
	for (int i = 0; i < size; i++)
	{
		InitShot(multiEnemy[i].shot[i], shotGraph, shotW, shotH, GetRadian(180.0f), ENEMY_SHOT_SPEED, ENEMY_SHOT_POWER);
	}
}






//////////////////////////////////////////////////////////////////////
// STAGE2
//////////////////////////////////////////////////////////////////////

// ステージ2初期化
void InitMultiEnemySTAGE2(Enemy& enemy, Enemy multiEnemy[], int size, Game& game)
{
	// エントリー情報を本体に書き込む
	// 初期位置の設定
	for (int i = 0; i < size; i++)
	{
		//multiEnemy[i].obj.pos.x = enemyEntryDataBese[i].x + (i * ENEMY_MOVE_MARGIN);
		multiEnemy[i].obj.pos.x = enemyEntryDataBeseSTAGE2[i].x;
		multiEnemy[i].obj.pos.y = enemyEntryDataBeseSTAGE2[i].y + 10;
		multiEnemy[i].obj.speed = enemyEntryDataBeseSTAGE2[i].speed;
		multiEnemy[i].obj.angle = GetRadian(180.0f);
		multiEnemy[i].life = ENEMY_LIFE;
		multiEnemy[i].alive = false;			// エントリーフレーム時間になるまでは生きていない
		multiEnemy[i].enemyEntry.routine = enemyEntryDataBeseSTAGE2[i].routine;
	}

	// エネミーのグラフィックをメモリにロード＆表示座標を初期化
	char* enemyGlaphStr = "data/texture/enemyBug20.png";

	// 空中
	char* enemyVerticalGraph		= "data/texture/enemyVertical.png";					// 垂直敵
	char* enemyHorizonGraph			= "data/texture/enemyHorizon.png";					// 平行
	char* enemyHorizonReverseGraph	= "data/texture/enemyHorizonReverse.png";			// 逆平行
	char* enemyRightAngleGraph		= "data/texture/enemyRightAngle.png";				// 

	// 地上
	char* enemyVerticalGroundGraph	= "data/texture/VERTICAL_GROUND_WEAPON.png";		// 垂直敵
	char* enemyHorizonGroundGraph	= "data/texture/HORIZON_GROUND_WEAPON.png";			// 平行
	char* enemyRightDiagonalGraph	= "data/texture/RIGHT_DIAGONAL_GRAOUND_WEAPON.png";	// 逆平行
	char* enemyZigzagGroundGraph	= "data/texture/enemyVertical.png";				// 直下移動

	// 中ボス
	char* subBossDualUse			= "data/texture/SubBoss.png";			// 中ボス水陸両用戦闘機

	// 海上
	char* enemySubBossCruisers		= "data/texture/CEUISERS.png";			// 巡洋艦
	char* enemyBattleShips			= "data/texture/STAGE2BattleShip.png";	// 戦艦


	// 被弾時の画像
	char* enemySubBossCruisersHit	= "data/texture/HitCruiser.png";			// 巡洋艦（被弾）


	for (int i = 0; i < size; i++)
	{
		// 地上
		// 垂直移動エネミー画像ロード
		if (multiEnemy[i].enemyEntry.routine == VERTICAL_GROUND_WEAPON)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyVerticalGroundGraph);
		}
		if (multiEnemy[i].enemyEntry.routine == HORIZON_GROUND_WEAPON)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyHorizonGroundGraph);
		}
		if (multiEnemy[i].enemyEntry.routine == HORIZON_REVERSE_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyRightDiagonalGraph);
		}
		if (multiEnemy[i].enemyEntry.routine == ZIGZAG_GROUND_WEAPON)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyZigzagGroundGraph);
		}
		if (multiEnemy[i].damageGraph < 0)
		{
			multiEnemy[i].damageGraph = LoadGraph(enemyGlaphStr);
		}

		// 空中
		// 垂直移動エネミー画像ロード
		if (multiEnemy[i].enemyEntry.routine == VERTICAL_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyVerticalGraph);
		}
		if (multiEnemy[i].enemyEntry.routine == HORIZON_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyHorizonGraph);
		}
		if (multiEnemy[i].enemyEntry.routine == HORIZON_REVERSE_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyHorizonReverseGraph);
		}
		if (multiEnemy[i].enemyEntry.routine == RIGHT_ANGLE_FIGHTER)
		{
			multiEnemy[i].obj.graph = LoadGraph(enemyRightAngleGraph);
		}
		if (multiEnemy[i].damageGraph < 0)
		{
			multiEnemy[i].damageGraph = LoadGraph(enemyGlaphStr);
		}

		// 中ボス
		if (multiEnemy[i].enemyEntry.routine == SUB_BOSS_DUAL_USE)
		{
			multiEnemy[i].obj.graph = LoadGraph(subBossDualUse);
			multiEnemy[i].life = SUB_BOSS_LIFE;
			multiEnemy[i].shotIntervalCount = SUB_BOSS_SHOT_INTERVAL;
		}

		// 海上
		if (multiEnemy[i].enemyEntry.routine == SUB_BOSS_CRUISERS)
		{
			// 巡洋艦
			multiEnemy[i].obj.graph = LoadGraph(enemySubBossCruisers);
			multiEnemy[i].life = SUB_BOSS_CRUISERS_LIFE;
			multiEnemy[i].damageGraph = LoadGraph(enemySubBossCruisersHit);
			multiEnemy[i].shotIntervalCount = 5;
		}

	}

	// エネミーの撃破時の分割画像メモリにロード (一旦game.enemyから入って1つ分作ってから、マルチエネミーにコピーする)
	LoadDivGraph("data/texture/ExplosionGraph.png", ENEMY_DESTROY_GRAPH_TOTAL, ENEMY_DESTROY_GRAPH_X_NUM, ENEMY_DESTROY_GRAPH_Y_NUM, 64, 64, game.enemy.destroyGraph);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < ENEMY_DESTROY_GRAPH_TOTAL; j++)
		{
			// エネミー撃破時の画像表示のためのフレーム保持関数の初期化
			multiEnemy[i].destroyFlameCount = 0;
		}
	}

	// 『ダメージをうけていない』を表すFALSEを代入
	for (int i = 0; i < size; i++)
	{
		multiEnemy[i].damageFlag = false;
	}

	// エネミーの登場テーブルの設定
	for (int i = 0; i < size; i++)
	{
		multiEnemy[i].enemyEntry.frame = enemyEntryDataBeseSTAGE1[i].frame;
	}

	//// エネミーのグラフィックのサイズを得る
	//GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);

	// マルチエネミー用のグラフィックサイズを得る
	int multiEnemyGraphSize;
	//multiEnemyGraphSize = GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);
	for (int i = 0; i < size; i++)
	{
		GetGraphSize(multiEnemy[i].obj.graph, &multiEnemy[i].obj.w, &multiEnemy[i].obj.h);
	}


	// ショットを初期化
	int shotGraph = enemy.shot[0].obj.graph;
	int shotW = enemy.shot[0].obj.w;
	int shotH = enemy.shot[0].obj.h;
	if (shotGraph < 0)
	{
		shotGraph = LoadGraph("data/texture/SuperEnemyShot.png");
		GetGraphSize(shotGraph, &enemy.obj.w, &enemy.obj.h);
	}
	for (int i = 0; i < ENEMY_SHOT; i++)
	{
		InitShot(enemy.shot[i], shotGraph, shotW, shotH, GetRadian(180.0f), ENEMY_SHOT_SPEED, ENEMY_SHOT_POWER);
	}
	// マルチエネミーのショットの初期化
	for (int i = 0; i < size; i++)
	{
		shotGraph = LoadGraph("data/texture/enemyShotGraph.png");
		GetGraphSize(shotGraph, &multiEnemy[i].obj.w, &multiEnemy[i].obj.h);
	}
	// ショットのパワーの設定
	for (int i = 0; i < size; i++)
	{
		InitShot(multiEnemy[i].shot[i], shotGraph, shotW, shotH, GetRadian(180.0f), ENEMY_SHOT_SPEED, ENEMY_SHOT_POWER);
	}
}





















