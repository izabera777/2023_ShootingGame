// �G�l�~�[
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

// �G�l�~�[�o���e�[�u��
EnemyEntry enemyEntryDataBese[ENEMY_NUM_STAGE1] =
{
	// �P�O��؂�

	// �t���[�����@ x���W�@  y���W  x�X�s�[�h  ���[�`���^�C�v
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




// �X�e�[�W�P�̃}���`�G�l�~�[�̃G���g���[���i�X�e�[�W�P�͒n��j
EnemyEntry enemyEntryDataBeseSTAGE1[ENEMY_NUM_STAGE2] =
{
	// �P�O��؂�

	// �t���[�����@ x���W�@  y���W   �X�s�[�h  ���[�`���^�C�v
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



// �X�e�[�W�Q�̃G�l�~�[�o��e�[�u��
EnemyEntry enemyEntryDataBeseSTAGE2[ENEMY_NUM_STAGE3] =
{
	// �P�O��؂�

	// �t���[�����@ x���W�@  y���W  x�X�s�[�h  ���[�`���^�C�v
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
// �G�l�~�[�֐��Q.
//----------------------------//


// ������.
void InitMultiEnemy(Enemy& enemy,Enemy multiEnemy[], int size,Game& game)
{
	//�����ʒu�̐ݒ�
	for (int i = 0; i < size; i++)
	{
		//multiEnemy[i].obj.pos.x = enemyEntryDataBese[i].x + (i * ENEMY_MOVE_MARGIN);
		multiEnemy[i].obj.pos.x = enemyEntryDataBese[i].x;
		multiEnemy[i].obj.pos.y = enemyEntryDataBese[i].y + 10;
		multiEnemy[i].obj.speed = enemyEntryDataBese[i].speed;
		multiEnemy[i].obj.angle = GetRadian(180.0f);
		multiEnemy[i].life		= ENEMY_LIFE;
		multiEnemy[i].alive		= false;			// �G���g���[�t���[�����ԂɂȂ�܂ł͐����Ă��Ȃ�
		multiEnemy[i].enemyEntry.routine = enemyEntryDataBese[i].routine;
	}

	// �G�l�~�[�̃O���t�B�b�N���������Ƀ��[�h���\�����W��������
	char* enemyGlaphStr				= "data/texture/SubBossDamege.png";


	char* enemyVerticalGraph		= "data/texture/enemyVertical.png";			// �����G
	char* enemyHorizonGraph			= "data/texture/enemyHorizon.png";			// ���s
	char* enemyHorizonReverseGraph	= "data/texture/enemyHorizonReverse.png";	// �t���s
	char* enemyRightAngleGraph		= "data/texture/enemyRightAngle.png";		// 


	for (int i = 0; i < size; i++)
	{
		// �����ړ��G�l�~�[�摜���[�h
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

	// �G�l�~�[�̌��j���̕����摜�������Ƀ��[�h (��Ugame.enemy���������1������Ă���A�}���`�G�l�~�[�ɃR�s�[����)
	LoadDivGraph("data/texture/ExplosionGraph.png", ENEMY_DESTROY_GRAPH_TOTAL, ENEMY_DESTROY_GRAPH_X_NUM, ENEMY_DESTROY_GRAPH_Y_NUM, 64, 64, game.enemy.destroyGraph);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < ENEMY_DESTROY_GRAPH_TOTAL; j++)
		{
			// �G�l�~�[���j���̉摜�\���̂��߂̃t���[���ێ��֐��̏�����
			multiEnemy[i].destroyFlameCount = 0;
		}
	}
	
	// �G�l�~�[���j���Ɋl�����X�R�A�̕����摜���������Ƀ��[�h
	LoadDivGraph("data/texture/pointGraph.png", SCORE_IMAGES_TOTAL, SCORE_IMAGES_X_NUM, SCORE_IMAGES_Y_NUM, SCORE_IMAGES_SIZE_X, SCORE_IMAGES_SIZE_Y, enemy.scoreDestroyGraph);

	// �w�_���[�W�������Ă��Ȃ��x��\��FALSE����
	for (int i = 0; i < size; i++)
	{
		multiEnemy[i].damageFlag = false;
	}
	
	// �G�l�~�[�̓o��e�[�u���̐ݒ�
	for (int i = 0; i < size; i++)
	{
		multiEnemy[i].enemyEntry.frame = enemyEntryDataBese[i].frame;
	}
	
	//// �G�l�~�[�̃O���t�B�b�N�̃T�C�Y�𓾂�
	//GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);

	// �}���`�G�l�~�[�p�̃O���t�B�b�N�T�C�Y�𓾂�
	int multiEnemyGraphSize;
	//multiEnemyGraphSize = GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);
	for (int i = 0; i < size; i++)
	{
		GetGraphSize(multiEnemy[i].obj.graph, &multiEnemy[i].obj.w, &multiEnemy[i].obj.h);
	}


	// �V���b�g��������
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

	// �}���`�G�l�~�[�̃V���b�g�̏�����
	for (int i = 0; i < size; i++)
	{
		shotGraph = LoadGraph("data/texture/enemyShotGraph.png");
		GetGraphSize(shotGraph, &multiEnemy[i].obj.w, &multiEnemy[i].obj.h);
	}

	// �V���b�g�̃p���[�̐ݒ�
	for (int i = 0; i < size; i++)
	{
		InitShot(multiEnemy[i].shot[i], shotGraph, shotW, shotH, GetRadian(180.0f), ENEMY_SHOT_SPEED, ENEMY_SHOT_POWER);
	}
}


// �}���`�G�l�~�[�̈ړ����[�`���ɉ������x�N�g���̒���
// �����ł͕����̂ݐݒ�
void MoveRoutinesMultiEnemy(Enemy multiEnemy[], int size)
{
	// �ړ����[�`���̎Q��
	// �`���[�g���A��
	for (int i = 0; i < size; i++)
	{
		// �����ړ��i�と���j
		if (VERTICAL_FIGHTER == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(0, 1, 0);
		}
		// ���s�ړ��i�����E�j
		if (HORIZON_FIGHTER == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(1, 0, 0);
		}
		// ���s�ړ��i�E�����j
		if (HORIZON_REVERSE_FIGHTER == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(-1, 0, 0);
		}
		// ���p�ړ��i�E�����j
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

		// �n�㕺��iSTAGE1�j
		// �����ړ��i�と���j
		if (VERTICAL_GROUND_WEAPON == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(0, 1, 0);
		}
		// ���s�ړ��i�����E�j
		if (HORIZON_GROUND_WEAPON == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(1, 0, 0);
		}
		// ���s�ړ��i�E�����j
		if (RIGHT_DIAGONAL_GRAOUND_WEAPON == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(-1, 0, 0);
		}
		// ���p�ړ��i�E�����j
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

		// U���ړ�
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

		// ���{�X
		if (SUB_BOSS_DUAL_USE == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet( 1, 0, 0);
		}

		// ���m��	������E�ړ�
		if (SUB_BOSS_CRUISERS == multiEnemy[i].enemyEntry.routine)
		{
			multiEnemy[i].obj.dir = VGet(1, 0, 0);
			multiEnemy[i].obj.w = 400;
			multiEnemy[i].obj.h = 50;
		}


		// �ړ��X�s�[�h�̓G���g���[�����Q��

	}
}



// �A�b�v�f�[�g.
void UpdateMultiEnemy(Enemy& enemy,Enemy multiEnemy[], Player& player,int size,Game& game)
{
	// �}���`�G�l�~�[�̈ړ����[�`���ɉ������x�N�g���̒���(����)
	MoveRoutinesMultiEnemy(multiEnemy, size);

	//�G�l�~�[�ړ�
	for (int i = 0; i < size; i++)
	{
		if (multiEnemy[i].alive == true)
		{
			MoveGameObject(multiEnemy[i].obj);
		}
	}

	// �G�l�~�[��ʊO�ɏo�Ă���AHP���O�̎� alive = false
	for (int i = 0; i < size; i++)
	{
		// HP���Ȃ��ꍇ
		if (multiEnemy[i].life <= 0)
		{
			multiEnemy[i].alive = false;
		}
		//�E�[�ɏo���ꍇ
		if (multiEnemy[i].obj.pos.x > SCREEN_W - multiEnemy[i].obj.w)
		{
			multiEnemy[i].alive = false;
		}
		else if (multiEnemy[i].obj.pos.x < 0)
		{
			multiEnemy[i].alive = false;
		}

	}

	// �G�e�����@�̕�����_���t���[����
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
	// �G�̒e�̔��ˏ���
	for (int i = 0; i < size; i++)
	{
		// �V���b�g�̔��˃C���^�[�o�����Ȃ��Ȃ��Ă����猂��
		if (multiEnemy[i].shotIntervalCount == 0 && multiEnemy[i].life > 0)
		{
			// ��ʏ�ɂłĂ��Ȃ��e�����邩�A�e�̐������J��Ԃ��Ē��ׂ�
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < ENEMY_SHOT; j++)
				{
					// �ei����ʏ�ɂłĂ��Ȃ��ꍇ�͂��̒e����ʂɏo��
					if (multiEnemy[i].shot[j].visibleFlag == false)
					{
						if (multiEnemy[i].life != 0 && multiEnemy[i].alive == true)
						{
							// �ei�̈ʒu���Z�b�g�A�ʒu�͓G�̒��S�ɂ���
							multiEnemy[i].shot[j].obj.pos.x = multiEnemy[i].obj.pos.x;
							multiEnemy[i].shot[j].obj.pos.y = multiEnemy[i].obj.pos.y;

							// �ei�͌����_�������đ��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ���true��������
							multiEnemy[i].shot[j].visibleFlag = true;

							// �ł����̐ݒ�
							// �ł���Ă���15�t���[���̊Ԃ͓G�e�̕������v���C���[�Ɍ�����
							if (multiEnemy[i].shot[j].canTrunFrameTime <= 15)
							{
								//	�v���C���[�@- �V���b�g   �x�N�g��AB = B - A
								multiEnemy[i].shot[j].obj.dir = VSub(player.obj.pos, multiEnemy[i].shot[j].obj.pos);
							}
							if (VSize(multiEnemy[i].obj.dir) > 0)
							{
								multiEnemy[i].shot[j].obj.dir = VNorm(multiEnemy[i].shot[j].obj.dir);
							}
							VECTOR shotVelocity = VScale(multiEnemy[i].obj.dir, ENEMY_SHOT_SPEED);
							multiEnemy[i].shot[j].obj.pos = VAdd(multiEnemy[i].obj.pos, shotVelocity);

							// ��e���o�����̂Œe���o�����[�v���甲���܂�
							break;
						}
					}
				}
			}

			// �C���^�[�o���p�̃J�E���^�[��ݒ�.
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
	// �G�l�~�[�̃V���b�g�̘A�˗͂��Ǘ�
	for (int i = 0; i < size; i++)
	{
		if (multiEnemy[i].shotIntervalCount != 0)
		{
			--multiEnemy[i].shotIntervalCount;
		}
	}

	// �����蔻��
	// �V���b�g����
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < ENEMY_SHOT; j++)
		{
			// �V���b�g�ړ�
			MoveShot(multiEnemy[i].shot[j]);
			
			// �G�l�~�[�̃V���b�g�ƃv���C���[�̓����蔻��
			if (IsHitShot(multiEnemy[i].shot[j], player.obj))
			{
				// �������Ă���V���b�g�p���[���_���[�W��^����
				if (player.life > 0)
				{
					// �v���C���[��e���̃T�E���h
					PlaySoundMem(game.sound.playerShotSE, DX_PLAYTYPE_BACK, true);

					player.life -= multiEnemy[i].shot[j].power;
					player.damageCounter	= 0;
					player.damageFlag		= true;
					// �A���œ�����Ȃ��悤�ɔ�����
					break;
				}

				

			}
		}
	}

	// �_���[�W���󂯂Ă��邩�ǂ����ŏ����𕪊�
	for (int i = 0; i < size; i++)
	{
		if (multiEnemy[i].damageFlag == true)
		{
			multiEnemy[i].damageCounter++;

			if (multiEnemy[i].damageCounter == 5)
			{
				// �w�_���[�W�������Ă��Ȃ��x��\��FALSE����
				multiEnemy[i].damageFlag = false;
			}
		}
	}
}


