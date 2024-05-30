//�C���N���[�h
#include "GameObject.h"
#include "Menu.h"
//#include "DxLib.h"
#include "Shot.h"
#include "Enemy.h"
#include "Utility.h"
#include "Player.h"
#include "BG.h"
#include "UI.h"
#include "Sound.h"
#include "Item.h"
#include "Game.h"

//�֐�����

////////////////////////////////////
//���j���[���
////////////////////////////////////

// ���j���[��ʂ�������
void InitMenu(Menu& menu, int graph)
{
    // �w�i�摜�̏�����
    menu.obj.graph = graph;
    GetGraphSize(menu.obj.graph, &menu.obj.w, &menu.obj.h);	//�O���t�B�b�N�̃T�C�Y�𓾂�
    menu.obj.pos.x = menu.obj.w * 0.5f;
    menu.obj.pos.y = (float)(menu.obj.h/2);

    // �X�e�[�W�摜�̃��[�h
    menu.objStageGraph[0].graph = LoadGraph("data/texture/STAGE1Graph.png");
    menu.objStageGraph[1].graph = LoadGraph("data/texture/STAGE2Graph.png");
    menu.objStageGraph[2].graph = LoadGraph("data/texture/STAGE3Graph.png");
    GetGraphSize(menu.objStageGraph[0].graph, &menu.objStageGraph[0].w, &menu.objStageGraph[0].h);
    GetGraphSize(menu.objStageGraph[1].graph, &menu.objStageGraph[1].w, &menu.objStageGraph[1].h);
    GetGraphSize(menu.objStageGraph[2].graph, &menu.objStageGraph[2].w, &menu.objStageGraph[2].h);
    
    // ���̂܂܂̃T�C�Y�ł͑傫������̂Œ���
    // STAGE1
    menu.objStageGraph[0].pos.x = 300;
    menu.objStageGraph[0].pos.y = 300;
    menu.objStageGraph[0].w     = 200;
    menu.objStageGraph[0].h     = 180;
    // STAGE2
    menu.objStageGraph[1].pos.x = 800;
    menu.objStageGraph[1].pos.y = 300;
    menu.objStageGraph[1].w     = 200;
    menu.objStageGraph[1].h     = 180;
    // STAGE3
    menu.objStageGraph[2].pos.x = 1300;
    menu.objStageGraph[2].pos.y = 300;
    menu.objStageGraph[2].w     = 200;
    menu.objStageGraph[2].h     = 180;

    // ���j���[
    menu.objStageSelectBot.graph = LoadGraph("data/texture/myimg.png");

    // ���j���[��œ����������I�u�W�F�N�g�̓ǂݍ���
    // �摜�̓ǂݍ���
    // �_
    menu.objFighterGraph[0].graph   = LoadGraph("data/texture/enemyVerticalMenu.png");  // �퓬�@�P
    menu.objFighterGraph[1].graph   = LoadGraph("data/texture/enemyHorizonMenu.png");   // �퓬�@�Q
    menu.objBossFighterGraph.graph  = LoadGraph("data/texture/BossMenu1.png");          // �{�X�i�����@�j
    menu.objBossShipGraph.graph     = LoadGraph("data/texture/BossShip1.png");          // �{�X�i�C�㔚���@�j
    // ���W�̏�����
    menu.objFighterGraph[0].pos.x   = 0;    // �퓬�@�P
    menu.objFighterGraph[0].pos.y   = 50;
    menu.objFighterGraph[1].pos.x   = -100; // �퓬�@�Q
    menu.objFighterGraph[1].pos.y   = 100;
    menu.objBossFighterGraph.pos.x  = 1700; // �{�X�i�����@�j
    menu.objBossFighterGraph.pos.y  = 600;
    menu.objBossShipGraph.pos.x     = 1700; // �{�X�i�C�㔚���@�j
    menu.objBossShipGraph.pos.y     = 300;

    // �ړ��L�[�A�V���b�g�摜
    menu.crossKey           = LoadGraph("data/texture/crossKey.png");
    menu.rightKeyRedGraph   = LoadGraph("data/texture/crossKeyRight.png");
    menu.leftKeyRedGraph    = LoadGraph("data/texture/crossKeyLeft.png");
    menu.upKeyRedGraph      = LoadGraph("data/texture/crossKeyUp.png");
    menu.downKeyRedGraph    = LoadGraph("data/texture/crossKeyDown.png");
    menu.spaceKeyGraph      = LoadGraph("data/texture/Xoff.png");
    menu.spaceKeyRedGraph   = LoadGraph("data/texture/Xon.png");

    // �^�C�g��
    menu.titleGraph = LoadGraph("data/texture/titleGraph.png");

    // �_�̉摜���[�h
    for (int i = 0; i < 3; i++)
    {
        menu.objCloudGraph[i].graph = LoadGraph("data/texture/�h�b�g�_400.png");
    }
    // �_�̍��W�ݒ�
    for (int i = 0; i < MENU_CLOUD_NUM - 1; i++)
    {
        menu.objCloudGraph[i].pos.x = -100 * i;
    }
    menu.objCloudGraph[2].pos.x = 1700;
    menu.objCloudGraph[0].pos.y = 100;
    menu.objCloudGraph[1].pos.y = 500;
    menu.objCloudGraph[2].pos.y = 800;

    // �t���[��
    menu.frameGraph = LoadGraph("data/texture/frame400.png");

    // �ړ��L�[��������
    menu.moveStringGraph = LoadGraph("data/texture/moveGraph.png");

    // �ˌ��L�[��������
    menu.shotStringGraph = LoadGraph("data/texture/attackGraph.png");

    // ����Ă����摜
    menu.glassCrackingGraph[0] = LoadGraph("data/texture/�Ђъ���P.png");
    menu.glassCrackingGraph[1] = LoadGraph("data/texture/�Ђъ���Q.png");
    menu.glassCrackingGraph[2] = LoadGraph("data/texture/�Ђъ���R.png");
    menu.glassCrackingGraph[3] = LoadGraph("data/texture/�Ђъ���S.png");
    menu.glassCrackingGraph[4] = LoadGraph("data/texture/�Ђъ���T.png");
    
    // �I�y���[�^�[
    menu.menuTalkGraph.graph = LoadGraph("data/texture/X��STAGE�����āI.png");
    menu.menuTalkGraph.pos.x = 800;
    menu.menuTalkGraph.pos.y = 900;
}

