#include <iostream>

// 매크로(Macro) -> 전처리에서 매크로도
// #define Square(x) ((x)*(x)) // 매크로는 다른 매크로 호출하고 중첩으로 막 쓰고 함

// 용량/속도 최적화 -> 용량을 포기하고 속도를 가져오는 최적화
// 인라인 함수 -> 속도 때문.
// 코드 이름 네이밍 규칙을 헤쳐서 __를 쓴다,,
#define FORCEINLINE __forceinline

FORCEINLINE int Square(int x)
{
	return x * x;
}

// 인라인 -> 코드를 함수 호출 대신 붙여넣는 것
inline int Square(int x) 
{
	return x * x;
}

int main() 
{
	int nubmer = Square(10);
}