#include<stdio.h>  
#include<math.h>   //���а����� �������� ���         
#include<Windows.h>  //�׷����� ����ϱ����� ���
#include<thread>  //�����Լ��� ����ϱ� ���� thread �������
using namespace std;  //thread�� C++�� ���ǵǾ��ִ�  Ŭ����(std)�̹Ƿ� �����ؾ� �Ѵ�.
#define PI 3.141592654  //PI��� ����
#define CT 525   //�¾���� �˵��� �߽���.

HWND    hwnd = GetForegroundWindow(); // ���� ��������  �ڵ��� ���Ѵ�. 
HDC hdc = GetWindowDC(hwnd);

void func1()  //������ �׷��ȸ� ǥ���ϴ� �Լ�
{
	float a = 0.0;  //���� a�� �ʱ�ȭ. ���⼭ a�� ������ ����
	while (1) {  //while�Լ� ���ǹ��� true ���� �־ ���ѹݺ� ��Ų��
		a = 2 * PI;   //while�Լ� �ȿ��� ���� a�� �ٽ� �ʱ�ȭ

		while (a > 0) {  //���� a�� ���� ���� ��� �ݺ�. a�� ���� 0���� �������� 
						 //Ż���Ͽ� ���� while������ �ٽ� �ʱ�ȭ�� �ް� ���ѹݺ��ȴ�.

			int Mercu = 20;  //������ ������. �༺�� ���� ũ�⿡ ������� �ʰ� ������ ũ�⸦ �����Ͽ���

			float x = CT - cos(a) * 100;  //���� ��ǥ�� x��. �߽� CT�� �������� �ڻ��ο� ���� a�� ����,���� �˵��� ������ 100�� ���Ѵ�.
			float y = CT - sin(a) * 100;  //���� ��ǥ�� y��. �߽� CT�� �������� ���ο� ���� a�� ����,���� �˵��� ������ 100�� ���Ѵ�.

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));  //���� �µθ� ����
			SelectObject(hdc, CreateSolidBrush(RGB(75, 105, 120)));  //������ ����. ûȸ������ ����.
			Ellipse(hdc, x, y, x + Mercu, y + Mercu);  //������ �ʱ���ġ. �̶� a�� 2*PI�̹Ƿ�, �ʱ���ġ�� (425,525)�̴�.

			a -= 0.01;  //���� a�� �ʱⰪ 2*PI���� -0.01�� ����. �پ�� a�� ���� ���� ������ ��ġ�� ���Ͽ� �¾� ������ �����Ѵ�.
						//�̶� ������ �ݽð� �������� �����Ѵ�.

			Sleep(24.1);  // ������ ���� �ֱ�. ������ �����ֱ�ӵ�(365��)�� 100�̶� ������ ������ �����ӵ��� 24.1 �̴�

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));  //������ �̵���θ� ���������� �����.
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
			Ellipse(hdc, x, y, x + Mercu, y + Mercu);

		}

	}
}
void func2()  //�ݼ��� �׷��ȸ� ǥ���ϴ� �Լ�
{
	float b = 0.0;  //���� b�� �ʱ�ȭ. b�� ����
	while (1) {
		b = 2 * PI;  //���� b�� �ʱⰪ.
		while (b > 0) {  //while���� ����.
			int Vinus = 25;  //�ݼ��� ������.
			float x = CT + cos(b) * 145;  //�ݼ��� x���� y��. ������ �ڻ���,���� ������ �ݴ���� �ʱ� ��ġ�� �ݴ�� �Ͽ���.
			float y = CT + sin(b) * 145;  //�ݼ� �˵��� �������� �߽�(CT,CT)�� �������� 145�� �����ߴ�.

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0))); //�ݼ��� �µθ��� ������, ���� ���� ���������� �Ͽ���.
			SelectObject(hdc, CreateSolidBrush(RGB(204, 0, 0)));
			Ellipse(hdc, x, y, x + Vinus, y + Vinus);  //�ݼ��� ��ġ

			b -= 0.01;  //�ݼ��� �ݽð�������� �����ϰ� �����ߴ�

			Sleep(67.37);  //�ݼ��� �����ӵ��� ������ 100�̶� �Ͽ����� 67.37�̴�.

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));  //�ݼ��� �̵���θ� ���������� ����
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
			Ellipse(hdc, x, y, x + Vinus, y + Vinus);
		}
	}
}
void func3()  //������ �׷��ȸ� ǥ���ϴ� �Լ�
{
	float c = 0.0;  //�����ʱ�ȭ

	while (1) {  //���ѹݺ�
		c = 2 * PI;  //���� �ʱⰪ

		while (c > 0) {

			int Earth = 26;  //������ ������.�ݼ��� ����ϰ� ������
			float x = CT + cos(c) * 195;  //������ xy��. ���� �˵��� �������� �߽�(CT,CT)�� �������� 195�� �����ߴ�.
			float y = CT + sin(c) * 195;

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 200, 0))); //������ �µθ��� �ʷϻ�, ���λ��� �Ķ������� �����ߴ�
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 255)));
			Ellipse(hdc, x, y, x + Earth, y + Earth);

			c -= 0.01;

			Sleep(100);  //������ ���� �ӵ�

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
			Ellipse(hdc, x, y, x + Earth, y + Earth);

		}

	}
}
void func4()  //ȭ���� �׷��ȸ� ǥ���ϴ� �Լ�
{
	float d = 0.0;

	while (1) {
		d = 2 * PI;

		while (d > 0) {

			int  Mars = 23;  //ȭ���� ������. �������� ���� �۰� ����
			float x = CT - cos(d) * 255;  //ȭ���˵��� �������� 255�� �����Ͽ���.
			float y = CT - sin(d) * 255;

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 140, 0))); //ȭ���� ������ ��Ȳ������ �����ߴ�.
			SelectObject(hdc, CreateSolidBrush(RGB(255, 165, 0)));
			Ellipse(hdc, x, y, x + Mars, y + Mars);

			d -= 0.01;

			Sleep(188.21);  //ȭ���� �����ӵ��� ����(100)�� �������� 188.21�̴�.

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
			Ellipse(hdc, x, y, x + Mars, y + Mars);

		}

	}
}
void func5()  //���� �׷����� ǥ���ϴ� �Լ�
{
	float e = 0.0;

	while (1) {
		e = 2 * PI;

		while (e > 0) {

			int Jupiter = 50;  //���� �������� 50���� ����.
			float x = CT - cos(e) * 325;  //���� �˵� �������� 325�� �����ߴ�.
			float y = CT - sin(e) * 325;

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));  //���� ������ �������� �����ߴ�.
			SelectObject(hdc, CreateSolidBrush(RGB(160, 80, 45)));
			Ellipse(hdc, x, y, x + Jupiter, y + Jupiter);

			e -= 0.01;

			Sleep(1186);  //���� �����ӵ��� ����(100)�� �������� 1186�̴�.

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
			Ellipse(hdc, x, y, x + Jupiter, y + Jupiter);




		}

	}
}
void func6()  //�伺�� �׷����� ǥ���ϴ� �Լ�
{
	float f = 0.0;

	while (1) {
		f = 2 * PI;

		while (f > 0) {

			int Saturn = 35;
			float x = CT + cos(f) * 370;  //�伺�� �ʱ� ��ġ�� �񼺰� �ݴ�� �����Ͽ� �ð������� �����ϰ� �ߴ�
			float y = CT + sin(f) * 370;

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(100, 100, 0)));  //�伺�� ������ �ݻ����� �����ߴ�.
			SelectObject(hdc, CreateSolidBrush(RGB(255, 215, 0)));
			Ellipse(hdc, x, y, x + Saturn, y + Saturn);

			f -= 0.01;

			Sleep(2950);  //�伺�� �����ӵ��� 2950�̴�.

			SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
			SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
			Ellipse(hdc, x, y, x + Saturn, y + Saturn);

		}

	}
}
void main() {  //�׷����� ������ �����Լ�.

	int x = 25, y = 25;  //�༺���� ���� �̵������� �� ������ �����ϱ� ���� 4���� ������ �ʱⰪ�� �����ߴ�.
	int w = 1025, h = 1025;

	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));  //�ð��� �������� ���ؼ� ����� ���������� �����ؿ���.
	SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
	Rectangle(hdc, 0, 0, 2 * CT, 2 * CT);

	for (int i = 1; i <= 8; i++) {  // 8�� �༺(������ȭ����)�� ���� �̵������� ǥ���ϱ� ���� �� �� 8���� �����.
		SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 255, 255)));
		SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 0)));
		Ellipse(hdc, x += 50, y += 50, w -= 50, h -= 50);
	}

	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 0, 0)));  //�¾��� �µθ��� ������,���δ� ��Ȳ������ �����ߴ�.
	SelectObject(hdc, CreateSolidBrush(RGB(210, 95, 0)));
	Ellipse(hdc, CT - 50, CT - 50, CT + 50, CT + 50);  //�¾��� ��ġ�� �߽�, �������� 100���� �����ߴ�.


	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));  //õ�ռ�,�ؿռ�,��ռ��� �̵��� �������� �ʰ� ������ �ߴ�.���� ���� �Ķ���,����, ȸ������ �����ߴ�.
	SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 255)));  // õ�ռ� �ؿռ� ��ռ��� �˵� �������� ���� 400,450,500���� �����ߴ�.
	Ellipse(hdc, CT - 400, CT, CT - 400 + 30, CT + 30);

	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	SelectObject(hdc, CreateSolidBrush(RGB(0, 0, 140)));
	Ellipse(hdc, CT - 450, CT, CT - 450 + 30, CT + 30);

	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 200, 0)));
	SelectObject(hdc, CreateSolidBrush(RGB(210, 180, 140)));
	Ellipse(hdc, CT - 500, CT, CT - 500 + 15, CT + 15);

	thread t1(func1);  //������ thread��ü. func1�� ������ �Լ��� ���� �����Ѵ�.
	thread t2(func2);
	thread t3(func3);
	thread t4(func4);
	thread t5(func5);
	thread t6(func6);

	t1.join();  // func1�Լ��� ����Ǹ� ����. ���� �ݺ� ���״�.
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
}