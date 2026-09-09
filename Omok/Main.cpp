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