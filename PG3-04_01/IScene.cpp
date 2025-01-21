#include "IScene.h"

int IScene::sceneNo = Scene::TITLE;

IScene::~IScene() {}

int IScene::GetSceneNo() { return sceneNo; }