// �`��.
void DrawMultiEnemy(Game& game,Enemy multiEnemy[], int size)
{
	
	int _destroyIndex = 0;	// �G�l�~�[���j���̉摜�̓Y����

	for (int i = 0; i < size; i++)
	{
		// �����̃t���[�����Ԃ��AHP�����鎞�A��ʏ�ɑ��݂��Ă��鎞����
		if (game.gameFrameCount >= multiEnemy[i].enemyEntry.frame && 0 < multiEnemy[i].life)
		{
			// �G���g���[�t���[�����ԂɂȂ����琶���Ă���
			multiEnemy[i].alive = true;
			// �_���[�W���󂯂Ă���ꍇ�̓_���[�W���̃O���t�B�b�N��`�悷��
			if (multiEnemy[i].damageFlag == true)
			{
				// ���ʂ̉摜���`��
				DrawGameObject(multiEnemy[i].obj, multiEnemy[i].obj.graph);
				
				// �T�u�{�X�������ꍇ�Y�����𒊏o
				if (multiEnemy[i].enemyEntry.routine == SUB_BOSS_CRUISERS || multiEnemy[i].enemyEntry.routine == SUB_BOSS_DUAL_USE)
				{
					game.subBossIndex = i;
				}

				// ���j���̉摜�\��
				if (multiEnemy[i].destroyFlameCount <= 65)
				{
					// ���j����Ă���̃t���[���J�E���g���P�O�Ŋ���Y�������o��
					DrawGameObject(multiEnemy[i].obj, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT]);
					DrawGraph(multiEnemy[i].obj.pos.x - 100, multiEnemy[i].obj.pos.y -  20, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT], true);
					DrawGraph(multiEnemy[i].obj.pos.x - 250, multiEnemy[i].obj.pos.y + 100, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT], true);
					DrawGraph(multiEnemy[i].obj.pos.x + 230, multiEnemy[i].obj.pos.y +  20, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT], true);
					DrawGraph(multiEnemy[i].obj.pos.x +  10, multiEnemy[i].obj.pos.y +   50, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT], true);
					DrawGraph(multiEnemy[i].obj.pos.x +  10, multiEnemy[i].obj.pos.y -   50, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT], true);

					// �G�l�~�[�����j����Ă���̃t���[���J�E���g
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


		// ���j���̉摜�\��
		if (multiEnemy[i].life <= 0 && multiEnemy[i].destroyFlameCount <= 65)	
		{
			// ���j����Ă���̃t���[���J�E���g��5�Ŋ���Y�������o��
			DrawGameObject(multiEnemy[i].obj, game.enemy.destroyGraph[multiEnemy[i].destroyFlameCount / ENEMY_BLAST_GRAPH_DRAW_COUNT]);
			
			if (multiEnemy[i].life <= 0 && multiEnemy[i].destroyFlameCount < 50)
			{
				// �`��ʒu�����j�ʒu�̏�����Ɉړ�
				CopySocreObject(game.enemy, multiEnemy, i);

				// ���j���̃X�R�A���o�i�摜�`��j
				DrawGameObject(game.enemy.scoreObj, game.enemy.scoreDestroyGraph[multiEnemy[i].destroyFlameCount / SCORE_IMAGES_DRAW_COUNT]);
			}

			// �G�l�~�[�����j����Ă���̃t���[���J�E���g
			multiEnemy[i].destroyFlameCount++;
		}
	}

	// �V���b�g�̕\��
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < ENEMY_SHOT; j++)
		{
			// �V���b�g���\��
			DrawShot(multiEnemy[i].shot[j]);
		}
	}
}


