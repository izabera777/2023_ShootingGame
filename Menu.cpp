//インクルード
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

//関数実装

////////////////////////////////////
//メニュー画面
////////////////////////////////////

// メニュー画面を初期化
void InitMenu(Menu& menu, int graph)
{
    // 背景画像の初期化
    menu.obj.graph = graph;
    GetGraphSize(menu.obj.graph, &menu.obj.w, &menu.obj.h);	//グラフィックのサイズを得る
    menu.obj.pos.x = menu.obj.w * 0.5f;
    menu.obj.pos.y = (float)(menu.obj.h/2);

    // ステージ画像のロード
    menu.objStageGraph[0].graph = LoadGraph("data/texture/STAGE1Graph.png");
    menu.objStageGraph[1].graph = LoadGraph("data/texture/STAGE2Graph.png");
    menu.objStageGraph[2].graph = LoadGraph("data/texture/STAGE3Graph.png");
    GetGraphSize(menu.objStageGraph[0].graph, &menu.objStageGraph[0].w, &menu.objStageGraph[0].h);
    GetGraphSize(menu.objStageGraph[1].graph, &menu.objStageGraph[1].w, &menu.objStageGraph[1].h);
    GetGraphSize(menu.objStageGraph[2].graph, &menu.objStageGraph[2].w, &menu.objStageGraph[2].h);
    
    // そのままのサイズでは大きすぎるので調整
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

    // メニュー
    menu.objStageSelectBot.graph = LoadGraph("data/texture/myimg.png");

    // メニュー上で動かしたいオブジェクトの読み込み
    // 画像の読み込み
    // 雲
    menu.objFighterGraph[0].graph   = LoadGraph("data/texture/enemyVerticalMenu.png");  // 戦闘機１
    menu.objFighterGraph[1].graph   = LoadGraph("data/texture/enemyHorizonMenu.png");   // 戦闘機２
    menu.objBossFighterGraph.graph  = LoadGraph("data/texture/BossMenu1.png");          // ボス（爆撃機）
    menu.objBossShipGraph.graph     = LoadGraph("data/texture/BossShip1.png");          // ボス（海上爆撃機）
    // 座標の初期化
    menu.objFighterGraph[0].pos.x   = 0;    // 戦闘機１
    menu.objFighterGraph[0].pos.y   = 50;
    menu.objFighterGraph[1].pos.x   = -100; // 戦闘機２
    menu.objFighterGraph[1].pos.y   = 100;
    menu.objBossFighterGraph.pos.x  = 1700; // ボス（爆撃機）
    menu.objBossFighterGraph.pos.y  = 600;
    menu.objBossShipGraph.pos.x     = 1700; // ボス（海上爆撃機）
    menu.objBossShipGraph.pos.y     = 300;

    // 移動キー、ショット画像
    menu.crossKey           = LoadGraph("data/texture/crossKey.png");
    menu.rightKeyRedGraph   = LoadGraph("data/texture/crossKeyRight.png");
    menu.leftKeyRedGraph    = LoadGraph("data/texture/crossKeyLeft.png");
    menu.upKeyRedGraph      = LoadGraph("data/texture/crossKeyUp.png");
    menu.downKeyRedGraph    = LoadGraph("data/texture/crossKeyDown.png");
    menu.spaceKeyGraph      = LoadGraph("data/texture/Xoff.png");
    menu.spaceKeyRedGraph   = LoadGraph("data/texture/Xon.png");

    // タイトル
    menu.titleGraph = LoadGraph("data/texture/titleGraph.png");

    // 雲の画像ロード
    for (int i = 0; i < 3; i++)
    {
        menu.objCloudGraph[i].graph = LoadGraph("data/texture/ドット雲400.png");
    }
    // 雲の座標設定
    for (int i = 0; i < MENU_CLOUD_NUM - 1; i++)
    {
        menu.objCloudGraph[i].pos.x = -100 * i;
    }
    menu.objCloudGraph[2].pos.x = 1700;
    menu.objCloudGraph[0].pos.y = 100;
    menu.objCloudGraph[1].pos.y = 500;
    menu.objCloudGraph[2].pos.y = 800;

    // フレーム
    menu.frameGraph = LoadGraph("data/texture/frame400.png");

    // 移動キー説明文字
    menu.moveStringGraph = LoadGraph("data/texture/moveGraph.png");

    // 射撃キー説明文字
    menu.shotStringGraph = LoadGraph("data/texture/attackGraph.png");

    // 割れていく画像
    menu.glassCrackingGraph[0] = LoadGraph("data/texture/ひび割れ１.png");
    menu.glassCrackingGraph[1] = LoadGraph("data/texture/ひび割れ２.png");
    menu.glassCrackingGraph[2] = LoadGraph("data/texture/ひび割れ３.png");
    menu.glassCrackingGraph[3] = LoadGraph("data/texture/ひび割れ４.png");
    menu.glassCrackingGraph[4] = LoadGraph("data/texture/ひび割れ５.png");
    
    // オペレーター
    menu.menuTalkGraph.graph = LoadGraph("data/texture/XでSTAGEを撃て！.png");
    menu.menuTalkGraph.pos.x = 800;
    menu.menuTalkGraph.pos.y = 900;
}

