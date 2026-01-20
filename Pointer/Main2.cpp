#include <iostream>

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