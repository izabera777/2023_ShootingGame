#include "Utility.h"
#include "DxLib.h"
#include "GameObject.h"
#include "UI.h"
#include "Shot.h"
#include "Player.h"
#include "Enemy.h"
#include "BG.h"
#include "Menu.h"
#include "Sound.h"
#include "Item.h"
#include "Game.h"


// �A�C�e��������
void InitItem(Item& item)
{
	// �摜�̃��[�h,�T�C�Y�̎擾

	// �RWAY�V���b�g�p
	if (item.multiShot.obj.graph < 0)
	{
		// �摜�̃��[�h
		item.multiShot.obj.graph = LoadGraph("data/texture/MultiShot.png");
		GetGraphSize(item.multiShot.obj.graph, &item.multiShot.obj.w, &item.multiShot.obj.h);
		// �X�e�[�^�X���
		item.multiShot.obj.visibleFlag = false;
		item.multiShot.obj.angle = 0;
		item.multiShot.obj.speed = ITEM_SPEED;
	}
	// �{��
	if (item.bom.obj.graph < 0)
	{
		item.bom.obj.graph = LoadGraph("data/texture/Bom.png");
		GetGraphSize(item.bom.obj.graph, &item.bom.obj.w, &item.bom.obj.h);
		item.bom.obj.visibleFlag = false;
		item.bom.obj.angle = 0;
		item.bom.obj.speed = ITEM_SPEED;
	}
	// �񕜃p�b�N
	if (item.medicalKits.obj.graph < 0)
	{
		item.medicalKits.obj.graph = LoadGraph("data/texture/Medical.png");
		GetGraphSize(item.medicalKits.obj.graph, &item.medicalKits.obj.w, &item.medicalKits.obj.h);
		item.medicalKits.obj.visibleFlag = false;
		item.medicalKits.obj.angle = 0;
		item.medicalKits.obj.speed = ITEM_SPEED;
	}
	// �~�T�C��
	if (item.missile.obj.graph < 0)
	{
		item.missile.obj.graph = LoadGraph("data/texture/Missile.png");
		GetGraphSize(item.missile.obj.graph, &item.medicalKits.obj.w, &item.medicalKits.obj.h);
		item.missile.obj.visibleFlag = true;
		item.missile.obj.angle = 0;
		item.missile.obj.speed = ITEM_SPEED;
	}


}

// �A�C�e���ƃv���C���[�̓����蔻��
bool IsHitObject(GameObject& item, GameObject& target,Sound& sound)
{
	// �����������A�������ĂȂ���
	bool isHit = false;

	// �A�C�e���̓����蔻��
	if (item.visibleFlag == 1)
	{
		// �o�t���̓����蔻�������
		float itemLeft		= item.pos.x   - item.w   * OBJECT_HIT_BUF;
		float itemRight		= item.pos.x   + item.w   * OBJECT_HIT_BUF;
		float itemTop		= item.pos.y   - item.h   * OBJECT_HIT_BUF;
		float itemBottom	= item.pos.y   + item.h   * OBJECT_HIT_BUF;
		float targetLeft	= target.pos.x - target.w * OBJECT_HIT_BUF;
		float targetRight	= target.pos.x + target.w * OBJECT_HIT_BUF;
		float targetTop		= target.pos.y - target.h * OBJECT_HIT_BUF;
		float targetBottmo	= target.pos.y + target.h;

		// �����蔻��
		if (((itemLeft  > targetLeft && itemLeft   < targetRight ) ||
			(targetLeft > itemLeft   && targetLeft < itemRight  )) &&
			((itemTop   > targetTop  && itemTop    < targetBottmo) ||
			(targetTop  > itemTop    && targetTop  < itemBottom)))
		{
			// �����������̌��ʉ����o��
			PlaySoundMem(sound.itemGetSE, DX_PLAYTYPE_BACK, true);

			// �ڐG���Ă���ꍇ�͓��������A�C�e���̑��݂�����
			item.visibleFlag = 0;

			// �������Ă���t���O�𗧂Ă�
			isHit = true;
		}
	}

	// �����������A�������ĂȂ���
	return isHit;
}


// �A�C�e���̈ړ�
void MoveItem(GameObject& obj)
{
	// �A�C�e���̈ړ����[�`���i���݂��Ă���ϐ���true�̂ݍs���j
	if (obj.visibleFlag == true)
	{
		// �A�C�e�����ړ�������
		MoveGameObject(obj);

		// ��ʂ̊O�ɏo�Ă��܂����ꍇ�͑��ݏ�Ԃ�ێ����Ă���ϐ���false����
		if (   obj.pos.y < 0        - obj.h * 0.5f
			|| obj.pos.y > SCREEN_H + obj.h * 0.5f
			|| obj.pos.x < 0        - obj.w * 0.5f
			|| obj.pos.x > SCREEN_W + obj.w * 0.5f)
		{
			obj.visibleFlag = false;
		}
	}
}

// �A�b�v�f�[�g�A�C�e��
void UpdateItem(Game& game)
{
	// �A�C�e���̈ړ�
	MoveItem(game.item.multiShot.obj);		// �RWAY�V���b�g
	MoveItem(game.item.bom.obj);			// �{��
	MoveItem(game.item.medicalKits.obj);	// �񕜃p�b�N
	MoveItem(game.item.missile.obj);		// �~�T�C��

	// �A�C�e���̓����蔻��
	// �}���`�V���b�g
	if (IsHitObject(game.item.multiShot.obj, game.player.obj, game.sound))
	{
		game.player.itemStatus = MULTI_SHOT;
	}

	// �{��
	if (IsHitObject(game.item.bom.obj, game.player.obj, game.sound))
	{
		game.player.bomCount++;
	}

	// �񕜃p�b�N
	if (IsHitObject(game.item.medicalKits.obj, game.player.obj, game.sound) && game.player.life <= 29)
	{
		game.player.life += 7;
		// �v���C���[�̃��C�t����𒴂�����
		if (game.player.life >= 29)
		{
			game.player.life = 29;
		}
	}

	// �~�T�C��
	if (IsHitObject(game.item.missile.obj, game.player.obj, game.sound))
	{
		game.player.itemStatus = MISSILE;
	}



}


// �`��
void DrawItem(Item& item)
{
	// �RWAY�V���b�g
	if (item.multiShot.obj.visibleFlag == true)
	{
		DrawGameObject(item.multiShot.obj, item.multiShot.obj.graph);
	}
	// �{��
	if (item.bom.obj.visibleFlag == true)
	{
		DrawGameObject(item.bom.obj, item.bom.obj.graph);
	}
	// �񕜃p�b�N
	if (item.medicalKits.obj.visibleFlag == true)
	{
		DrawGameObject(item.medicalKits.obj, item.medicalKits.obj.graph);
	}
	// �~�T�C��
	if (item.missile.obj.visibleFlag == true)
	{
		DrawGameObject(item.missile.obj, item.missile.obj.graph);
	}
}





