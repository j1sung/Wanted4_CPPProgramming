#include <iostream> //<- F12 눌러봐 -> 헤더와 경로 보임
//탭에서 오픈 컨테이너 뭐시기 누르면 실제 그 헤더파일이 경로에 있다.
//C++는 기계어로 한번에 바꿔서 ~~
#include "Log.h" // void Log(const char* message);

// <조작키 설명>
// F12 -> 함수 정의로 이동
// Ctrl + - 
// Ctrl + 방향키 좌우.
// Home + End + (shift)
// Ctrl K+O -> 헤더랑 cpp 왔다갔다

// 이 함수가 어디있는지 찾는건 링커의 역할이다. -> 지금 include 안했는데도 찾아왔음
//void Log(const char* message);
//void Log(const char* message) {
//	std::cout << message << "n";
//}

int main()
{
	Log("Hello World");
	//std::cout << "Hello World" << '\n';
	return 0;
}