// メニューアップデート
void  UpdateMenu(Menu& menu,Sound& sound)
{
    // オブジェクトの移動
    // 左から右
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
    // 雲の描画 雲①、雲②
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



    // 右から左
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
    // 雲③
    if (menu.objCloudGraph[2].pos.x <= -100)
    {
        menu.objCloudGraph[2].pos.x = 1700;
    }
    else
    {
        menu.objCloudGraph[2].pos.x -= 1;
    }

    // オペレーター画像の移動
    /*if (menu.menuTalkGraph.pos.x <= -400)
    {
        menu.menuTalkGraph.pos.x = 2200;
    }
    else
    {
        menu.menuTalkGraph.pos.x -= 2;
    }*/


    // メニューの描画
    DrawMenu(menu);

}

// ガラスの割れた描画
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


//メニュー画面描画
void DrawMenu(Menu& menu)
{
    // ステージ背景の描画
    DrawGameObject(menu.obj,menu.obj.graph);

    // オブジェクトの描画
    DrawGameObject(menu.objFighterGraph[0], menu.objFighterGraph[0].graph);
    DrawGameObject(menu.objFighterGraph[1], menu.objFighterGraph[1].graph);
    DrawGameObject(menu.objBossFighterGraph, menu.objBossFighterGraph.graph);
    DrawGameObject(menu.objBossShipGraph, menu.objBossShipGraph.graph);

    // 雲の描画
    for (int i = 0; i < MENU_CLOUD_NUM; i++)
    {
        DrawGameObject(menu.objCloudGraph[i], menu.objCloudGraph[i].graph);
    }

    // ステージ選択画像の描画
    DrawGameObject(menu.objStageGraph[0], menu.objStageGraph[0].graph);
    DrawGameObject(menu.objStageGraph[1], menu.objStageGraph[1].graph);
    DrawGameObject(menu.objStageGraph[2], menu.objStageGraph[2].graph);

    // ステージダメージ画像の描画
    DrawGlassCracking(menu);

    // オペレーターの描画
    DrawGameObject(menu.menuTalkGraph, menu.menuTalkGraph.graph);

    // タイトルの画像
    DrawGraph(350, 20, menu.titleGraph, true);
    
    // フレーム枠
    //DrawGraph(900, 500, menu.frameGraph, true);

    // 矢印の描画
    DrawGraph(CROSSKEY_X_POS, CROSSKEY_Y_POS, menu.crossKey, true);

    // 射撃キー
    DrawGraph(SHOT_KEY_X_POS, SHOT_KEY_Y_POS, menu.spaceKeyGraph, true);

    // 赤矢印
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
    // 射撃キー
    if (CheckHitKey(KEY_INPUT_SPACE) != 0 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) != 0)
    {
        DrawGraph(SHOT_KEY_X_POS, SHOT_KEY_Y_POS, menu.spaceKeyRedGraph, true);
    }

    // 「移動キー」画像描画
    DrawGraph(800, 700, menu.moveStringGraph, true);

    // 「射撃キー」画像描画
    DrawGraph(150, 700, menu.shotStringGraph, true);

}







