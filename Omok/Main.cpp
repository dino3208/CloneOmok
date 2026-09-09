// 출처 : https://github.com/Bonnate/Cpp_OmkGame


#include <iostream>
#include <Windows.h> // key값, gotoxy 등 여러가지 지원.


// constant expression -> constexpr : 컴파일 시점에 계산할 수 있는 상수 표현식.
// 메모리를 잡고 계산하는 것이 아니라 코드를 빌드하는 순간 MAX_ROW_OMOK_SIZE를 10으로 고정.
constexpr int MAX_ROW_OMOK_SIZE = 10; 
constexpr int MAX_COL_OMOK_SIZE = 10;

// Go to (x,y) -> gotoxy : 콘솔창 에서 글자가 찍힐 커서의 위치를 특정 좌표로 이동시키는 함수.
// 콘솔 화면에서 게임을 만들 때 특정 위치에 UI나 글자를 덮어씌워 화면 깜빡임을 줄이기 위해 사용한다.
void gotoxy(int x, int y)
{
	// pos struct는 x와 y의 값을 저장하는 것. (단순 순자)
	// gotoxy의 x,y 인자를 이용하여 pos객체를 임시로 생성하고
	// SetConsoleCursorPosition함수를 이용하여 커서를 이동시킨다. 
	COORD pos{ (SHORT)x,(SHORT)y }; // Windows API의 전용 데이터 타입들은 대부분 대문자로 작성된다.
	// Coordinate(좌표) -> COORD : 콘솔 화면에서 문자 하나의 위치(가로,세로)를 나타내기 위한 윈도우 기본 구조체.

	// 운영체제에서 화면의 텍스트 커서 위치를 원하는 좌표로 직접 옮겨주는 함수이다.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// GetStdHandle(STD_OUTPUT_HANDLE) : 콘솔 화면에 글자를 출력하는 고유 번호표(핸들)을 가져온다.
	// STD_OUTPUT_HANDLE : 표준 출력 (일반 콘솔 화면).
	// pos : 커서를 옮길 목표 좌표.
}

// textcolor
void textcolor(int foreground, int background)
{
	// color는 단순히 색상코드를 비트화시켜서 인자 한 개로 변환시켜준다.
	// *16을 사용하여 비트를 이동시킴 (^4)
	int color = foreground + background * 16;
	// 윈도우 콘솔의 텍스트 속성은 색상 하나를 1바이트(8비트) 크기 정수 안에서 글자색과 배경색으로 반씩 나누어 관리한다.
	// 비트 구조: [배경색 4비트][글자색 4비트]
	// 글자색 : 하위 4비트(0~15) | 배경색 : 상위 4비트(0~15).
	// 수학적으로 16을 곱하는 것은 비트를 왼쪽으로 4칸을 미는 것과 완전히 동일하다.

	// 윈도우 콘솔 화면에 출력될 텍스트 색상, 시각적 속성을 설정하는 함수.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 프로그램 실행 시 오목판 배열을 형식에 맞게 할당해준다.
void InitOmok(char*** arr); // Todo:

// 게임 시작시 오목판과 다른 요소를 그린다.
void PaintGame(char*** arr); // Todo:

// For Test:
bool Check33_1111(int row, int col, char* STONE, char*** arr);
bool Check33_112(int row, int col, char* STONE, char*** arr);
bool Check33_22(int row, int col, char* STONE, char*** arr);
void AnnounceRule(int row, int col, char*** arr);


// 돌을 찍은 기점에서 4방향*2 체크 [인자:행, 열, 돌모양, 오목판 배열].
bool CheckFinish(int row, int col, char* STONE, char*** arr); 
// 검사만 하고 끝내기 때문에 row,col 참조가 불필요하다.

// 게임을 실행한다.
void RunGame(char*** arr, char& row, char*& col, bool& isBlackTurn); 
// 게임 상태를 계속 업데이트해야 하기 때문에 row,col을 참조해야 한다.

// 할당된 메모리를 반환한다.
void ReleaseMemory(char*** arr);

int main()
{
	// 흑돌, 백돌이 순서대로 돌아가게 boolean형 선언, 흑돌이 게임을 먼저 시작한다.
	bool isBlackTurn = TRUE;

	// 현재 커서가 위치한 곳의 좌표를 나타낸다(행과 열).
	int row, col; // 원본은 char였는데 int로 고쳐보았다.

	// 게임 시작은 오목판 크기의 중심에서 시작한다.
	row = MAX_ROW_OMOK_SIZE / 2;
	col = MAX_COL_OMOK_SIZE / 2;

	// 2차원 포인터 char형을 동적할당으로 선언한다.

}

bool Check33_1111(int row, int co, const char* STONE, char*** arr)
{

}

bool Check33_112(int row, int col, const char* STONE, char*** arr)
{

}

bool Check33_22(int row, int col, char* STONE, char*** arr)
{

}

void AnnounceRule(int row, int col, char*** arr)
{

}

bool CheckFinish(int row, int col, const char* STONE, char*** arr)
{

}

void InitOmok(char*** arr)
{

}

void PaintGame(char*** arr)
{

}

void RunGame(char*** arr, char& row, char* col, bool& isBlackTurn)
{

}

void ReleaseMemory(char*** arr)
{
	// 2차원 배열 반환.
}