
#include <iostream>
#include <graphics.h>   //ͼ�ν�����ͷ�ļ���TC2.0
#include <time.h>
#include <stdlib.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

#define NUM  13			//13��

//�̻����Ľṹ��
struct Jet
{
	int x, y;			//�̻����ĵ�ǰ��x y
	int hx, hy;			//��ߵ��x y
	bool shoot;			//����̻�����һ��״̬  �Ƿ��ڷ���״̬
	
	DWORD dt, t2, t1;  //����ʱ�������������ٶ�
	IMAGE img[2];      //ͼƬ������ 2��Ԫ�� �������ͼƬ
	byte n : 1;        //�ṹ������ λ�� ����n
}jet[NUM];             //�ṹ�����  ֻ��1���̻���
//jet[NUM]  �̻���������  13��Ԫ��

struct Fire
{
	int r;					//��ǰ�뾶
	int max_r;				//���뾶
	int x, y;               //ͼ�ν������������
	int cen_x, cen_y;       //���ĵ������
	int width, height;      //ͼƬ�Ŀ�Ⱥ͸߶�
	int xy[240][240];       //��������

	bool show;              //�Ƿ���ʾ
	bool draw;              //�Ƿ����
	DWORD t1, t2, dt;       //���ŵ��ٶ� GetTickCount()
}fire[NUM];
//fire[NUM]  �̻�����  13��Ԫ��

//����ͼƬ
void LoadImg()  //��ʼ���Ĺ��̡�img[]
{
	IMAGE allflowers, flower;
	loadimage(&allflowers, L"flower.jpg", 3120, 240);
	for (int i = 0; i < NUM; i++)
	{
		SetWorkingImage(&allflowers);
		getimage(&flower, i * 240, 0, 240, 240);
		SetWorkingImage(&flower);

		for (int y = 0; y < 240; y++)
		{
			for (int x = 0; x < 240; x++)
			{
				fire[i].xy[x][y] = getpixel(x, y);
			}
		}
	}
	
	IMAGE	image;  //����һ��ͼƬ
	//һ����ͼƬ�����ؽ���
	loadimage(&image, L"shoot.jpg", 200, 50);
	//putimage(0, 0, &image);  //���image

	for (int i = 0; i < NUM; i++)
	{
		//��image�����ȡһ��СͼƬ
		SetWorkingImage(&image);
		//�õ�֮�󱣴浽 img[]
		int n = rand() % 5;  //n    0-4  0-100 20-120 40-140 60-160 80-180
		getimage(&jet[i].img[0], n*20, 0, 20, 50);  //����
		getimage(&jet[i].img[1], (n+5)*20, 0, 20, 50); //����
	}
	SetWorkingImage(NULL);
	//jet[NUM]  13  ÿһ��Ԫ�� 2��СͼƬ  ��������
}

//��ʼ��  13��
void FireInit(int i)
{
	//��ʼ���̻�
	int r[13] = { 120, 120, 155, 123, 130, 147, 138, 138, 130, 135, 140, 132, 155 };
	int x[13] = { 120, 120, 110, 117, 110, 93, 102, 102, 110, 105, 100, 108, 110 };
	int y[13] = { 120, 120, 85, 118, 120, 103, 105, 110, 110, 120, 120, 104, 85 };
	fire[i].cen_x = x[i];
	fire[i].cen_y = y[i];
	fire[i].max_r = r[i];
	fire[i].show = false;
	fire[i].width = 240;
	fire[i].height = 240;
	fire[i].dt = 5;
	fire[i].r = 0;
	fire[i].t1 = GetTickCount();

	//��ʼ���̻���
	jet[i].dt     = rand()%10 + 1;     //ÿһ���̻������ٶ�Ҫ��Ҫ��ͬ 
	jet[i].n      = 0;
	jet[i].shoot  = false;
	jet[i].t1     = GetTickCount();  //��ȡһ��ϵͳ��ʱ��
}

//��ʾ���� ѡ�� ʱ����
void Choise(DWORD& t1)   //t1    ����  C++����C���Ե�һ����Ҫ����
{
	DWORD t2 = GetTickCount();  //t2

	if (t2 - t1 > 100)   //ms  ���100ms����һ���µ��̻���
	{
		//13���̻���
		int i = rand() % NUM;  //���ѡ��һ�� 
		
		if (jet[i].shoot == false&&fire[i].show==false)  //����һ���µ��̻��� �Ƿ���״̬��
		{
			jet[i].x = rand()%1200;
			jet[i].y = rand()%100+600;  //600-699
			jet[i].hx = jet[i].x;
			jet[i].hy = rand()%400;  // 0-399
			jet[i].shoot=true;  //ÿѡ��һ�� ����״̬ ��ѡ�ˡ�  13���˷���״̬��

			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
		}
		t1 = t2;
	}
}

