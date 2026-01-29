#include <iostream>
#include "Player.h"
#include <vector>

int main()
{
	std::vector<int> array;
	array.push_back(10); // lvalue reference 였는데 RValue reference도 받게 바뀜
	array.emplace_back(10); // RValue reference를 받아 move 지원 -> 이게 RValue는 좋음

	// 객체를 파일에 쓰기 (파일 직렬화).
	//Player player(3, 200, 30.0f);
	Player player;
	//player.Serialize("PlayerData.txt");
	player.Deserialize("PlayerData.txt");


	// 문자열 입출력.
	int score = 100;
	float pi = 3.141592f;

	char formatString[256] = {};
	sprintf_s(formatString, 256, "score=%d pi=%f", score, pi);

	int intValue = 0;
	float floatValue = 0.0f;
	sscanf_s(formatString, "score=%d pi=%f", &intValue, &floatValue);

	FILE* file = nullptr;
	// &file은 파일을 다룰 수 있는 포인터일뿐, 파일 자체가 아니다.
	fopen_s(&file, "Test.txt", "rb"); // 파일 읽기 실패하면 주소값을 안줌

	// 파일 읽기 실패
	if (file == nullptr)
	{
		std::cout << "Failed to read file.\n";
		__debugbreak();
	}

	// 파일 크기 가늠.
	fseek(file, 0, SEEK_END);
	size_t fileSize = ftell(file);

	std::cout << "FileSize: " << fileSize << "\n";

	// !파일 크기 가늠한 뒤에 다시 처음부터 읽으려면 FP되돌려야 함.
	//fseek(file, 0, SEEK_SET); rewind()와 기능이 같다.
	rewind(file);

	// 블록 단위로 읽기.
	// 읽은 데이터를 저장하기 위한 공간.
	char buffer[1024] = {};
	size_t readSize = fread(buffer, sizeof(char), 1024, file);

	// 이런식으로도 된다.
	//char* buffer = new char[fileSize+1];
	//size_t readSize = fread(buffer, sizeof(char), fileSize, file);
	// delete[] buffer;

	std::cout << "readSize: " << readSize << "\n";
	std::cout << buffer;

	// 파일 쓰기.
	/*const char* message = "프로그램에서 작성한 문자열 값입니다.";
	fputs(message, file);*/

	// 파일 읽기.
	/*char data[256] = {};
	while (true)
	{
		if (fgets(data, 256, file) == nullptr)
		{
			break;
		}
		std::cout << data;
	}*/

	fclose(file);

	std::cin.get();
	return 0;
}