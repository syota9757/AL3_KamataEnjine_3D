#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>


// 3x3の回転行列を表す構造体
typedef struct {
    float m[3][3];
} Matrix3x3;

// 3x1のベクトルを表す構造体
typedef struct {
    float v[3];
} Vector3;

// アフィン変換行列を作成する関数
void CreateAffineTransform(Matrix3x3* rotation, Vector3* translation, Matrix3x3* result)
{
    // 回転行列をコピー
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result->m[i][j] = rotation->m[i][j];
        }
    }

    // 平行移動ベクトルを適用
    for (int i = 0; i < 3; ++i) {
        result->m[i][3] = translation->v[i];
    }

    // 最下行を設定
    result->m[3][0] = 0.0f;
    result->m[3][1] = 0.0f;
    result->m[3][2] = 0.0f;
    result->m[3][3] = 1.0f;
}



GameScene::GameScene() {}

//デストラクタ
GameScene::~GameScene() {
	delete sprite_;
	delete model_;
<<<<<<< Updated upstream
=======
	
	delete player_;


	for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {
		delete worldTransformBlock;
	}
	worldTransformBlocks_.clear();
>>>>>>> Stashed changes
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

<<<<<<< Updated upstream
	//ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("gaidoline.png");
	//スプライトの生成
	sprite_ = Sprite::Create(textureHandle_, {100, 50});
   //3Dモデルの生成
	model_ = Model::Create();

	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	//ビュープロジェクションの初期化
	viewProjection_.Initialize();
}

void GameScene::Update() {
//スプライトの今の座標を取得
	Vector2 position = sprite_->GetPosition();
	//座標を{2,1}移動
	position.x += 2.0f;
	position.y += 1.0f;
	//移動した座標をスプライトに反映	
	sprite_->SetPosition(position);
=======
//3Dモデルの生成
	model_ = Model::Create(); 


   //自キャラの生成
	player_ = new Player();
	//自キャラの初期化
	player_->Initialize(model_,TextureHandle_,&viewProjection_);


	//要素数
	const uint32_t kNumBlockHorizontal = 20;
	//ブロック1個分
	const float kBlockWidth = 2.0f;
	//要素数を変更する
	worldTransformBlocks_.resize(kNumBlockHorizontal); 

	//キューブの生成
	for (uint32_t i = 0; i < kNumBlockHorizontal; ++i) {
		worldTransformBlocks_[i] = new WorldTransform();
		worldTransformBlocks_[i]->Initialize();
		worldTransformBlocks_[i]->translation_.x = kBlockWidth + i;
		worldTransformBlocks_[i]->translation_.y = 0.0f;
	}
}

void GameScene::Update() {
////スプライトの今の座標を取得
//	Vector2 position = sprite_->GetPosition();
//	//座標を{2,1}移動
//	position.x += 2.0f;
//	position.y += 1.0f;
//	//移動した座標をスプライトに反映	
//	sprite_->SetPosition(position);

	//自キャラの更新
	player_->update();

	//ブロックの更新
	for (WorldTransform* worldTransformBlock :
		worldTransformBlocks_) { 
	    //平行移動
		Matrix4x4 result{
			1.0f,0.0f,0.0f,0.0f,
			0.0f,1.0f,0.0f,0.0f,
			0.0f,0.0f,1.0f,0.0f,
			worldTransformBlock->translation_.x,
			worldTransformBlock->translation_.y,
			worldTransformBlock->translation_.z,
			1.0f };

		//平行移動だけ代入
		worldTransformBlock->matWorld_ = result;

		//定数バッファに転送する
		worldTransformBlock->TransferMatrix();

	}
>>>>>>> Stashed changes
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>
	sprite_->Draw();

	
	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	// 3Dモデル描画
<<<<<<< Updated upstream
	model_->Draw(worldTransform_, viewProjection_, textureHandle_);
=======
	//model_->Draw(worldTransform_, viewProjection_, TextureHandle_);]
	
	//ブロックの描画
	for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {
		   modelBlock_->Draw(*worldTransformBlock, viewProjection_);
	}
>>>>>>> Stashed changes
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
