#include<stdio.h>  
#include<math.h>   //수학공식을 쓰기위한 헤더         
#include<Windows.h>  //그래픽을 출력하기위한 헤더
#include<thread>  //병렬함수를 사용하기 위한 thread 헤더파일
using namespace std;  //thread는 C++에 정의되어있는  클래스(std)이므로 선언해야 한다.
#define PI 3.141592654  //PI상수 정의
#define CT 525   //태양계의 궤도의 중심점.

HWND    hwnd = GetForegroundWindow(); // 현재 윈도우의  핸들을 구한다. 
HDC hdc = GetWindowDC(hwnd);

void func1()  //수성의 그래픽를 표현하는 함수
{
	float a = 0.0;  //변수 a의 초기화. 여기서 a는 라디안의 역할
	while (1) {  //while함수 조건문에 true 값을 넣어서 무한반복 시킨다
		a = 2 * PI;   //while함수 안에서 변수 a값 다시 초기화

		while (a > 0) {  //변수 a의 값이 양일 경우 반복. a의 값이 0보다 작이지면 
						 //탈출하여 위의 while문에서 다시 초기화를 받고 무한반복된다.

			int Mercu = 20;  //수성의 반지름. 행성의 실제 크기에 비례하지 않고 적절한 크기를 대입하였다

			float x = CT - cos(a) * 100;  //수성 좌표의 x값. 중심 CT를 기준으로 코사인에 변수 a를 대입,수성 궤도의 반지름 100을 곱한다.
			float y = CT - sin(a) * 100;  //수성 좌표의 y값. 중심 CT를 기준으로 사인에 변수 a를 대입,수성 궤도의 반지름 100을 곱한다.

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));  //수성 태두리 색깔
			SelectObject(hdc, CreateSolidBrush(RGB(75, 105, 120)));  //수성의 색깔. 청회색으로 설정.
			Ellipse(hdc, x, y, x + Mercu, y + Mercu);  //수성의 초기위치. 이때 a는 2*PI이므로, 초기위치는 (425,525)이다.

			a -= 0.01;  //변수 a의 초기값 2*PI에서 -0.01씩 감소. 줄어든 a의 값에 따라 수성의 위치가 변하여 태양 주위를 공전한다.
						//이때 수성은 반시계 방향으로 공전한다.

			Sleep(24.1);  // 수성의 공전 주기. 지구의 공전주기속도(365일)를 100이라 했을때 수성의 공전속도는 24.1 이다

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));  //수성의 이동경로를 검은색으로 지운다.
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
			Ellipse(hdc, x, y, x + Mercu, y + Mercu);

		}

	}
}
void func2()  //금성의 그래픽를 표현하는 함수
{
	float b = 0.0;  //변수 b의 초기화. b는 라디안
	while (1) {
		b = 2 * PI;  //변수 b의 초기값.
		while (b > 0) {  //while문의 조건.
			int Vinus = 25;  //금성의 반지름.
			float x = CT + cos(b) * 145;  //금성의 x값과 y값. 수성과 코사인,사인 연산을 반대로해 초기 위치를 반대로 하였음.
			float y = CT + sin(b) * 145;  //금성 궤도의 반지름은 중심(CT,CT)을 기준으로 145로 설정했다.

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0))); //금성의 태두리는 검은색, 내부 색은 붉은색으로 하였음.
			SelectObject(hdc, CreateSolidBrush(RGB(204, 0, 0)));
			Ellipse(hdc, x, y, x + Vinus, y + Vinus);  //금성의 위치

			b -= 0.01;  //금성도 반시계방향으로 공전하게 설정했다

			Sleep(67.37);  //금성의 공전속도는 지구를 100이라 하였을때 67.37이다.

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));  //금성의 이동경로를 검은색으로 지움
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
			Ellipse(hdc, x, y, x + Vinus, y + Vinus);
		}
	}
}
void func3()  //지구의 그래픽를 표현하는 함수
{
	float c = 0.0;  //라디아초기화

	while (1) {  //무한반복
		c = 2 * PI;  //라디안 초기값

		while (c > 0) {

			int Earth = 26;  //지구의 반지름.금성과 비슷하게 설정함
			float x = CT + cos(c) * 195;  //지구의 xy값. 지구 궤도의 반지름은 중심(CT,CT)을 기준으로 195로 설정했다.
			float y = CT + sin(c) * 195;

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 200, 0))); //지구의 태두리는 초록색, 내부색은 파란색으로 설정했다
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 255)));
			Ellipse(hdc, x, y, x + Earth, y + Earth);

			c -= 0.01;

			Sleep(100);  //지구의 공전 속도

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
			Ellipse(hdc, x, y, x + Earth, y + Earth);

		}

	}
}
void func4()  //화성의 그래픽를 표현하는 함수
{
	float d = 0.0;

	while (1) {
		d = 2 * PI;

		while (d > 0) {

			int  Mars = 23;  //화성의 반지름. 지구보다 조금 작게 설정
			float x = CT - cos(d) * 255;  //화성궤도의 반지름은 255로 설정하였다.
			float y = CT - sin(d) * 255;

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 140, 0))); //화성의 색깔은 주황색으로 설정했다.
			SelectObject(hdc, CreateSolidBrush(RGB(255, 165, 0)));
			Ellipse(hdc, x, y, x + Mars, y + Mars);

			d -= 0.01;

			Sleep(188.21);  //화성의 공전속도는 지구(100)을 기준으로 188.21이다.

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
			Ellipse(hdc, x, y, x + Mars, y + Mars);

		}

	}
}
void func5()  //목성의 그래프를 표현하는 함수
{
	float e = 0.0;

	while (1) {
		e = 2 * PI;

		while (e > 0) {

			int Jupiter = 50;  //목성의 반지름은 50으로 설정.
			float x = CT - cos(e) * 325;  //목성의 궤도 반지름은 325로 설정했다.
			float y = CT - sin(e) * 325;

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));  //목성의 색깔은 갈색으로 설정했다.
			SelectObject(hdc, CreateSolidBrush(RGB(160, 80, 45)));
			Ellipse(hdc, x, y, x + Jupiter, y + Jupiter);

			e -= 0.01;

			Sleep(1186);  //목성의 공전속도는 지구(100)을 기준으로 1186이다.

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
			Ellipse(hdc, x, y, x + Jupiter, y + Jupiter);




		}

	}
}
void func6()  //토성의 그래프를 표현하는 함수
{
	float f = 0.0;

	while (1) {
		f = 2 * PI;

		while (f > 0) {

			int Saturn = 35;
			float x = CT + cos(f) * 370;  //토성의 초기 위치를 목성과 반대로 설정하여 시각적으로 용이하게 했다
			float y = CT + sin(f) * 370;

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(100, 100, 0)));  //토성의 색깔은 금색으로 설정했다.
			SelectObject(hdc, CreateSolidBrush(RGB(255, 215, 0)));
			Ellipse(hdc, x, y, x + Saturn, y + Saturn);

			f -= 0.01;

			Sleep(2950);  //토성의 공전속도는 2950이다.

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
			Ellipse(hdc, x, y, x + Saturn, y + Saturn);

		}

	}
}
void main() {  //그래픽을 구현할 메인함수.

	int x = 25, y = 25;  //행성들의 공전 이동방향을 흰 선으로 설정하기 위해 4개의 변수의 초기값을 지정했다.
	int w = 1025, h = 1025;

	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));  //시각적 용이함을 위해서 배경을 검은색으로 설정해였다.
	SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
	Rectangle(hdc, 0, 0, 2 * CT, 2 * CT);

	for (int i = 1; i <= 8; i++) {  // 8개 행성(수금지화목토)의 공전 이동방향을 표현하기 위해 흰선 원 8개를 만든다.
		SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 255, 255)));
		SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
		Ellipse(hdc, x += 50, y += 50, w -= 50, h -= 50);
	}

	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 0, 0)));  //태양의 태두리는 빨간색,내부는 주황색으로 설정했다.
	SelectObject(hdc, CreateSolidBrush(RGB(210, 95, 0)));
	Ellipse(hdc, CT - 50, CT - 50, CT + 50, CT + 50);  //태양의 쥐치는 중심, 반지름은 100으로 설정했다.


	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));  //천왕성,해왕성,명왕성은 이동을 묘사하지 않고 구현만 했다.색은 각각 파란색,남색, 회색으로 설정했다.
	SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 255)));  // 천왕성 해왕성 명왕성의 궤도 반지름은 각각 400,450,500으로 설정했다.
	Ellipse(hdc, CT - 400, CT, CT - 400 + 30, CT + 30);

	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 140)));
	Ellipse(hdc, CT - 450, CT, CT - 450 + 30, CT + 30);

	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 200, 0)));
	SelectObject(hdc, CreateSolidBrush(RGB(210, 180, 140)));
	Ellipse(hdc, CT - 500, CT, CT - 500 + 15, CT + 15);

	thread t1(func1);  //수성의 thread객체. func1을 나머지 함수와 병렬 진행한다.
	thread t2(func2);
	thread t3(func3);
	thread t4(func4);
	thread t5(func5);
	thread t6(func6);

	t1.join();  // func1함수가 종료되면 리턴. 무한 반복 시켰다.
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
}