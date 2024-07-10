#include "player.h"
#include<cassert>

void Player::Initialize(Model* model, uint32_t textureHandle,ViewProjection* viewProjection){
assert(model);
model_ = model;
textureHandle_ = textureHandle;
viewProjection_ = viewProjection;
worldTransform_.Initialize();

}
void Player::update(){
	worldTransform_.TransferMatrix();

}
void Player::Draw(){
//3Dモデルを描画
	model_->Draw(worldTransform_,*viewProjection_, textureHandle_);
}