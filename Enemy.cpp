#include "Enemy.h"
#include <stdio.h>


// static�Ő錾���������o�֐��|�C���^�e�[�u���̎���
void (Enemy::* Enemy::spFuncTable[])() = {
  &Enemy::Closer,	// �v�f�ԍ�0
  &Enemy::Shot,	// �v�f�ԍ�1
  &Enemy::Leave,	// �v�f�ԍ�1
};

void Enemy::Update()
{
	//TestFunc();

	//// �����o�֐��|�C���^�Ɋ֐��̃A�h���X��������
	//pFunc = &Enemy::TestFunc;
	//(this->*pFunc)();

	//pFunc = &Enemy::TestFunc2;
	//(this->*pFunc)();

	//pFunc = &Enemy::TestFunc3;
	//(this->*pFunc)();


	//for (int i = 0; i < 3; i++) {
	//	// �����o�֐��|�C���^�ɓ����Ă���֐����Ăяo��
	//	(this->*spFuncTable[i])();
	//}

	//Step = Step::Closer;
	//step_ = Step::kShot;
	//(this->*spFuncTable[(size_t)Step::kShot])();

	//for (int step_ = 0; step_ < 3; step_++) {
	//	// �����o�֐��|�C���^�ɓ����Ă���֐����Ăяo��
	//	(this->*spFuncTable[step_])();
	//}

	// �֐��|�C���^���g�p���Ċe�֐����Ăяo��
	(this->*spFuncTable[(size_t)step_])();
}

// �ڋ�
void Enemy::Closer()
{
	printf("Closer\n");

	// ���̏�Ԃ��w��
	step_ = Step::kShot;
}

// �ˌ�
void Enemy::Shot()
{
	printf("Shot\n");

	// ���̏�Ԃ��w��
	step_ = Step::kLeave;
}

// ���E
void Enemy::Leave()
{
	printf("Leave\n");

	// ���̏�Ԃ��w��
	step_ = Step::kCloser;
}
