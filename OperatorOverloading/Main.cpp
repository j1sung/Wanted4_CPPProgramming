#include <iostream>

class Point
{
public:
	Point(int x = 0, int y = 0)
		: x(x), y(y)
	{
	}

	//// 덧셈.
	//Point Add(const Point& other)
	//{
	//	return Point(x + other.x, y + other.y);
	//}

	// 비멤버 함수 -> friend 선언과 동시에 구현을 한 것!
	//friend Point Add(const Point& left, const Point& right);
	friend Point Add(const Point& left, const Point& right)
	{
		return Point(left.x + right.x, left.y + right.y);
	}

	// 연산자 오버로딩 구현
	// 단항 연산자 '++', '--'는 나 자신을 받는 것
	// 이항 연산자 '+' 가 붙는데 2개의 값이 필요하지만 하나는 매개변수로 받아오고, 하나는 나 자신!
	/*Point operator+(const Point& other)
	{
		return Point(x + other.x, y + other.y);
	}*/

	// 기본적으로 나를 받아서 2개를 받아오면 3항 연산으로 생각한다. -> 오류뜸
	// friend를 써서 이항 모두 밖에서 받아옴을 지정해줘야 한다.
	friend Point operator+(const Point& left, const Point& right)
	{
		return Point(left.x + right.x, left.y + right.y);
	}

	// 남용 금지! -> 연산 오버로딩 -> 혼란 발생!
	// 배열 연산도 오버로딩 가능
	// 배열 연산은 나를 스스로 받을 수 없음 -> 단항이어도 받아와야함
	// []도 연산자다
	int operator[](int index)
	{
		return array[index];
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& point)
	{
		return os << "(" << point.x << "," << point.y << ")\n";
	}

public: // 속성 접근을 많이 할거니 일단 public
	int x = 0;
	int y = 0;
	int array[];

};

//Point Add(const Point& left, const Point& right)
//{
//	return Point(left.x + right.x, left.y + right.y);
//}


// std::istream&
// << 연산자 오버로딩
//std::ostream& operator<<(std::ostream& os, const Point& point)
//{
//	return os << "(" << point.x << "," << point.y << ")\n";
//}

int main()
{
	Point p1(1, 1);
	Point p2(5, 5);

	//Point p3 = p1.Add(p2);
	//Point p3 = Add(p1, p2);
	//int number = GetValueWithIndex(3);
	//int number = p3[3];

	// 연산자 오버로딩
	//Point p3 = p1.operator+(p2); -> 원래는 이렇게 함수이지만 연산자 오버로딩은 생략 가능!
	Point p3 = p1 + p2;
	
	//std::cout << "(" << p3.x << "," << p3.y << ")" << "\n";
	std::cout << p3 << "\n";
	//std::cout.operator<<(10).operator<<(20);

	//Point p3(p1.x + p2.x, p1.y + p2.y);

	std::cin.get();
	return 0;
}