#include "player.h"
#include<cassert>

void Player::Initialize(Model* model, ViewProjection* viewProjection){
assert(model);
model_ = model;
viewProjection_ = viewProjection;
worldTransform_.Initialize();

}
void Player::update(){
	worldTransform_.UpdateMatrix();

}
void Player::Draw(){
//3Dモデルを描画
	model_->Draw(worldTransform_,*viewProjection_);
}