#include <Windows.h>
#include <stdio.h>
#include <conio.h>

#define BALL_SIZE 20       // 볼의 크기 상수를 정의
#define BAR_HOR_SIZE  50  // 바의 수평 크기 상수를 정의 
#define BAR_VER_SIZE  10  // 바의 수직 크기 상수를 정의
#define BLOCK_VER_SIZE 20	//벽돌의 수직 크기 상수
#define BLOCK_HOR_SIZE 100	//벽돌의 수평 크기 상수
#define BAR_MOVE_STEP 15  // 바의 수형 이동 크기 상수를 정의
#define MOVE_STEP 5       // 볼의 이동 간격 상수를 정의
#define _B 523.2511		//바와 볼의 충돌음
#define _S 987.7666		//볼과 벽돌의 충돌음


int main(void)
{
	int ball_cnt[4] = { 0, };	//4개의 벽돌 각각의 볼과의 충돌 카운트

	int bar_x = 250;   // 막대의 시점의 x,y 좌표
	int bar_y = 200;

	int ball_x = 300;   // 볼의 시점의 x,y 좌표 
	int ball_y = 200;

	int block_x[4] = { 50,160,270,380 };	//벽돌 4개 각각의 x 시작 좌표

	int block_y = 80;

	int dx = MOVE_STEP;  // 시작시 x좌표의 이동 값
	int dy = MOVE_STEP;  // 시작시 y좌표의 이동 값

	char c; // 키 입력 저장 변수
	int score = 0;	//벽돌 점수. 100점씩 늘어남

	HWND    hwnd = GetForegroundWindow(); // 현재 윈도우의  핸들을 구한다. 
	HDC hdc = GetWindowDC(hwnd);          // 윈도우의 디바이스 컨테스트(Device context)의 핸들을 구하여 윈도우에 접근한다. 
	TCHAR str[50];  // 출력할 문자열을 저장할 배열

	 // 배경을 흰색으로 설정
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 255, 255)));
	SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
	Rectangle(hdc, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

	// 그리는 펜의 테두리 색은 파란색, 채우는 색은 흰색으로 설정
	SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 255)));
	SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));

	// 파란색 테두리를 갖는 사각형을 그린다. 바탕색은 흰색
	Rectangle(hdc, 30, 40, 500, 400 + BALL_SIZE + MOVE_STEP);
	//system("pause");

	TextOut(hdc, 200, 450, L"BAR X control : j,k", 19); // 화면 아래에 문자열 출력

	TextOut(hdc, 200, 250, L"PRESS ANY KEY!",15);	//프로그램 시작전 메시지

	c = _getch();	// 키를 입력받는 문자.키를 누르면 프로그램이 실행됨.

	SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(255, 255, 255)));	//시작전 메시지를 지우기 위한 흰색 사각형
	SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
	Rectangle(hdc, 200, 200, 350, 300);
	
	while (1)
	{
	
		score = ball_cnt[0] + ball_cnt[1] + ball_cnt[2] + ball_cnt[3];	//score값을 표현

		wsprintf(str, TEXT("SCORE : %d"), score*100);   //벽돌을 깰때마다 score가 100점씩 늘어남.
		TextOut(hdc,520, 120, str, lstrlen(str)); 

		// 그리는 펜의 테두리 색은 파란색, 채우는 색은 빨강색으로 설정
		SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 255)));
		SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));

		// 원을 그린다. 
		Ellipse(hdc, ball_x, ball_y, ball_x + BALL_SIZE, ball_y + BALL_SIZE);

		// 바를 그린다. 
		Rectangle(hdc, bar_x, 400, bar_x + BAR_HOR_SIZE, 400 + BAR_VER_SIZE);

		Sleep(30); // 시간 지연

		// 그리는 펜의 색은 흰색, 채우는 색은 흰색
		SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(255, 255, 255)));
		SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));

		// 바탕색(흰색)으로 원을 그려서 원을 지운다. 
		Ellipse(hdc, ball_x, ball_y, ball_x + BALL_SIZE, ball_y + BALL_SIZE);

		// 바를 지운다. 
		Rectangle(hdc, bar_x, 400, bar_x + BAR_HOR_SIZE, 400 + BAR_VER_SIZE);



		for (int i = 0; i < 4; i++) {
			if (ball_cnt[i] == 0) {
				SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 0)));	//벽돌을 그린다.색깔은 갈색, 테두리는 검은색
				SelectObject(hdc, CreateSolidBrush(RGB(153, 51, 51)));
				Rectangle(hdc, block_x[i], block_y, block_x[i] + BLOCK_HOR_SIZE, block_y + BLOCK_VER_SIZE);
			}
			else {
				SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(255, 255, 255)));	//벽돌을 지운다.
				SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
				Rectangle(hdc, block_x[i], block_y, block_x[i] + BLOCK_HOR_SIZE, block_y + BLOCK_VER_SIZE);

			}
		}
		// 이동하는 위치의 x,y 좌표 값으로 변경하기 위해 좌표 값을 dx,dy만큼 이동

		if (_kbhit())  // 키가 눌러졌는지 검사
		{
			c = _getch();   // 키가 눌러진 경우 입력 문자 값을 얻는다.     
			if (c == 'j' || c == 'J') bar_x = bar_x - BAR_MOVE_STEP; // 소문자 j가 입력된 경우 x좌표 값은 dx만큼 감소
			if (c == 'k' || c == 'K') bar_x = bar_x + BAR_MOVE_STEP; // 소문자 k가 입력된 경우 x좌표 값은 dx만큼 증가
		} //if

		// 충돌 검사, 볼의 x좌표가 바의 x좌표와 크기 범위 안에 위치하는가
		// 볼의 y 좌표가 볼의 크기를 고려한 바의 y좌표와 바의 수직 두께 좌표 범위 안에 있는가
		if (bar_x <= ball_x && ball_x <= (bar_x + BAR_HOR_SIZE))
			if ((400 - BALL_SIZE) <= ball_y && ball_y <= (400 + BAR_VER_SIZE)) {
				Beep(_B, 20);
				dy = -MOVE_STEP;
			}
		for (int i = 0; i < 4; i++) {	//벽돌과 볼의 충돌검사.
			if (ball_x >= block_x[i]-20 && ball_x <= (block_x[i] + BLOCK_HOR_SIZE+20))
				if (block_y <= ball_y && ball_y <= block_y + BLOCK_VER_SIZE)
				{
					Beep(_S, 20);
					dy = MOVE_STEP;
					ball_cnt[i] = 1;
				}
		}
		if (score == 4) {	//프로그램 종료 조건.총 score점수가 400점이 되면 종료된다.
			TextOut(hdc, 200, 250, L"GAME OVER!", 15);
			getchar();
			break;
		}


		ball_x = ball_x + dx;
		ball_y = ball_y + dy;

		// 바의 좌측, 우측 경계 값 검사 및 설정
		if (bar_x >= (500 - (BAR_HOR_SIZE + MOVE_STEP))) bar_x = 500 - (BAR_HOR_SIZE + MOVE_STEP); // x 좌표 값의 우측 경계를 만난 경우 x 좌표 값 제한
		if (bar_x <= 30 + MOVE_STEP) bar_x = 30 + MOVE_STEP;  // x 좌표 값의 좌측 경계를 만난 경우 x 좌표 값 제한

		// 볼의 좌측, 우측 경계 값 검사 및 설정
		if (ball_x >= (500 - (BALL_SIZE + MOVE_STEP))) dx = -MOVE_STEP; // x 좌표 값의 우측 경계를 만난 경우 x 좌표 값 제한
		if (ball_x <= 30 + MOVE_STEP)               dx = +MOVE_STEP;  // x 좌표 값의 좌측 경계를 만난 경우 x 좌표 값 제한

		if (ball_y >= 400)            // 볼이 바닥에 닿은 경우, 볼의 시작 위치 x,y 좌표를 를 초기화
		{
			ball_y = 200;
			ball_x = 300;
		}

		if (ball_y <= (40 + MOVE_STEP)) dy = +MOVE_STEP; // y 좌표 값이 위측 경계를 만난 경우 y좌표 값 제한
	} //while

	return 0;
}