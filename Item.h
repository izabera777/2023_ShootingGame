#pragma once

// �萔
#define ITEM_SPEED		3	// �A�C�e���̈ړ����x
#define ITEM_RAND_MAX	2	// �A�C�e���̎��

// ���
enum ItemType
{
	MULTI_SHOT,		// 3WAY�V���b�g
	BOM,			// �{��
	MEDICAL_KIT,	// ��
	MISSILE			// �~�T�C��
};


// �v���g�^�C�v�錾
struct GameObject;

// �RWAY�V���b�g�p
struct ItemMultiShot
{
	GameObject obj;
};

// �{��
struct ItemBom
{
	GameObject obj;
};

// ��
struct ItemMedicalKits
{
	GameObject obj;
};

// �~�T�C��
struct ItemMissile
{
	GameObject obj;
};



// �A�C�e��
struct Item
{
	ItemMultiShot		multiShot;		// �RWAY�V���b�g
	ItemBom				bom;			// �{��
	ItemMedicalKits		medicalKits;	// �񕜃p�b�N
	ItemMissile			missile;		// �~�T�C��
};


// �֐��v���g�^�C�v�錾

/// <summary>
/// �A�C�e���̏�����
/// </summary>
/// <param name="item">�A�C�e���\����</param>
void InitItem(Item& item);

/// <summary>
/// �A�C�e���ƃv���C���[�̓����蔻��
/// </summary>
/// <param name="item">�A�C�e���\����</param>
/// <param name="target">�v���C���[�\����</param>
/// <returns>�����������A�������ĂȂ���</returns>
bool IsHitObject(GameObject& item, GameObject& target, Sound& sound);

/// <summary>
/// �A�C�e���̈ړ�
/// </summary>
/// <param name="obj">�A�C�e���\����</param>
void MoveItem(GameObject& obj);

void UpdateItem(Game& game);


/// <summary>
/// �A�C�e���̕`��
/// </summary>
/// <param name="item">�A�C�e���\����</param>
void DrawItem(Item& item);











