#include <iostream>

// 배열을 함수에 전달
void PrintArray(int* array, int length) // 포인터에선 배열 크기 추출 불가로 크기 같이 넘김
{

	for (int ix = 0; ix < length; ++ix) 
	{
		std::cout << array[ix] << "\n";
	}
}

int main()
{
	// 배열 선언
	//int array[10] = {}; // {} -> 0으로 초기화
	int array[10];
	memset(array, 0, sizeof(int) * 10); // 0으로 4*10=40바이트가 모두 0 초기화

	// index: 0부터 시작, 마지막은 크기 - 1
	array[0] = 1;
	array[3] = 10;
	array[9] = 100;

	// Out-of-Index(Range)
	// array[10] = 1000; // 컴파일러가 막아줌
	// array[-1] = 1000;

	// 배열의 이름은 주소(포인터)
	int* arrayPointer = array;
	//arrayPointer[1] = 20;
	*(arrayPointer + 1) = 20; 
	// 포인터에서 덧셈, 뺄셈하면 그 포인터의 타입 크기만큼 더하고 빼진다. -> int면 기본적으로 4바이트씩 
	
	// 배열 원소 전체 읽기(순회)
	// range-based loop
	// foreach ( )
	//for (const int& item : array) // const -> 읽기 전용, 여기서 &는 딱히 의미 없고 포인터면 몰라도
	//{
	//	std::cout << item << "\n";
	//}


	// 초기식, 조건식, 증감식
	// 증감식에서 전위/후위 증감 차이가 있나?
	// 앞은(전위) 메모리 저장할 필요 없는데 뒤는(후위) 저장해야함
	// 뒤에 붙이면 혹독한 환경에서는 메모리를 저장하는 과정이 필요해서 성능이 좀 떨어질 수 있다.
	/*for (int ix = 0; ix < 10; ++ix) 
	{                               
		std::cout << array[ix] << "\n";
	}*/

	PrintArray(array, 10);

	// 배열 동적 할당
	int* dynamicArray = new int[10];

	memset(dynamicArray, 1, sizeof(int) * 10);

	for(int ix = 0; ix <10; ++ix)
	{
		dynamicArray[ix] = ix + 1;
	}

	// 해제
	delete[] dynamicArray; // 배열 해제는 []를 붙여야 한다.

	std::cin.get();
	return 0;
}