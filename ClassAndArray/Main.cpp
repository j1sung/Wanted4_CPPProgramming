#include <iostream>

// 게임 물체(객체)
// Game-Object / Actor / Entity(개체).
// 유니티 / 언리얼 / ?

// 클래스
class Entity
{
public:
	Entity()
	{
		std::cout << "Constructor called\n";
	}
	~Entity() = default; // 소멸자 생략해도 컴파일러가 만들어주지만 명시하는게 좋음 = default, {}로 기본 지정

	// 함수 끝에 const를 지정하면,
	// 함수 본문에서 객체 내부의 값을 변경할 수 없음.
	void ShowName() const // const를 main에서함수에다가 써서 여기도 const 지정해야함
	{
		//number = 10;
		std::cout << "Entity.\n";
	}

	const Entity* GetSelf() const // this는 const 하려면 const 앞뒤로
	{
		//this는 자기 자신을 가리키는 ' 포인터'
		return this;
	}

	//int number = 0;
};

//// C언어로 번역되어서 이렇게 함수가 만들어진다.
//// 함수 자체는 전역 코드 영역에 있다.
//void ShowName(Entity* entity)
//{
//	//
//}

// 설명용이었음
void SafeDelete(Entity** entity)
{
	delete* entity;
	*entity = nullptr;
}

int main()
{
	// 이게 될것인가?? -> 실행은 되는데 왜 될까?
	// 어셈블러 할때 C문법으로 번역을 한다.
	// C++ -> 
	//Entity* entity = nullptr;
	//entity->ShowName(); // 함수 호출 시점에서 null 체크를 안한다. 객체참조에서 null체크를 안해서 실행이 된다?
	// Entity::ShowName(entity); // this = entity
	//ShowName(entity); // C스타일로 이렇게 바뀌어서 실행됨 -> c, c++은 객체 null체크를 안하고/ C#, Java는 null 체크를 한다.

	//const int count = 5;
	//Entity entities[count]; // 생성자는 굳이 초기화 할 멤버변수 없어서 안함

	// Range-Based Loop( foreach ). 순환이 안된다는?
	//for (const Entity& entity : entities) // 변조 안하니 const 붙이는게 좋음
	//{
	//	entity.ShowName(); // 컴파일러 입장에서 선언보고 넘기는데, 보장을 못받아서 빨간줄 나온걸 const붙여서 해결
	//}

	//const int count = 5;
	//Entity* entities[count] = {}; // 이런식으로 초기화 0으로 한다 요즘
	////memset(entities, 0, sizeof(Entity*) * count); // 이건 과거

	//for (int ix = 0; ix < count; ++ix) // 후위 증감식은 임시 복사하는 과정때문에 성능차이 있지만 요즘은 딱히
	//{
	//	entities[ix] = new Entity();
	//}

	//for (Entity*& entity : entities)
	//{
	//	//SafeDelete(entity);
	//	delete entity;
	//	entity = nullptr;
	//}

	// this는 자기 자신을 가리킨다. -> 주소
	Entity* entity = new Entity();
	std::cout << entity << "\n";
	std::cout << entity->GetSelf() << "\n";
	
	delete entity;
	entity = nullptr;

	std::cin.get();
	return 0;
}