#include <iostream>

//#define LOG(x) std::cout << x << std::endl

//void Increment(int value) 
//{
//	++value;
//}

// Call-By-Reference
// 참조에 의한 호출
// 참조=주소 -> 주소 값 복사
void Increment(int& value) 
{
	++value;
}

void Swap(int* const numberA, int* const numberB) 
{
	int temp = *numberA;
	*numberA = *numberB;
	*numberB = temp;
}

int main()
{
	//int a = 5;
	//int& ref = a;    // L-Value Reference.
	//ref = 10;

	//int number = 10;
	//Increment(number);

	int number1 = 10;
	int number2 = 20;

	std::cout << "number1: " << number1 << ' ' << "number2: " << number2 << "\n";
	Swap(&number1, &number2);
	std::cout << "number1: " << number1 << ' ' << "number2: " << number2 << "\n";

	std::cin.get();
}