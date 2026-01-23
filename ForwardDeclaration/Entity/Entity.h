#pragma once

// 전반 선언(Forward declaration).
//forward Vector; ?
//class Vector;
//using namespace Wanted;

class Vector;

class Entity
{
public:
	Entity() = default;
	Entity(int x, int y);
	// 복사 생성자 (Copy constructor).
	Entity(const Entity& other);

	~Entity();

private:
	Vector* position = nullptr; // 포인터로만 정의가 된다.
};


