#include <iostream>

// 클래스.
class Entity
{
public:
	Entity() 
	{
		std::cout << "Entity() called\n";
	};
	~Entity() 
	{
		std::cout << "~Entity() called\n";
	};

protected:
	float x = 0.0f;
	float y = 0.0f;
};

class Weapon
{
public:
	void Attack()
	{

	}
};

// : 다음에 상속할 부모 클래스 타입 지정.
class Player : public Entity
{
public:
	Player() 
	{
		std::cout << "Player() called\n";
	}

	~Player()
	{
		std::cout << "~Player() called\n";
	}

	void Attack(Weapon* weapon)
	{
		weapon->Attack();
	}

private:
	char* name = nullptr;
};

int main()
{
	//Entity entity;
	Player player;
	//Weapon sword = nullptr;;

	//player.Attack(&sword);
	//player.Attack(sword); // nullptr로 주소가 없어서 안됨


	std::cin.get();
	return 0;
}