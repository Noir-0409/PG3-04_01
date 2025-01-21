#include <Novice.h>
#include "GameManager.h"

const char kWindowTitle[] = "PG3";

// Windowsアプリでのmain関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	GameManeger* gameManeger = new GameManeger();

	gameManeger->Run();

	// ライブラリの終了
	Novice::Finalize();

	delete gameManeger;

	return 0;
}
