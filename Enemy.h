#pragma once


class Enemy
{
public:
	// �X�V
	void Update();

	// �e��Ԃ̊֐�
	void Closer();
	void Shot();
	void Leave();

private:
	// �����o�֐��|�C���^
	// void (Enemy::* pFunc)();

	// �����o�֐��|�C���^�̃e�[�u��
	static void (Enemy::* spFuncTable[])();

	// ��Ԃ��`
	enum class Step
	{
		kCloser,
		kShot,
		kLeave
	};

	// ���݂̏��
	Step step_= Step::kCloser;
};

