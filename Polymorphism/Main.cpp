#include <iostream>

// 매크로 안에서 어떤 항목 앞에 #을 붙이면
// 무지성(무조건)으로 문자열로 변환함.
#define NAME(x) #x // 장문(2byte)로 할F면 앞에 L을 붙여라

#define PURE 0

// 순수 가상 함수를 가지는 클래스 -> 구현 강제하고 싶을 때 씀
// 인터페이스.
// 순수 가상 함수만 가져야 함
class NameInterface
{
public: // 외부 다른 객체가 접근할 수 있기 위해 쓰는 기법이므로 public!!
	// 순수 가상 함수(Pure). -> 왜 사용하는가? 공통점 약속 코드 줄이기
	virtual const char* GetName() const = 0; // =0을 붙여서 내용이 없는 순수 가상함수 선언
	//virtual const char* GetName() const = PURE;

};

class Entity: public NameInterface
{
public:
	//const char* Getame() const { return "Entity"; }
	virtual const char* GetName() const override
	{
		return NAME(Entity); 
	}
};

class Player : public NameInterface
{
public:
	Player(const char* name)
	{
		// 내부의 name 설정.
		// 크기.
		size_t length = strlen(name) + 1;
		// 할당
		this->name = new char[length];

		// 문자열 복사.
		strcpy_s(this->name, length, name);
	}

	~Player()
	{
		if (name) {
			delete[] name;
			name = nullptr;
		}
	}

	// 앞 const 반환 char 변형X, 뒤 const name 변형 X
	virtual const char* GetName() const override 
	{
		return name;
	}   

private:
	char* name = nullptr;
};

int main()
{
	Entity* entities[250] = {};

	Entity* entity = new Entity();
	std::cout << entity->GetName() << "\n";
	entities[0] = entity;

	Player* player = new Player("Jisung");
	//Entity* player = new Player("Jisung"); // 굳이 업캐스팅은 형변환 안써도 됨

	std::cout << player->GetName() << "\n";
	//entities[1] = player; // 업 캐스팅으로 가능

	//NameInterface* test = new NameInterface();

	delete player;
	delete entity;


	std::cin.get();
	return 0;
}