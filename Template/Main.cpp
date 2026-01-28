#include <iostream>

// 두 변수의 값을 서로 교환하는 함수
//template<class T> -> 옛날엔 class로 먼저 만들고 최근에 바뀜, 둘 다 근데 됨! (보이면 예전 코드구나 하면 됨)
template<typename T>
void Swap(T& a, T& b) // 기본적으로 매커니즘이 틀린건지 실행해보기 전까지 모름(어쩔때는 컴파일도 될때 있음)
{
	T temp = a;
	a = b;
	b = temp;
}

//void Swap(float& a, float& b)
//{
//	float temp = a;
//	a = b;
//	b = temp;
//}


int main()
{
	int a = 10;
	int b = 20;
	Swap<int>(a, b);

	float floatA = 10.0f;
	float floatB = 20.0f;
	Swap<float>(floatA, floatB);

	std::cin.get();
	return 0;
}