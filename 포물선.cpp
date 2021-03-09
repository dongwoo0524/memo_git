#include <Windows.h>
#include <stdio.h>
#include <math.h>

#define BALL_SIZE 12      // ���� ũ�� ����� ����
#define MOVE_STEP 3     // ���� �̵� ���� ����� ����
#define X_END     800     // x ��ǥ�� ���� ��� �� ����
#define Y_END     400     // y ��ǥ�� �ϴ� ��� �� ����
#define PI 3.141592654   // PI ��� ��
#define G         9.8        // �߷� ���ӵ� ��� ��

int main(void)
{
    int x;       // ���� x,y ��ǥ
    int y;

    int v0 = 80;      // �ʱ� �߻� �ӵ� ��
    int degree;     // �������� �߻� ����

    double t = 0.0;   // �ð� ��
    double dt = 0.1;  // �ð� ���� ��
    TCHAR str[50];  // ����� ���ڿ��� ������ �迭

    HWND    hwnd = GetForegroundWindow(); // ���� ��������  �ڵ��� ���Ѵ�. 
    HDC hdc = GetWindowDC(hwnd);          // �������� ����̽� ���׽�Ʈ(Device context)�� �ڵ��� ���Ͽ� �����쿡 �����Ѵ�. 

     // ����� ������� ����
    SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 255, 255)));
    SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));
    Rectangle(hdc, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

    // �׸��� ���� �׵θ� ���� �Ķ���, ä��� ���� ������� ����
    SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 255)));
    SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));

    // �Ķ��� �׵θ��� ���� �簢���� �׸���. �������� ���
    Rectangle(hdc, 30, 40, 800 + BALL_SIZE + MOVE_STEP, 400 + BALL_SIZE + MOVE_STEP);

    // �߻�븦 �׸���. 
    Rectangle(hdc, 50, 380, 55, 410);

    TextOut(hdc, 350, 450, L"������ � �ùķ��̼�", 6); // ȭ�� �Ʒ��� ���ڿ� ���

     // �ʱ� �ӵ� ���� ������ â �ϴܿ� ����Ѵ�. 
    wsprintf(str, TEXT("�ʱ� �ӵ� ��=%d"), v0); // �ӵ� ���� ����ϱ� ���� ���ڿ��� ��ȯ
    TextOut(hdc, 50, 440, str, lstrlen(str));  // �ӵ� ���� ȭ�鿡 ���

    for (degree = 0; degree <= 90; degree += 5)  //�������� ���� ���� 5���� ������Ű�� ���
    {
        t = 0; // ���� �ð� ���� 0���� ����

        while (1)
        {
            // �׸��� ���� �׵θ� ���� �Ķ���, ä��� ���� ���������� ����
            SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(0, 0, 255)));
            SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));

            // ������ ��� X,Y ��ǥ ���
            x = 50 + (int)(v0 * cos((degree)*PI / 180) * t);                // x��ǥ�� ���
            y = 400 - (int)(v0 * sin((degree)*PI / 180) * t - 1.0 / 2.0 * G * t * t); // y��ǥ�� ���

             // ���� �׸���. 
            Ellipse(hdc, x, y, x + BALL_SIZE, y + BALL_SIZE);

            Sleep(30); // �ð� ����

            // �׸��� ���� ���� ���, ä��� ���� ���
            SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(255, 255, 255)));
            SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));

            // ������(���)���� ���� �׷��� ���� �����. 
            Ellipse(hdc, x, y, x + BALL_SIZE, y + BALL_SIZE);

            // �׸��� ���� ���� ������, ä��� ���� ���
            SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(255, 0, 0)));
            SelectObject(hdc, CreateSolidBrush(RGB(255, 255, 255)));

            // ���� ������ ������ �׷��д�.  
            Ellipse(hdc, x, y, x + 1, y + 1);

            // ���� ���� ������ â �ϴܿ� ����Ѵ�. 
            wsprintf(str, TEXT(" %3d��"), degree);    // ���� ���� ����ϱ� ���� ���ڿ��� ��ȯ
            TextOut(hdc, x, 420, str, lstrlen(str)); // ���� ���� ȭ�鿡 ���

            // �ð� ���� ����
            t += dt;

            // ���� ��ǥ�� x,y �Ѱ� ���� �����ߴ��� �˻��ϰ� ���������� ��� �ߴ�
            if (x >= X_END) break; // ���� x��ǥ ���� 800�� �Ѿ� ���� ��� �ߴ�
            if (y > Y_END) break; // ���� y��ǥ ���� 400�� �Ѿ� ���� ��� �ߴ� 
        } //while
    }//for
    return 0;
}