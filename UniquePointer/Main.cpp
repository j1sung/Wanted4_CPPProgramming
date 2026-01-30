#include <iostream>
#include <memory>

class Player
{
public:
	Player()
	{
		std::cout << "생성자 호출\n";

	}
	
	Player(const Player& other) = delete; // -> 이런 방식으로 unique_ptr에 복사를 막거나
	Player& operator=(const Player& other) = delete;
//private: // 이렇게 예전방식으로도 막을 수 있다. private라서 복제 안됨
//	Player(const Player& other)
//	{
//	}
//	Player& operator = (const Player& other)
//	{
//		return *this;
//	}

	~Player()
	{
		std::cout << "소멸자 호출\n";
	}
};

// void Function(std::unique_ptr<Player>& player) // 1) // 참조로 받으면 소유권을 이전받은거처럼 공유 접근으로 되긴함.
//void Function(Player* player) // 2)
void Function(Player& player) // 3)
{
	// 위험한 코드 1) 참조로 받으면 이런게 가능한데 절대 안됨!
	//Player* rawPointer = player.get(); // 스마트포인터는 .get()으로 원시 포인터를 받아올 수 있는데
	//delete rawPointer; //이렇게 삭제가 가능한데 하면 안됨
	//player->

	// 위험한 코드 2)
	//delete player;

	// 3)
	//delete player; // 이건 그래도 막힘

	std::cout << "Player 받음\n";
}

int main()
{

	//Player player;
	//Player player2 = player;
	//palyer2 = palyer;


	// unique_ptr 객체 선언. 공간의 소유권을 한 객체에만 주는 포인터.
	std::unique_ptr<Player> player = std::make_unique<Player>();

	//Function(player); // 1) 복사생성자 delete되어서 기본적으로는 못쓴다. -> 대신 파라미터를 참조(래퍼런스)로 받으면 가능하다.
	//Function(player.get()); // 2)
	Function(*player); // 3)
	//Function(std::make_unique<Player>()); // 임시로 파라미터로 소유한경우만 가능

	//std::unique_ptr<Player> player2 = player; // 이렇게 바로 대입하는 복사는 안된다! -> std::move만 됨

	/*std::unique_ptr<Player> player2;
	player2 = std::move(player);*/


	//std::cin.get();
	return 0;
}