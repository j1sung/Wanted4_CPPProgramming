#include "Player.h"

// 생성자 -> 기본값 설정/자원 할당.
Player::Player() 
{

}

// 자원 해제.
Player::~Player()
{

}

// 구현 따로 하기
// Player:: <- Player 클래스 안에 있는.
// :: 범위 지정 연산자.
void Player::Move(int inX, int inY)
{
	x = inX;
	y = inY;
}
