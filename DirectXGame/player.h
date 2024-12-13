#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
class Player
{
private:
	//ワールド変換データ
	WorldTransform worldTransform_;
	//モデル
	Model* model_ = nullptr;

	ViewProjection* viewProjection_ = nullptr;

public:
	///<summary>
	///初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="textuHandle">テクスチャハンドル</param>
	void Initialize(Model*model,ViewProjection*viewProjection);

	///<summary>
	///更新
	/// </summary>
	void update();

	///<summary>
	///描画
	/// </summary>
	void Draw();
};

