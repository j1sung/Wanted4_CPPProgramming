#include <iostream>
//#include <string.h>
#include <windows.h>

#define MYTEXT(value) L##value; // ##은 파라미터 두개 붙이기
#define MYTEST(value1, value2) value1##value2; // ##은 파라미터 두개 무식하게 붙이기

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <cstring>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

// 클래스 내부에서 문자열을 다루기
class Player 
{
	// C#은
	// 위에 멤버 변수
	// 그 아래 함수

	// public/protected/private
	// -> 접근 한정자/접근 제한자.
	// 접근 가능한 범위를 설정

	// C++은 변수 아래/함수 위에
public:
	// 공개 함수를 위에
	
	// 생성자 (Constructor)
	// // 객체를 생성할 때 호출되는 특별한 함수
	// 반환형이 없고, 클래스 이름과 동일
	Player(const char* inName) 
	{
		Test();
		// 문자열 복사
		// name = inName; -> 이건 안된다.

		// 1. 저장 공간 확보.
		// -> 확보할 공간의 크기를 알아야 함.
		// size_t: 부호 없는 정수형
		// typedef unsigned _int64 size_t; (x64)
		// typedef unsigned int size_t; (x86)
		size_t length = strlen(inName); // 무조건 null 문자가 나올때까지 순서대로 검사하기에 성능 안좋음
		// strlen()은 null(\0)이 나올때까지만 크기를 구하니 문자를 넣을땐 바이트 1 추가해야함
											
		name = new char[length + 1]; // null('\0')문자 할당을 위해 +1

		// 소멸자 없으면 메모리 릭 발생!!
		// C:\Workspace\CppBasic\CPlusPlus\String\Main.cpp(46) : {164} normal block at 0x00000279D97E4EA0, 8 bytes long.
		// Data: < JisungA > 4A 69 73 75 6E 67 41 00
		// Object dump complete.

		// 2. 문자열 복사. char의 개수는 바이트의 크기와 같으니 자동 처리됨
		// 기본 메커니즘은 memcpy() 와 같다
		// 문자열 복사 전용 안전 함수인 strcpy_s를 사용
		strcpy_s(name, length + 1, inName);
	}
	void Test()
	{
		int a;
	}

	 //소멸자 -> 메모리 해제를 위해
	 //객체가 해제될 때 실행
	~Player() // 소멸자가 없으면 delete하지 않아 메모리 릭 발생!
	{
		//if(name != nullptr)
		if (name) // 0이 아닌 나머지는 다 true이다. -1, 100, 1 다 true이다. 0만 false.
		{
			delete[] name;

		}
	}
	
private:
	// 문자열을 저장할 변수
	char* name = nullptr;

};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 문자열
	// 문자열은 불변성을 가짐 -> const를 붙여야함!!
	const char* testString = "Jisung"; // 원시 포인터를 가진 문자열
	std::cout << testString << "\n";

	// 문자 배열도 가능
	char buffer[7] = { 'J', 'i', 's', 'u', 'n', 'g', 0}; // \0 = 0 둘 다 상관없음 -> 아스키코드로 0이나 \0 null이 같음
	std::cout << buffer << "\n";

	// 객체 기반으로 문자열 사용
	// 명시적으로 타입 이름을 저장하지 않으면 읽어낼 수 없다.
	// 리플렉션으로 추가해야,,,
	Player player("JisungA");

	// wide-character.
	// wchar_t에서는 L을 문자열 앞에 붙여야 한다!
	//const wchar_t* wideString = L"Hello wide string";
	const wchar_t* wideString = MYTEXT("Hello wide string"); // 원래 TEXT를 씀

	// wide-character는 구분을 위해 출력에 wcout/입력에 wcin으로 써야함
	std::wcout << wideString << TEXT("\n"); 

	auto test = MYTEST(10, 20);

	std::cin.get();
	return 0;
}