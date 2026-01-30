//#include <iostream>
//#include <functional>
//
////typedef int (*Adder)(int a, int b);
//using Adder = int (*)(int a, int b); // (int, int); 처럼 이름은 생략 가능 -> 명시적
////using Adder = std::is_function<int(int, int)>;
//
////using ClassAdder = int (Operator::*)(int a, int b);
//typedef int (Operator::*ClassAdder)(int a, int b); // 클래스 이름마다 다 하나씩 바꿔서 써줘야함. Operator2면 Operator에서 변경
//
//
//// 반환형이 int이고, 파라미터를 안받는 함수.
//int Function(int a, int b, Adder adder)
////int Function(int a, int b, std::function<int(int,int)> adder)
//{
//	return adder(a, b);
//}
//
//int Function(int a, int b, ClassAdder adder)
//{
//	return adder(a, b);
//}
//
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//class Operator
//{
//public:
//	int Add(int a, int b)
//	{
//		return a + b;
//	}
//};
//
//int main()
//{
//	// 함수 포인터 선언.
//	//int (*FunctionPointer)();
//	//FunctionPointer = Function;
//
//	// 함수 포인터를 통한 간접 호출.
//	std::cout << Function(10, 20, Add) << "\n";
//	
//	// 객체에서 함수 포인터
//	//Operator oper;
//	//oper.Add();
//	//ClassAdder adder = &Operator::Add;
//	//std::cout << Function(10, 20, (oper.*Adder)() << "\n");
//
//	std::cin.get();
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>

// Functor (함수 객체).
class Less
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};


// Functor (함수 객체).
// 클래스라 상태관리까지 할 수 있는 함수 포인터이다.
class Greater
{
public:
	bool operator()(int a, int b)
	{
		return a < b;
	}

private:
	// 상태도 추가로 관리 가능.
};


int main()
{
	// 정렬한 배열
	std::vector<int> array = { 1,2,3,4,5,6,7,8,9,10 };

	// 함수 객체 생성.
	/*Less less;
	Greater greater;*/

	// 정렬.
	//std::sort(array.begin(), array.end(), greater);
	auto greater = [](int a, int b)->bool
		{
			return a < b;
		};
	int number1 = 10;
	int number2 = 5;

	bool retsult = greater(number1, number2);

	std::sort(array.begin(), array.end(), greater);

	int sum = 0;
	//auto test = []() {};
	std::for_each(array.begin(), array.end(), [&sum](int item)/*->void*/ {sum += item; }); // 반환형 void는 생략 가능

	std::cout << "Sum = " << sum << "\n";

	//std::sort(array.begin(), array.end(), [](int a, int b)->bool { return a > b; });

	// 출력.
	for (const auto item : array)
	{
		std::cout << item << " ";
	}
	std::cout << "\n";
	std::cin.get();
}