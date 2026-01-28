#include <iostream>

void PrintString(char* string)
{
	std::cout << string << "\n";
}

class A
{
public:
	virtual void Test() {} // vtable -> dynamic_cast할때만
private:
};
class B: public A
{
};

int main()
{
	const char* name = "jistung"; // 문자 리터럴 불변
	PrintString(const_cast<char*>(name)); // const_cast()

	int number = 10;
	float floatNumber = static_cast<float>(number); // 기본 타입간 변환

	A* a = new A();
	B* b = static_cast<B*>(a); // 잘 알고 써야함. // static_cast는 상속(연관)만 되어있으면 통과되지만 개발자가 확정지어서 문제 없을때 다운캐스팅에서 써야한다.
	if (b)
	{
		std::cout << "b is not null\n";
	}
	B* b2 = reinterpret_cast<B*>(a);// 위험. // reinterpret_cast<>()는 더 강력하므로 보통 다운캐스팅은 static_cast를 쓰고, 정말 필요할때만 void*나 비상속일때나...
	if (b2)
	{
		std::cout << "b2 is not null\n";
	}
	B* b3 = dynamic_cast<B*>(a); // dynamic_cast는 런타임 검사해줌 -> 느릴 순 있음
	if (b3)
	{
		std::cout << "b3 is not null\n";
	}

	const type_info& aInfo = typeid(a);
	const type_info& bInfo = typeid(b);
	if (aInfo == bInfo)
	{
		std::cout << "Same\n";
	}
	//std::cout << "Type of a is " << info.name() << "\n";

	delete a;

	std::cin.get();
	return 0;
}