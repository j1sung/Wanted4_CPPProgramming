#include <iostream>

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
		// 문자열 복사
		// name = inName; -> 이건 안된다.

		// 1. 저장 공간 확보.
		// -> 확보할 공간의 크기를 알아야 함.
		size_t length = strlen(inName) + 1; // 무조건 null 문자가 나올때까지 순서대로 검사하기에 성능 안좋음
											// null문자 할당을 위해 1 더함
		name = new char[length];

		// 2. 문자열 복사. char의 개수는 바이트의 크기와 같으니 자동 처리됨

		// 기본 메커니즘은 memcpy() 와 같다
		strcpy_s(name, length, inName);
	}

	// 소멸자 -> 메모리 해제를 위해
	// 객체가 해제될 때 실행
	~Player() 
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
	// 문자열
	// 문자열은 불변성을 가짐 -> const를 붙여야함!!
	const char* testString = "Jisung"; // 원시 포인터를 가진 문자열
	std::cout << testString << "\n";

	// 문자 배열도 가능
	char buffer[7] = { 'J', 'i', 's', 'u', 'n', 'g', 0}; // \0 = 0 둘 다 상관없음 -> 아스키코드로 0이나 \0 null이 같음
	std::cout << buffer << "\n";

	// 객체 기반으로 문자열 사용
	Player player("JisungA");

	std::cin.get();
	return 0;
}