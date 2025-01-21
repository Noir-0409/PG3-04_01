#include "ClearScene.h"

void ClearScene::Initialize() {}

void  ClearScene::Update(char* keys, char* preKeys) {
	
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == false) {
		
		sceneNo = Scene::TITLE;
	}
}

void  ClearScene::Draw() {
	Novice::ScreenPrintf(0, 0, "Clear Scene");
	Novice::ScreenPrintf(0, 30, "Push Space");
}