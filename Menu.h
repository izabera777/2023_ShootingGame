#pragma once

// �\���̃v���g�^�C�v�錾
struct GameObject;
struct EenmyEntry;
struct Enemy;
struct Sound;
struct Game;

// �萔
#define MENU_STAGE_NUM      3   // ���j���[�ɕ\������X�e�[�W��
#define MENU_FIGHTER_NUM    3   // ���j���[�ɕ\������퓬�@�̐�
#define MENU_CLOUD_NUM      3   // ���j���[�ɕ\������_�̐�
#define MENU_GLASS_NUM      5   // �X�e�[�W������Ă����摜�̑���
#define MENU_LIFE           6   // �X�e�[�W�̗̑�
#define STAGE_NUM           3   // �X�e�[�W�̐�

// �ˌ��L�[
#define SHOT_KEY_X_POS      500 // �ˌ��L�[�̕`��X�ʒu
#define SHOT_KEY_Y_POS      650 // �ˌ��L�[�̕`��Y�ʒu

// �\���L�[
#define CROSSKEY_X_POS      1100// �\���L�[�̕`��X�ʒu
#define CROSSKEY_Y_POS      650 // �\���L�[�̕`��Y�ʒu



// �\���̐錾

struct StageMnue
{
    int     life = MENU_LIFE;
};


// ���j���[���
struct Menu
{
    GameObject  obj;                //�Q�[���I�u�W�F�N�g�\����
    
    // �X�e�[�W
    GameObject  objStageGraph[MENU_STAGE_NUM];          // �X�e�[�W�̉摜

    // MENU��ł̃I�u�W�F�N�g
    GameObject  objStageSelectBot;                      // �X�e�[�W�Z���N�g���Ɏg���@�̂̏��
    GameObject  objCloudGraph[MENU_FIGHTER_NUM];        // ���j���[��̉��o�Ŏg�p����_�摜
    int         titleGraph;         // �^�C�g���摜

    // ���j���[��̉��o�Ŏg�p����G�퓬�@�摜
    GameObject  objFighterNormal;                       // ���j���[��̉��o�Ŏg�p����G�퓬�@�摜
    GameObject  objBossFighterGraph;                    // ���j���[��̉��o�Ŏg�p����{�X�퓬�@�摜
    GameObject  objBossShipGraph;                       // ���j���[��̉��o�Ŏg�p����{�X�^���N�摜
    GameObject  objFighterGraph[MENU_CLOUD_NUM];        // ���j���[��̉��o�Ŏg�p����퓬�@�摜


    // ���A�V���b�g�摜�֌W
    int         playerKeyInputIndex = 0;// ���j���[��łȂ�̃L�[�������ꂽ����ۑ����� 0:���͂Ȃ� 1:�� 2: �� 3:�E 4:���@5:�X�y�[�X
    int         crossKey;           // �\���L�[
    int         rightKeyRedGraph;   // �ԁ�
    int         leftKeyRedGraph;    // �ԁ�
    int         upKeyRedGraph;      // �ԁ�
    int         downKeyRedGraph;    // �ԁ�
    int         spaceKeyGraph;      // �X�y�[�X
    int         spaceKeyRedGraph;   // �ԃX�y�[�X
    int         frameGraph;         // �t���[��
    int         moveStringGraph;    // �u�ړ��L�[�v
    int         shotStringGraph;    // �u�ˌ��L�[�v
    int         glassCrackingGraph[MENU_GLASS_NUM];  // �K���X�������

    // ���C�t
    StageMnue   stageMenu[STAGE_NUM];   // �X�e�[�W�̃��C

    // �I�y���[�^�[
    GameObject	menuTalkGraph;			// ���j���[�ł̃I�y���[�^�[�̉�b

};

// �Q�[���J�E���g
struct FrameCount
{
    int gameFrameCount;
};



//�֐��v���g�^�C�v�錾
//void TestDrawMultiEnemy(Enemy& enemy, EnemyEntry& enemyEntry);
void InitMenu(Menu& menu, int graph);
void DrawMenu(Menu& menu);
void UpdateMenu(Menu& menu, Sound& sound);

void DrawGlassCracking(Menu& menu);






