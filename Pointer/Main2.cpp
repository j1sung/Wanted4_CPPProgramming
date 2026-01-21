#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

void DeletePointer(void* ptr) // void* ptr = pointer; 
{                             // 여기선 int x = y 처럼 값의 복사가 일어남
	if (ptr != nullptr)
	{
		delete ptr; // 여기서 힙 메모리 해제
		ptr = nullptr;
	}
}
// &pointer -> pointer 변수의 주소
// pointer -> pointer가 들고 있는 주소값
// *pointer -> 그 주소에 저장된 실제 데이터

int main()
{   
	// 프로그램 끝날때 _CrtDumpMemoryLeaks();를 자동호출 시키는 함수이다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); 

	//_CrtSetBreakAlloc(159);

	// Todo: 메모리 릭 일부러
	int* intPointer = new int;
	//delete intPointer; // 힙 메모리를 해제하니 leck 문제가 사라졌다.

	// 동적 할당.
	char* buffer = new char[10];

	void* pointer = new int; 
	// new 하면 힙에 int 한개를 만들고, 이 힙 메모리 주소를 pointer에 저장
	// new 는 동적으로 만든 힙의 주솟값을 반환하기 때문이다.

	DeletePointer(pointer);

	// null check
	if (pointer != nullptr)
	{
		std::cout << "Pointer is not null\n";
	
	}
	else
	{
		std::cout << "Pointer is null\n";
	}

	std::cin.get();
}