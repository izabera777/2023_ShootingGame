

// ゲームオブジェクト
#include "GameObject.h"

// ゲームオブジェクト移動
void MoveGameObject(GameObject& obj)
{
	//VGetでベクトルを設定（方向、ディレクション）
	//VScaleでスピード倍を掛ける	//VScale(何倍かしたい変数,倍率)
	//VAddでX,Y,Z成分を一気に加算する
	VECTOR velocity = VScale(obj.dir, obj.speed);	
	obj.pos = VAdd(obj.pos, velocity);
}

// ゲームオブジェクト描画。違う画像も描画できるようにgraphだけ分けている
void DrawGameObject(GameObject& obj, int graph)
{
	DrawRotaGraph((int)obj.pos.x, (int)obj.pos.y,
		obj.scale,
		obj.angle,
		graph, TRUE);
}
