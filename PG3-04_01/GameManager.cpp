#include "GameManager.h"

GameManeger::GameManeger() {

	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	currentSceneNo_ = TITLE;
	prevSceneNo_ = 0;
}

GameManeger::~GameManeger() {}

int GameManeger::Run() {

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame(); //フレームの開始

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		if (prevSceneNo_ != currentSceneNo_)
			sceneArr_[currentSceneNo_]->Initialize();

		/// ↓更新処理ここから

		sceneArr_[currentSceneNo_]->Update(keys, preKeys);
		/// ↑更新処理ここまで

		/// ↓描画処理ここから

		sceneArr_[currentSceneNo_]->Draw();
		/// ↑描画処理ここまで

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0)
			break;
	}

	return 0;
}