// �X�R�A�`��ʒu�𒲐����邽�߁AscoreObj�Ɏ��ۂ̏����R�s�[
void CopySocreObject(Enemy& enemy,Enemy multiEnemy[],int arrayNum)
{
	// ������ɂ��炷
	enemy.scoreObj.pos.x = multiEnemy[arrayNum].obj.pos.x;
	enemy.scoreObj.pos.y = multiEnemy[arrayNum].obj.pos.y - SCORE_IMAGES_SHIFT_BUF;
	enemy.scoreObj.scale = multiEnemy[arrayNum].obj.scale;
	enemy.scoreObj.angle = multiEnemy[arrayNum].obj.angle;
}





//////////////////////////////////////////////////////////////////////
// STAGE�P
//////////////////////////////////////////////////////////////////////

// �X�e�[�W�P������
void InitMultiEnemySTAGE1(Enemy& enemy, Enemy multiEnemy[], int size, Game& game)
{
	// �G���g���[����{�̂ɏ�������
	// �����ʒu�̐ݒ�
	for (int i = 0; i < size; i++)
	{
		//multiEnemy[i].obj.pos.x = enemyEntryDataBese[i].x + (i * ENEMY_MOVE_MARGIN);
		multiEnemy[i].obj.pos.x = enemyEntryDataBeseSTAGE1[i].x;
		multiEnemy[i].obj.pos.y = enemyEntryDataBeseSTAGE1[i].y + 10;
		multiEnemy[i].obj.speed = enemyEntryDataBeseSTAGE1[i].speed;
		multiEnemy[i].obj.angle = GetRadian(180.0f);
		multiEnemy[i].life = ENEMY_LIFE;
		multiEnemy[i].alive = false;			// �G���g���[�t���[�����ԂɂȂ�܂ł͐����Ă��Ȃ�
		multiEnemy[i].enemyEntry.routine = enemyEntryDataBeseSTAGE1[i].routine;
	}

	// �G�l�~�[�̃O���t�B�b�N���������Ƀ��[�h���\�����W��������
	char* enemyGlaphStr = "data/texture/SubBossDamege.png";

	// ��
	char* enemyVerticalGraph		= "data/texture/enemyVertical.png";			// �����G
	char* enemyHorizonGraph			= "data/texture/enemyHorizon.png";			// ���s
	char* enemyHorizonReverseGraph	= "data/texture/enemyHorizonReverse.png";	// �t���s
	char* enemyRightAngleGraph		= "data/texture/enemyRightAngle.png";		// 
	
	// �n��
	char* enemyVerticalGroundGraph	= "data/texture/VERTICAL_GROUND_WEAPON.png";		// �����G
	char* enemyHorizonGroundGraph	= "data/texture/HORIZON_GROUND_WEAPON.png";			// ���s
	char* enemyRightDiagonalGraph	= "data/texture/RIGHT_DIAGONAL_GRAOUND_WEAPON.png";	// �t���s
	char* enemyZigzagGroundGraph	= "data/texture/STAGE1BossGraph.png";			// �����ړ�

	// ���{�X
	char* subBossDualUse			= "data/texture/SubBoss.png";	// ���{�X�������p�퓬�@

	for (int i = 0; i < size; i++)
	{
		// �n��
		// �����ړ��G�l�~�[�摜���[�h
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

		// ��
		// �����ړ��G�l�~�[�摜���[�h
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

			// ���{�X
		if (multiEnemy[i].enemyEntry.routine == SUB_BOSS_DUAL_USE)
		{
			multiEnemy[i].obj.graph = LoadGraph(subBossDualUse);
			multiEnemy[i].life = SUB_BOSS_LIFE;
			multiEnemy[i].shotIntervalCount = SUB_BOSS_SHOT_INTERVAL;
		}
		

	}

	// �G�l�~�[�̌��j���̕����摜�������Ƀ��[�h (��Ugame.enemy���������1������Ă���A�}���`�G�l�~�[�ɃR�s�[����)
	LoadDivGraph("data/texture/ExplosionGraph.png", ENEMY_DESTROY_GRAPH_TOTAL,ENEMY_DESTROY_GRAPH_X_NUM, ENEMY_DESTROY_GRAPH_Y_NUM, 64, 64, game.enemy.destroyGraph);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < ENEMY_DESTROY_GRAPH_TOTAL; j++)
		{
			// �G�l�~�[���j���̉摜�\���̂��߂̃t���[���ێ��֐��̏�����
			multiEnemy[i].destroyFlameCount = 0;
		}
	}


	// �w�_���[�W�������Ă��Ȃ��x��\��FALSE����
	for (int i = 0; i < size; i++)
	{
		multiEnemy[i].damageFlag = false;
	}

	// �G�l�~�[�̓o��e�[�u���̐ݒ�
	for (int i = 0; i < size; i++)
	{
		multiEnemy[i].enemyEntry.frame = enemyEntryDataBeseSTAGE1[i].frame;
	}

	//// �G�l�~�[�̃O���t�B�b�N�̃T�C�Y�𓾂�
	//GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);

	// �}���`�G�l�~�[�p�̃O���t�B�b�N�T�C�Y�𓾂�
	int multiEnemyGraphSize;
	//multiEnemyGraphSize = GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);
	for (int i = 0; i < size; i++)
	{
		GetGraphSize(multiEnemy[i].obj.graph, &multiEnemy[i].obj.w, &multiEnemy[i].obj.h);
	}


	// �V���b�g��������
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
	// �}���`�G�l�~�[�̃V���b�g�̏�����
	for (int i = 0; i < size; i++)
	{
		shotGraph = LoadGraph("data/texture/enemyShotGraph.png");
		GetGraphSize(shotGraph, &multiEnemy[i].obj.w, &multiEnemy[i].obj.h);
	}
	// �V���b�g�̃p���[�̐ݒ�
	for (int i = 0; i < size; i++)
	{
		InitShot(multiEnemy[i].shot[i], shotGraph, shotW, shotH, GetRadian(180.0f), ENEMY_SHOT_SPEED, ENEMY_SHOT_POWER);
	}
}






