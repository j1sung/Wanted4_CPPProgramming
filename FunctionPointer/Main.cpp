#include <iostream>
#include <functional>

//typedef int (*Adder)(int a, int b);
using Adder = int (*)(int a, int b); // (int, int); 처럼 이름은 생략 가능 -> 명시적
//using Adder = std::is_function<int(int, int)>;

//using ClassAdder = int (Operator::*)(int a, int b);
typedef int (Operator::*ClassAdder)(int a, int b); // 클래스 이름마다 다 하나씩 바꿔서 써줘야함. Operator2면 Operator에서 변경


// 반환형이 int이고, 파라미터를 안받는 함수.
int Function(int a, int b, Adder adder)
//int Function(int a, int b, std::function<int(int,int)> adder)
{
	return adder(a, b);
}

int Function(int a, int b, ClassAdder adder)
{
	return adder(a, b);
}


int Add(int a, int b)
{
	return a + b;
}

class Operator
{
public:
	int Add(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	// 함수 포인터 선언.
	//int (*FunctionPointer)();
	//FunctionPointer = Function;

	// 함수 포인터를 통한 간접 호출.
	std::cout << Function(10, 20, Add) << "\n";
	
	// 객체에서 함수 포인터
	//Operator oper;
	//oper.Add();
	//ClassAdder adder = &Operator::Add;
	//std::cout << Function(10, 20, (oper.*Adder)() << "\n");

	std::cin.get();
	return 0;
}