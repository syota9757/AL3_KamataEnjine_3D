#pragma once
#include<Model.h>
#include<WorldTransform.h>
#include<ViewProjection.h>
class Skydome
{
public:
	void Initilize();
	void Update();
	void Draw();

private:
	WorldTransform worldTransform_;
	ViewProjection viewProjection_; 
	Model* model_ = nullptr;
};