//////////////////////////////////////////////////////////////////////
// STAGE2
//////////////////////////////////////////////////////////////////////

// �X�e�[�W2������
void InitMultiEnemySTAGE2(Enemy& enemy, Enemy multiEnemy[], int size, Game& game)
{
	// �G���g���[����{�̂ɏ�������
	// �����ʒu�̐ݒ�
	for (int i = 0; i < size; i++)
	{
		//multiEnemy[i].obj.pos.x = enemyEntryDataBese[i].x + (i * ENEMY_MOVE_MARGIN);
		multiEnemy[i].obj.pos.x = enemyEntryDataBeseSTAGE2[i].x;
		multiEnemy[i].obj.pos.y = enemyEntryDataBeseSTAGE2[i].y + 10;
		multiEnemy[i].obj.speed = enemyEntryDataBeseSTAGE2[i].speed;
		multiEnemy[i].obj.angle = GetRadian(180.0f);
		multiEnemy[i].life = ENEMY_LIFE;
		multiEnemy[i].alive = false;			// �G���g���[�t���[�����ԂɂȂ�܂ł͐����Ă��Ȃ�
		multiEnemy[i].enemyEntry.routine = enemyEntryDataBeseSTAGE2[i].routine;
	}

	// �G�l�~�[�̃O���t�B�b�N���������Ƀ��[�h���\�����W��������
	char* enemyGlaphStr = "data/texture/enemyBug20.png";

	// ��
	char* enemyVerticalGraph		= "data/texture/enemyVertical.png";					// �����G
	char* enemyHorizonGraph			= "data/texture/enemyHorizon.png";					// ���s
	char* enemyHorizonReverseGraph	= "data/texture/enemyHorizonReverse.png";			// �t���s
	char* enemyRightAngleGraph		= "data/texture/enemyRightAngle.png";				// 

	// �n��
	char* enemyVerticalGroundGraph	= "data/texture/VERTICAL_GROUND_WEAPON.png";		// �����G
	char* enemyHorizonGroundGraph	= "data/texture/HORIZON_GROUND_WEAPON.png";			// ���s
	char* enemyRightDiagonalGraph	= "data/texture/RIGHT_DIAGONAL_GRAOUND_WEAPON.png";	// �t���s
	char* enemyZigzagGroundGraph	= "data/texture/enemyVertical.png";				// �����ړ�

	// ���{�X
	char* subBossDualUse			= "data/texture/SubBoss.png";			// ���{�X�������p�퓬�@

	// �C��
	char* enemySubBossCruisers		= "data/texture/CEUISERS.png";			// ���m��
	char* enemyBattleShips			= "data/texture/STAGE2BattleShip.png";	// ���


	// ��e���̉摜
	char* enemySubBossCruisersHit	= "data/texture/HitCruiser.png";			// ���m�́i��e�j


	for (int i = 0; i < size; i++)
	{
		// �n��
		// �����ړ��G�l�~�[�摜���[�h
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

		// ��
		// �����ړ��G�l�~�[�摜���[�h
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

		// ���{�X
		if (multiEnemy[i].enemyEntry.routine == SUB_BOSS_DUAL_USE)
		{
			multiEnemy[i].obj.graph = LoadGraph(subBossDualUse);
			multiEnemy[i].life = SUB_BOSS_LIFE;
			multiEnemy[i].shotIntervalCount = SUB_BOSS_SHOT_INTERVAL;
		}

		// �C��
		if (multiEnemy[i].enemyEntry.routine == SUB_BOSS_CRUISERS)
		{
			// ���m��
			multiEnemy[i].obj.graph = LoadGraph(enemySubBossCruisers);
			multiEnemy[i].life = SUB_BOSS_CRUISERS_LIFE;
			multiEnemy[i].damageGraph = LoadGraph(enemySubBossCruisersHit);
			multiEnemy[i].shotIntervalCount = 5;
		}

	}

	// �G�l�~�[�̌��j���̕����摜�������Ƀ��[�h (��Ugame.enemy���������1������Ă���A�}���`�G�l�~�[�ɃR�s�[����)
	LoadDivGraph("data/texture/ExplosionGraph.png", ENEMY_DESTROY_GRAPH_TOTAL, ENEMY_DESTROY_GRAPH_X_NUM, ENEMY_DESTROY_GRAPH_Y_NUM, 64, 64, game.enemy.destroyGraph);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < ENEMY_DESTROY_GRAPH_TOTAL; j++)
		{
			// �G�l�~�[���j���̉摜�\���̂��߂̃t���[���ێ��֐��̏�����
			multiEnemy[i].destroyFlameCount = 0;
		}
	}

	// �w�_���[�W�������Ă��Ȃ��x��\��FALSE����
	for (int i = 0; i < size; i++)
	{
		multiEnemy[i].damageFlag = false;
	}

	// �G�l�~�[�̓o��e�[�u���̐ݒ�
	for (int i = 0; i < size; i++)
	{
		multiEnemy[i].enemyEntry.frame = enemyEntryDataBeseSTAGE1[i].frame;
	}

	//// �G�l�~�[�̃O���t�B�b�N�̃T�C�Y�𓾂�
	//GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);

	// �}���`�G�l�~�[�p�̃O���t�B�b�N�T�C�Y�𓾂�
	int multiEnemyGraphSize;
	//multiEnemyGraphSize = GetGraphSize(enemy.obj.graph, &enemy.obj.w, &enemy.obj.h);
	for (int i = 0; i < size; i++)
	{
		GetGraphSize(multiEnemy[i].obj.graph, &multiEnemy[i].obj.w, &multiEnemy[i].obj.h);
	}


	// �V���b�g��������
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
	// �}���`�G�l�~�[�̃V���b�g�̏�����
	for (int i = 0; i < size; i++)
	{
		shotGraph = LoadGraph("data/texture/enemyShotGraph.png");
		GetGraphSize(shotGraph, &multiEnemy[i].obj.w, &multiEnemy[i].obj.h);
	}
	// �V���b�g�̃p���[�̐ݒ�
	for (int i = 0; i < size; i++)
	{
		InitShot(multiEnemy[i].shot[i], shotGraph, shotW, shotH, GetRadian(180.0f), ENEMY_SHOT_SPEED, ENEMY_SHOT_POWER);
	}
}





















