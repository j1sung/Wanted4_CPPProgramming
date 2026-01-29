#include "Player.h"
#include <iostream>


Player::Player()
	:Player(0, 0, 0.0f)
{

}

Player::Player(int id, int score, float attack)
	:id(id), score(score), attack(attack)
{

}
Player::~Player()
{

}

// 직렬화 (파일에 쓰기).
void Player::Serialize(const char* path)
{
	// 열기
	FILE* file = nullptr;
	errno_t error = fopen_s(&file, path, "wt");
	
	// 예외처리.
	if (!file)
	{
		std::cout << "Failed to open file.\n";

		__debugbreak();
		return;
	}

	//// 파일에 저장할 데이터 만들기.
	//char outputData[256] = {}; 
	//sprintf_s(outputData, 256, "id=%d score=%d attack=%f", id, score, attack);

	//// 데이터 정리.
	//size_t length = strlen(outputData);
	//memset(outputData + length, 0, 256 - length);

	//// 파일에 데이터 기록.
	//size_t writtenSize = fwrite(outputData, sizeof(char), 256, file);


	size_t writtenSize = fprintf_s(file, "id=%d score=%d attack=%f", id, score, attack);

	// 파일 닫기
	fclose(file);
}

// 역직렬화 (파일에서 읽기).
void Player::Deserialize(const char* path)
{
	// 파일 열기.
	FILE* file = nullptr;
	errno_t error = fopen_s(&file, path, "rt");

	// 예외처리.
	if (!file)
	{
		std::cout << "Failed to open file.\n";

		__debugbreak();
		return;
	}

	size_t readSize = fscanf_s(file, "id=%d score=%d attack=%f", &id, &score, &attack);

	fclose(file);

}