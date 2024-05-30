//----------------------------//
// ユーティリティ（便利）関数群
//----------------------------//
#include "Utility.h"
#include "DxLib.h"
#include <math.h>

static int mStartTime;      //測定開始時刻
static int mCount;          //カウンタ
static float mFps;          //fps
static const int N = 60;  //平均を取るサンプル数
static const int FPS = 60;  //設定したFPS



// 指定された全文字列の幅を取得.
int GetDrawStringWidthFull(char* str)
{
	return GetDrawStringWidth(str, (int)strlen(str));
}

// ディグリーをラジアンに変換
float GetRadian(float degree)
{
	return (PI / 180.0f) * degree;
}



// 初期化
void FpsControll_Initialize()
{
    mStartTime = GetNowCount();
    mCount = 0;
    mFps = 0;
}

// FPS制御
bool FpsControll_Update()
{
    if (mCount == 0) { //1フレーム目なら時刻を記憶
        mStartTime = GetNowCount();
    }
    if (mCount == N) { //60フレーム目なら平均を計算する
        int t = GetNowCount();
        mFps = 1000.f / ((t - mStartTime) / (float)N);
        mCount = 0;
        mStartTime = t;
    }
    mCount++;
    return true;
}

// FPS表示
void FpsControll_Draw()
{
    DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", mFps);
}

// 設定したFPS値になるまで待つ
void FpsControll_Wait()
{
    int tookTime = GetNowCount() - mStartTime;  //かかった時間
    int waitTime = mCount * 1000 / FPS - tookTime;  //待つべき時間
    if (waitTime > 0) {
        Sleep(waitTime);  //待機
    }
}