// ���j���[�A�b�v�f�[�g
void  UpdateMenu(Menu& menu,Sound& sound)
{
    // �I�u�W�F�N�g�̈ړ�
    // ������E
    if (menu.objFighterGraph[0].pos.x >= 1700)
    {
        menu.objFighterGraph[0].pos.x = -100;
    }
    else
    {
        menu.objFighterGraph[0].pos.x += 3;
    }
    // 
    if (menu.objFighterGraph[1].pos.x >= 1700)
    {
        menu.objFighterGraph[1].pos.x = -100;
    }
    else
    {
        menu.objFighterGraph[1].pos.x += 4;
    }
    // �_�̕`�� �_�@�A�_�A
    if (menu.objCloudGraph[0].pos.x >= 1700)
    {
        menu.objCloudGraph[0].pos.x = -50;
    }
    else
    {
        menu.objCloudGraph[0].pos.x += 1;
    }
    // 
    if (menu.objCloudGraph[1].pos.x >= 1700)
    {
        menu.objCloudGraph[1].pos.x = -100;
    }
    else
    {
        menu.objCloudGraph[1].pos.x += 2;
    }



    // �E���獶
    if (menu.objBossFighterGraph.pos.x <= -100)
    {
        menu.objBossFighterGraph.pos.x = 1700;
    }
    else
    {
        menu.objBossFighterGraph.pos.x -= 3;
    }
    // 
    if (menu.objBossShipGraph.pos.x <= -100)
    {
        menu.objBossShipGraph.pos.x = 1700;
    }
    else
    {
        menu.objBossShipGraph.pos.x -= 4;
    }
    // �_�B
    if (menu.objCloudGraph[2].pos.x <= -100)
    {
        menu.objCloudGraph[2].pos.x = 1700;
    }
    else
    {
        menu.objCloudGraph[2].pos.x -= 1;
    }

    // �I�y���[�^�[�摜�̈ړ�
    /*if (menu.menuTalkGraph.pos.x <= -400)
    {
        menu.menuTalkGraph.pos.x = 2200;
    }
    else
    {
        menu.menuTalkGraph.pos.x -= 2;
    }*/


    // ���j���[�̕`��
    DrawMenu(menu);

}

