#include "Skydome.h"
void Skydome::Initilize() {};
void Skydome::Update() {};
void Skydome::Draw() {
	model_->Draw(worldTransform_,  viewProjection_);
};
 