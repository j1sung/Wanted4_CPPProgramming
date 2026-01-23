#pragma once  // -> 중복 include 방지 구문 (컴파일러 구문).
              // 순환참조까지는 막아주지 못한다.

// 클래스
class Player
{
	// 접근 한정자/접근 제한자.
	// 클래스 내부의 속성을 어디까지 노출시킬지 결정.
	// public/protected/private.
	// 공개/상속(물려줌) 계층까지/나만.
public:

	// Setter(세터)
	// 공개 함수(메소드) -> 메시지.
	inline void SetX(const int inX)
	{
		if (inX < 0)
		{
			return;
		}

		x = inX;
	}

	inline void SetY(const int inY)
	{
		y = inY;
	}

	inline void SetSpeed(const int inSpeed)
	{
		speed = inSpeed;
	}

	// Getter(게터).
	inline int GetX() const
	{
		return x;
	}

	//// 클래스 조작 함수
	//void Move(int x, int y)
	//{
	//	SetX(x);
	//	SetY(y);
	//}

public:

	// 생성자.
	// 파라미터를 받지 않는 생성자 = 기본 생성자.
	//Player() {}
	//Player() = default;
	//~Player() = default;
	Player();
	Player(const char* inName);
	~Player();


	// 클래스 조작 함수.
	// 선언하기.
	void Move(int inX, int inY);
	//{
	//	x = inX;
	//	y = inY;
	//}

private:
	int x = 0;
	int y = 0;
	int speed = 0;

	// 이름 값(문자열).
	//char name[10] = {}; // 이거도 가능
	char* name = nullptr; // 힙으로 해보기
};