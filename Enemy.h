#pragma once


class Enemy
{
public:
	// 更新
	void Update();

	// 各状態の関数
	void Closer();
	void Shot();
	void Leave();

private:
	// メンバ関数ポインタ
	// void (Enemy::* pFunc)();

	// メンバ関数ポインタのテーブル
	static void (Enemy::* spFuncTable[])();

	// 状態を定義
	enum class Step
	{
		kCloser,
		kShot,
		kLeave
	};

	// 現在の状態
	Step step_= Step::kCloser;
};

