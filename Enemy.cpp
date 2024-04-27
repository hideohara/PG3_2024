#include "Enemy.h"
#include <stdio.h>


// staticで宣言したメンバ関数ポインタテーブルの実体
void (Enemy::* Enemy::spFuncTable[])() = {
  &Enemy::Closer,	// 要素番号0
  &Enemy::Shot,	// 要素番号1
  &Enemy::Leave,	// 要素番号1
};

void Enemy::Update()
{
	//TestFunc();

	//// メンバ関数ポインタに関数のアドレスを代入する
	//pFunc = &Enemy::TestFunc;
	//(this->*pFunc)();

	//pFunc = &Enemy::TestFunc2;
	//(this->*pFunc)();

	//pFunc = &Enemy::TestFunc3;
	//(this->*pFunc)();


	//for (int i = 0; i < 3; i++) {
	//	// メンバ関数ポインタに入っている関数を呼び出す
	//	(this->*spFuncTable[i])();
	//}

	//Step = Step::Closer;
	//step_ = Step::kShot;
	//(this->*spFuncTable[(size_t)Step::kShot])();

	//for (int step_ = 0; step_ < 3; step_++) {
	//	// メンバ関数ポインタに入っている関数を呼び出す
	//	(this->*spFuncTable[step_])();
	//}

	// 関数ポインタを使用して各関数を呼び出す
	(this->*spFuncTable[(size_t)step_])();
}

// 接近
void Enemy::Closer()
{
	printf("Closer\n");

	// 次の状態を指定
	step_ = Step::kShot;
}

// 射撃
void Enemy::Shot()
{
	printf("Shot\n");

	// 次の状態を指定
	step_ = Step::kLeave;
}

// 離脱
void Enemy::Leave()
{
	printf("Leave\n");

	// 次の状態を指定
	step_ = Step::kCloser;
}
