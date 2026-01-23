#include "Entity.h"
#include "../Vector.h"
#include <iostream>
//#include "../Main.cpp" // #include가 파일 들어가서 복사하는거니 cpp도 됨
//#include <../Vector.h> // 이건 왜 안될까? <>는 이 범위 내에서만 보고 ""는 상대경로까지 보기 때문이다.
//#include <iostream> // 이거는 그럼 이 영역에 없는데 왜 돼? -> vs가 지정함 경로

//// 굳이 Entity/Entiy.h를 안해도 디렉터리 경로 설정을 해놓으면 <>든 ""든 다 가능
//#include <Entity/Entity.h>
//#include <Entity.h>
//#include "Entity.h" 

// using namespace Wanted;
// using namespace std; // 안쓰는게 좋음 너무 많은게 있어서

Entity::Entity(int x, int y)
{
	position = new Vector();
	position->x = x;
	// (*position).x = x;
	position->y = y;

}

Entity::Entity(const Entity& other)
{
	std::cout << "copy construcotr called\n";
	// 기본 복사 생성자가 하는 일
	// 값 복사 -> 다른 경로 설정
	// 나중에 댕글링 포인터 문제 발생
	// 댕글링(dangling) - 주인을 잃어버림
	// -> 이미 삭제된 메모리 주소에 접근.
	//  position = other.position;

	// 깊은 복사(Deep copy).
	// 공간 확보
	position = new Vector();

	// 값 복사.
	position->x = other.position->x;
	position->y = other.position->y;
}

Entity::~Entity()
{
	if (position)
	{
		delete position;
		position = nullptr;
	}
}