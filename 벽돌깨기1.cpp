#include <Windows.h>
#include <stdio.h>
#include <conio.h>

#define BALL_SIZE 20       // ���� ũ�� ����� ����
#define BAR_HOR_SIZE  50  // ���� ���� ũ�� ����� ���� 
#define BAR_VER_SIZE  10  // ���� ���� ũ�� ����� ����
#define BLOCK_VER_SIZE 20	//������ ���� ũ�� ���
#define BLOCK_HOR_SIZE 100	//������ ���� ũ�� ���
#define BAR_MOVE_STEP 15  // ���� ���� �̵� ũ�� ����� ����
#define MOVE_STEP 5       // ���� �̵� ���� ����� ����
#define _B 523.2511		//�ٿ� ���� �浹��
#define _S 987.7666		//���� ������ �浹��


int main(void)
{
	int ball_cnt[4] = { 0, };	//4���� ���� ������ ������ �浹 ī��Ʈ

	int bar_x = 250;   // ������ ������ x,y ��ǥ
	int bar_y = 200;

	int ball_x = 300;   // ���� ������ x,y ��ǥ 
	int ball_y = 200;

	int block_x[4] = { 50,160,270,380 };	//���� 4�� ������ x ���� ��ǥ

	int block_y = 80;

	int dx = MOVE_STEP;  // ���۽� x��ǥ�� �̵� ��
	int dy = MOVE_STEP;  // ���۽� y��ǥ�� �̵� ��

	char c; // Ű �Է� ���� ����
	int score = 0;	//���� ����. 100���� �þ

	HWND    hwnd = GetForegroundWindow(); // ���� ��������  �ڵ��� ���Ѵ�. 
	HDC hdc = GetWindowDC(hwnd);          // �������� ����̽� ���׽�Ʈ(Device context)�� �ڵ��� ���Ͽ� �����쿡 �����Ѵ�. 
	TCHAR str[50];  // ����� ���ڿ��� ������ �迭

	 // ����� ������� ����
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 255, 255)));
	SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
	Rectangle(hdc, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

	// �׸��� ���� �׵θ� ���� �Ķ���, ä��� ���� ������� ����
	SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 255)));
	SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));

	// �Ķ��� �׵θ��� ���� �簢���� �׸���. �������� ���
	Rectangle(hdc, 30, 40, 500, 400 + BALL_SIZE + MOVE_STEP);
	//system("pause");

	TextOut(hdc, 200, 450, L"BAR X control : j,k", 19); // ȭ�� �Ʒ��� ���ڿ� ���

	TextOut(hdc, 200, 250, L"PRESS ANY KEY!",15);	//���α׷� ������ �޽���

	c = _getch();	// Ű�� �Է¹޴� ����.Ű�� ������ ���α׷��� �����.

	SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(255, 255, 255)));	//������ �޽����� ����� ���� ��� �簢��
	SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
	Rectangle(hdc, 200, 200, 350, 300);
	
	while (1)
	{
	
		score = ball_cnt[0] + ball_cnt[1] + ball_cnt[2] + ball_cnt[3];	//score���� ǥ��

		wsprintf(str, TEXT("SCORE : %d"), score*100);   //������ �������� score�� 100���� �þ.
		TextOut(hdc,520, 120, str, lstrlen(str)); 

		// �׸��� ���� �׵θ� ���� �Ķ���, ä��� ���� ���������� ����
		SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 255)));
		SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));

		// ���� �׸���. 
		Ellipse(hdc, ball_x, ball_y, ball_x + BALL_SIZE, ball_y + BALL_SIZE);

		// �ٸ� �׸���. 
		Rectangle(hdc, bar_x, 400, bar_x + BAR_HOR_SIZE, 400 + BAR_VER_SIZE);

		Sleep(30); // �ð� ����

		// �׸��� ���� ���� ���, ä��� ���� ���
		SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(255, 255, 255)));
		SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));

		// ������(���)���� ���� �׷��� ���� �����. 
		Ellipse(hdc, ball_x, ball_y, ball_x + BALL_SIZE, ball_y + BALL_SIZE);

		// �ٸ� �����. 
		Rectangle(hdc, bar_x, 400, bar_x + BAR_HOR_SIZE, 400 + BAR_VER_SIZE);



		for (int i = 0; i < 4; i++) {
			if (ball_cnt[i] == 0) {
				SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 0)));	//������ �׸���.������ ����, �׵θ��� ������
				SelectObject(hdc, CreateSolidBrush(RGB(153, 51, 51)));
				Rectangle(hdc, block_x[i], block_y, block_x[i] + BLOCK_HOR_SIZE, block_y + BLOCK_VER_SIZE);
			}
			else {
				SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(255, 255, 255)));	//������ �����.
				SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
				Rectangle(hdc, block_x[i], block_y, block_x[i] + BLOCK_HOR_SIZE, block_y + BLOCK_VER_SIZE);

			}
		}
		// �̵��ϴ� ��ġ�� x,y ��ǥ ������ �����ϱ� ���� ��ǥ ���� dx,dy��ŭ �̵�

		if (_kbhit())  // Ű�� ���������� �˻�
		{
			c = _getch();   // Ű�� ������ ��� �Է� ���� ���� ��´�.     
			if (c == 'j' || c == 'J') bar_x = bar_x - BAR_MOVE_STEP; // �ҹ��� j�� �Էµ� ��� x��ǥ ���� dx��ŭ ����
			if (c == 'k' || c == 'K') bar_x = bar_x + BAR_MOVE_STEP; // �ҹ��� k�� �Էµ� ��� x��ǥ ���� dx��ŭ ����
		} //if

		// �浹 �˻�, ���� x��ǥ�� ���� x��ǥ�� ũ�� ���� �ȿ� ��ġ�ϴ°�
		// ���� y ��ǥ�� ���� ũ�⸦ ����� ���� y��ǥ�� ���� ���� �β� ��ǥ ���� �ȿ� �ִ°�
		if (bar_x <= ball_x && ball_x <= (bar_x + BAR_HOR_SIZE))
			if ((400 - BALL_SIZE) <= ball_y && ball_y <= (400 + BAR_VER_SIZE)) {
				Beep(_B, 20);
				dy = -MOVE_STEP;
			}
		for (int i = 0; i < 4; i++) {	//������ ���� �浹�˻�.
			if (ball_x >= block_x[i]-20 && ball_x <= (block_x[i] + BLOCK_HOR_SIZE+20))
				if (block_y <= ball_y && ball_y <= block_y + BLOCK_VER_SIZE)
				{
					Beep(_S, 20);
					dy = MOVE_STEP;
					ball_cnt[i] = 1;
				}
		}
		if (score == 4) {	//���α׷� ���� ����.�� score������ 400���� �Ǹ� ����ȴ�.
			TextOut(hdc, 200, 250, L"GAME OVER!", 15);
			getchar();
			break;
		}


		ball_x = ball_x + dx;
		ball_y = ball_y + dy;

		// ���� ����, ���� ��� �� �˻� �� ����
		if (bar_x >= (500 - (BAR_HOR_SIZE + MOVE_STEP))) bar_x = 500 - (BAR_HOR_SIZE + MOVE_STEP); // x ��ǥ ���� ���� ��踦 ���� ��� x ��ǥ �� ����
		if (bar_x <= 30 + MOVE_STEP) bar_x = 30 + MOVE_STEP;  // x ��ǥ ���� ���� ��踦 ���� ��� x ��ǥ �� ����

		// ���� ����, ���� ��� �� �˻� �� ����
		if (ball_x >= (500 - (BALL_SIZE + MOVE_STEP))) dx = -MOVE_STEP; // x ��ǥ ���� ���� ��踦 ���� ��� x ��ǥ �� ����
		if (ball_x <= 30 + MOVE_STEP)               dx = +MOVE_STEP;  // x ��ǥ ���� ���� ��踦 ���� ��� x ��ǥ �� ����

		if (ball_y >= 400)            // ���� �ٴڿ� ���� ���, ���� ���� ��ġ x,y ��ǥ�� �� �ʱ�ȭ
		{
			ball_y = 200;
			ball_x = 300;
		}

		if (ball_y <= (40 + MOVE_STEP)) dy = +MOVE_STEP; // y ��ǥ ���� ���� ��踦 ���� ��� y��ǥ �� ����
	} //while

	return 0;
}