#include "Player.h"
#include <iostream>

// 생성자 -> 기본값 설정/자원 할당.
Player::Player() 
{

}

Player:: Player(const char* inName)
	// :x(0), y(0), speed(0) // 멤버 이니셜 라이저 -> 멤버변수 초기화와 시점이 같음
	//멤버 이니셜라이저는 동적 할당은 못함
{
	// x = 0; 이걸 여기서 할 수 있으면 위에서 하는게 좋음

	// 동적 할당 및 ㄷ문자열 복사.
	size_t length = strlen(inName) + 1; // 널문자공간 1 추가
	name = new char[length];

	// 복사 처리 -> 참조 아님
	strcpy_s(name, length, inName);
}

// 자원 해제.
Player::~Player()
{
	// null 체크.
	if(name) // 0 아닌 어떤값도 다 true
	{
		delete[] name;
		name = nullptr;
	}
}

// 구현 따로 하기
// Player:: <- Player 클래스 안에 있는.
// :: 범위 지정 연산자.
void Player::Move(int inX, int inY)
{
	x = inX;
	y = inY;
}
