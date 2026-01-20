#include <iostream>

//void DeletePointer(void** ptr) // void*& ptr -> 포인터의 래퍼런스로 하면 변수 *붙인거 다 지우고 래퍼런스면 그냥 매개변수도 넘겨도 됨
//{
//	if (*ptr != nullptr)
//	{
//		// 댕글링 포인터 = 이미 해제된 힙 주소를 들고있음
//		delete *ptr; // 여기까지만 하면 pointer 스택에는 힙의 주소가 남아 댕글링 포인터임
//		*ptr = nullptr; // 그래서
//		// 넘어온 원본에도 null(0) 이 들어가길 바랬지만 안되는 실수
//	}
//}
///*
//	메모리 할당/해제
//	기본적으로 운영체제에게 요청 -> 자원 관리
//	해제 -> 자원해제만 하고 아무것도 안함
//*/
//
//
//int main()
//{
//	new int[10];
//
//	// 동적 할당.
//	char* buffer = new char[10];
//	// buffer는 스택 new 만나면 힙으로 char크기로 10칸 wjwkd
//
//	// 포인터는 주소를 저장하는 변수
//	//void* pointer = nullptr; // 주소 0번지가 들어가있다.
//	//void* pointer; // 이상한 주소가 들어가있다. -> C#, Java는 0으로 가상머신이 초기화 해준다
//	void* pointer = new int; // pointer 스택에 어딘가 주소가 있고 값을 가지고 있다.
//	DeletePointer(&pointer); // void*로 넘기면 주소가 넘어가지 않아 null인 0으로 초기화가 안된다. 따라서 pointer != nullptr이 안걸림
//	//delete pointer;
//	//pointer = nullptr;
//
//	
//	// null check
//	if (pointer != nullptr) 
//	{
//		std::cout << "Pointer is not null\n";
//
//	}
//	else
//	{
//		std::cout << "Pointer is null\n";
//	}
//
//	//의미는 없음.
//	std::cin.get(); // 여기다 중단점 놓고 디버깅으로 포인터 주소 확인
//}

/*
	프로그래밍 -> 변수 값 저장 잘 되고, 원하는 함수 호출이 잘 되면 문제 없는 프로그램이다.
	= 데이터(상태)를 올바르게 관리하고,의도한 시점에 의도한 동작(함수)이 실행되도록 구조를 설계·구현하는 일이다.
	디버깅 -> 문제 전에 중단점을 놓고 값과 함수 호출의 관계를 보면 된다.
	= 문제가 발생하기 직전의 상태(변수 값)와 실행 흐름(호출 스택)을 관찰해‘왜 잘못된 상태에 도달했는지’를 역추적하는 과정이다.

	2진수 10 -> 2 (0,1) 0b(0
	10진수 10 그냥 10
	16진수 10 -> 16 (0~15) 0x(0~F)
	8진수 10 -> 
*/

/*
	- watch = 조사식 -> 변수 검색해서 주소 확인


*/