// �K���X�̊��ꂽ�`��
void DrawGlassCracking(Menu& menu)
{
    for (int i = 0; i < STAGE_NUM; i++)
    {
        if (menu.stageMenu[i].life == 5)
        {
            DrawGraph(100 + (i*500), 200, menu.glassCrackingGraph[0], true);
        }
        if (menu.stageMenu[i].life == 4)
        {
            DrawGraph(100 + (i * 500), 200, menu.glassCrackingGraph[1], true);
        }
        if (menu.stageMenu[i].life == 3)
        {
            DrawGraph(100 + (i * 500), 200, menu.glassCrackingGraph[2],true);
        }
        if (menu.stageMenu[i].life == 2)
        {
            DrawGraph(100 + (i * 500), 200, menu.glassCrackingGraph[3],true);
        }
        if (menu.stageMenu[i].life == 1)
        {
            DrawGraph(100 + (i * 500),200,menu.glassCrackingGraph[4],true);
        }
    }



}


//���j���[��ʕ`��
void DrawMenu(Menu& menu)
{
    // �X�e�[�W�w�i�̕`��
    DrawGameObject(menu.obj,menu.obj.graph);

    // �I�u�W�F�N�g�̕`��
    DrawGameObject(menu.objFighterGraph[0], menu.objFighterGraph[0].graph);
    DrawGameObject(menu.objFighterGraph[1], menu.objFighterGraph[1].graph);
    DrawGameObject(menu.objBossFighterGraph, menu.objBossFighterGraph.graph);
    DrawGameObject(menu.objBossShipGraph, menu.objBossShipGraph.graph);

    // �_�̕`��
    for (int i = 0; i < MENU_CLOUD_NUM; i++)
    {
        DrawGameObject(menu.objCloudGraph[i], menu.objCloudGraph[i].graph);
    }

    // �X�e�[�W�I���摜�̕`��
    DrawGameObject(menu.objStageGraph[0], menu.objStageGraph[0].graph);
    DrawGameObject(menu.objStageGraph[1], menu.objStageGraph[1].graph);
    DrawGameObject(menu.objStageGraph[2], menu.objStageGraph[2].graph);

    // �X�e�[�W�_���[�W�摜�̕`��
    DrawGlassCracking(menu);

    // �I�y���[�^�[�̕`��
    DrawGameObject(menu.menuTalkGraph, menu.menuTalkGraph.graph);

    // �^�C�g���̉摜
    DrawGraph(350, 20, menu.titleGraph, true);
    
    // �t���[���g
    //DrawGraph(900, 500, menu.frameGraph, true);

    // ���̕`��
    DrawGraph(CROSSKEY_X_POS, CROSSKEY_Y_POS, menu.crossKey, true);

    // �ˌ��L�[
    DrawGraph(SHOT_KEY_X_POS, SHOT_KEY_Y_POS, menu.spaceKeyGraph, true);

    // �Ԗ��
    if (CheckHitKey(KEY_INPUT_LEFT) == 1 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) != 0)
    {
        DrawGraph(CROSSKEY_X_POS, CROSSKEY_Y_POS, menu.leftKeyRedGraph, true);
    }
    if (CheckHitKey(KEY_INPUT_RIGHT) == 1 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) != 0)
    {
        DrawGraph(CROSSKEY_X_POS, CROSSKEY_Y_POS, menu.rightKeyRedGraph, true);
    }
    if (CheckHitKey(KEY_INPUT_UP) == 1 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP) != 0)
    {
        DrawGraph(CROSSKEY_X_POS, CROSSKEY_Y_POS, menu.upKeyRedGraph, true);
    }
    if (CheckHitKey(KEY_INPUT_DOWN) == 1 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN) != 0)
    {
        DrawGraph(CROSSKEY_X_POS, CROSSKEY_Y_POS, menu.downKeyRedGraph, true);
    }
    // �ˌ��L�[
    if (CheckHitKey(KEY_INPUT_SPACE) != 0 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)
    {
        DrawGraph(SHOT_KEY_X_POS, SHOT_KEY_Y_POS, menu.spaceKeyRedGraph, true);
    }

    // �u�ړ��L�[�v�摜�`��
    DrawGraph(800, 700, menu.moveStringGraph, true);

    // �u�ˌ��L�[�v�摜�`��
    DrawGraph(150, 700, menu.shotStringGraph, true);

}







