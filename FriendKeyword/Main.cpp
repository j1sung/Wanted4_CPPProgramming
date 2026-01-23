#include <iostream>

class Entity
{// 기본 생성자/소멸자는 컴파일러가 채워줌

public:
	// 정답.
	//int GetX() const { return x; }

	// 2. friend를 통해서 외부 접근 권한을 한시적으로 줌
	//friend void ShowEntity(Entity& entity);
	friend void ShowEntity(Entity& entity) // 실제론 멤버함수로 friend를 씀
	{
		std::cout << entity.x << ", " << entity.y << "\n";
	}

	friend void Add(Entity& entity1, Entity& entity2);

	void Add(Entity& other) // 접근한정자는 클래스 타입에 대해 지정해서 같은 클래스 타입이라 other도 접근이 가능하다.
	{						// 다른 객체니까 한정자가 객체 단위로 적용될거 같은데 그렇지 않아서 클래스 타입단위라 다른 객체여도 같은 타입이라 접근이 가능한거다.
		x + other.x; // 왜 other 접근이?
		y + other.y;
	}

	friend void Add(Entity& entity1, Entity& entity2)
	{
		entity1.x + entity2.x;
		entity1.y + entity2.y;
	}

	// 접근 한정자/제한자/(Visibility)가시성.
private:
	int x = 0;
	int y = 0;
};

//void Add(Entity& entity1, Entity& entity2)
//{
//	entity1.x + entity2.x;
//	entity1.y + entity2.y;
//}

// 1. 외부 함수 먼저 정의
// Entity 정보를 출력하는 함수.
//void ShowEntity(Entity& entity)
//{
//	std::cout << entity.x << ", " << entity.y << "\n";
//}

int main()
{
	Entity entity;

	Entity entity1;
	Entity entity2;
	
	Add(entity1, entity2);

	//entity1.Add(entity2);
	//entity.ShowEntity() 
	// -> 이건 friend는 멤버함수가 아니고 외부함수에 정의하고 그걸 객체에서 friend로 접근하니 안됨
	ShowEntity(entity);

	std::cin.get();
	return 0;
}