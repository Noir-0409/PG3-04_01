#pragma once
#include "math/Vector2.h"
#include <Novice.h>
#include <KamataEngine.h>

class Player {
public:
	Player();

	void Init();
	void Update();
	void Draw();

	// メンバ関数
	void MoveRight();
	void MoveLeft();

private:
	KamataEngine::Vector2 position_{};

	float speed_ = 3.0f;
};