#include <iostream> // "iostream"도 가능하다.
#include "Entity/Entity.h"
// #include에서 <> 랑 "" 차이가 뭘까?
// ""가 검색범위가 <>보다 더 넓다.
// ""는 상대경로로 찾는다 -> 현재 경로 기준

void TestFunction(Entity entity)
{
	std::cout << "TestFunction\n";
}

int main()
{
	// 프로그램 종료시 entity 먼저 회수
	// 이후 entity2도 메모리 해제하려는데 같은 주소를 참조해서 이미 삭제된걸 접근할때 
	// entity2는 댕글링 포인터가 된다.
	Entity entity(10, 20);
	Entity entity2(entity);
	Entity entity3 = entity2;

	TestFunction(entity3);

	std::cin.get();
	return 0;
}