void Shoot()
{
	//13���̻���
	for (int i = 0; i < NUM; i++)
	{
		//�ٶ�  jet[].t2  t1  dt
		//shoot = true	
		jet[i].t2 = GetTickCount();
		if (jet[i].t2 - jet[i].t1 >= jet[i].dt&&jet[i].shoot == true)
		{
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
			//y--  ����һֱ��  ̫��ȥ�ˡ�
			if (jet[i].y >= jet[i].hy)  //0
			{
				jet[i].y-=5;  //����
				jet[i].n++;  //�������˰�
			}
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);

			//���̻����ɵ���ߵ�֮��
			if (jet[i].y <= jet[i].hy)
			{
				putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
				jet[i].shoot = false;
				fire[i].x = jet[i].hx;   //��ߵ����������  ���̻�  
				fire[i].y = jet[i].hy;
				fire[i].show = true;
			}
			jet[i].t1 = jet[i].t2;
		}
	}
}

void ShowFire(DWORD* pMem)   //pMem  ʲôָ��  �Դ�ָ��
{
	int drt[16] = { 5, 5, 5, 5, 5, 6, 25, 25, 25, 25, 55, 55, 55, 55, 55, 65 };

	for (int i = 0; i < NUM; i++)
	{
		fire[i].t2 = GetTickCount();
		if (fire[i].t2 - fire[i].t1>fire[i].dt&&fire[i].show == true)
		{
			if (fire[i].r < fire[i].max_r)
			{
				fire[i].r++;
				fire[i].dt = drt[fire[i].r / 10];  //��������������
				fire[i].draw = true;
			}
			if (fire[i].r >= fire[i].max_r - 1)
			{
				fire[i].draw = false;
				FireInit(i);
			}
			fire[i].t1 = fire[i].t2;
		}

		if (fire[i].draw)  //�ڻ���
		{
			for (double a = 0; a <= 6.28; a += 0.01)  //��� ����  ��ѧ���еĽǶ�
			{
				//���ѡ�  x = a + r*cos()  //cen_x  cen_y  Բ
				int x1 = (int)(fire[i].cen_x + fire[i].r*cos(a));
				int y1 = (int)(fire[i].cen_y + fire[i].r*sin(a));

				if (x1 > 0 && x1<fire[i].width&&y1>0 && y1 < fire[i].height)
				{
					int b = fire[i].xy[x1][y1] & 0xff;
					int g = (fire[i].xy[x1][y1]>>8) & 0xff;;
					int r = fire[i].xy[x1][y1] >> 16;
					//RGB(0,0,0);  ��ɫ

					int xx = (int)(fire[i].x + fire[i].r*cos(a));
					int yy = (int)(fire[i].y + fire[i].r*sin(a));

					if (b>0x20 && g > 0x20 && r > 0x20 && xx > 0 && xx<1200 && yy>0 && yy < 800)
					{
						pMem[yy * 1200 + xx] = BGR(fire[i].xy[x1][y1]);
					}
				}
			}
			fire[i].draw = false;
		}
	}
}

int main()
{
	//��һ�����ڣ� ���1200 �߶�800  ,SHOWCONSOLE
	initgraph(1200,1000);  //init��ʼ��  graphͼ�ν���
	srand((unsigned int)time(NULL));

	mciSendString(L"open С����.mp3 alias music", 0, 0, 0);
	mciSendString(L"play music", 0, 0, 0);


	DWORD t1 = GetTickCount();
	DWORD *pMem = GetImageBuffer(NULL);

	LoadImg();  //��ʼ��13���̻�����img
	for (int i = 0; i < NUM; i++)  //��ʼ��13���̻�������������
	{
		FireInit(i);
	}
	
	BeginBatchDraw();
	while (1)
	{
		Sleep(10);
		for (int clr = 0; clr < 1000; clr++) 
		{
			for (int j = 0; j < 2; j++)
			{
				int px1 = rand() % 1200;
				int py1 = rand() % 800;

				if (py1 < 799)
				{
					pMem[py1 * 1200 + px1] = pMem[py1 * 1200 + px1 + 1] = BLACK;
				}
			}
		}

		Choise(t1);
		Shoot();
		ShowFire(pMem);
		FlushBatchDraw();
	}

	return 0;
}
