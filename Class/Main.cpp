#include <iostream>

#include "Player.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//// 클래스 조작 함수
//void Move(Player& player, int x, int y) 
//{
//	player.SetX(x);
//	player.SetY(y);
//}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 인스턴스/객체
	Player player1;
	//player1.SetX(5);
	//player1.SetY(2);
	player1.SetSpeed(3);
	player1.Move(5, 2); // 클래스에서 함수 선언만 있지만 컴파일에서 일단 넘어가고 실제 구현은 링커가 연결

	// 힙
	// 1차 포인터
	Player* player2 = new Player("Jisung"); // 2번째 생성자 사용해봄
	player2->Move(3, 1);
	(*player2).Move(3, 1);

	//// 2차 포인터로 접근한다면?
	//Player** player3 = new Player();
	//(*player3)->Move(2, 1);
	//(*(*player3)).Move(2, 1);

	delete player2;
	player2 = nullptr;

	std::cin.get();
	return 0;
}