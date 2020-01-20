
#include <iostream>
#include <graphics.h>   //图形界面库的头文件。TC2.0
#include <time.h>
#include <stdlib.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

#define NUM  13			//13个

//烟花弹的结构体
struct Jet
{
	int x, y;			//烟花弹的当前的x y
	int hx, hy;			//最高点的x y
	bool shoot;			//这个烟花弹的一个状态  是否处于发射状态
	
	DWORD dt, t2, t1;  //三个时间点控制上升的速度
	IMAGE img[2];      //图片的数组 2个元素 存放两张图片
	byte n : 1;        //结构体里面 位段 变量n
}jet[NUM];             //结构体变量  只有1个烟花弹
//jet[NUM]  烟花弹的数组  13个元素

struct Fire
{
	int r;					//当前半径
	int max_r;				//最大半径
	int x, y;               //图形界面里面的坐标
	int cen_x, cen_y;       //中心点的坐标
	int width, height;      //图片的宽度和高度
	int xy[240][240];       //像素数组

	bool show;              //是否显示
	bool draw;              //是否绘制
	DWORD t1, t2, dt;       //绽放的速度 GetTickCount()
}fire[NUM];
//fire[NUM]  烟花数组  13个元素

//加载图片
void LoadImg()  //初始化的过程。img[]
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
	
	IMAGE	image;  //定义一张图片
	//一整张图片都加载进来
	loadimage(&image, L"shoot.jpg", 200, 50);
	//putimage(0, 0, &image);  //输出image

	for (int i = 0; i < NUM; i++)
	{
		//从image上随机取一个小图片
		SetWorkingImage(&image);
		//拿到之后保存到 img[]
		int n = rand() % 5;  //n    0-4  0-100 20-120 40-140 60-160 80-180
		getimage(&jet[i].img[0], n*20, 0, 20, 50);  //暗的
		getimage(&jet[i].img[1], (n+5)*20, 0, 20, 50); //亮的
	}
	SetWorkingImage(NULL);
	//jet[NUM]  13  每一个元素 2张小图片  不清楚随机
}

//初始化  13次
void FireInit(int i)
{
	//初始化烟花
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

	//初始化烟花弹
	jet[i].dt     = rand()%10 + 1;     //每一个烟花弹的速度要不要相同 
	jet[i].n      = 0;
	jet[i].shoot  = false;
	jet[i].t1     = GetTickCount();  //获取一次系统的时间
}

//显示出来 选择 时间间隔
void Choise(DWORD& t1)   //t1    引用  C++对于C语言的一个重要扩充
{
	DWORD t2 = GetTickCount();  //t2

	if (t2 - t1 > 100)   //ms  间隔100ms产生一个新的烟花弹
	{
		//13个烟花弹
		int i = rand() % NUM;  //随机选择一个 
		
		if (jet[i].shoot == false&&fire[i].show==false)  //产生一个新的烟花弹 非发射状态。
		{
			jet[i].x = rand()%1200;
			jet[i].y = rand()%100+600;  //600-699
			jet[i].hx = jet[i].x;
			jet[i].hy = rand()%400;  // 0-399
			jet[i].shoot=true;  //每选择一个 发射状态 再选了。  13成了发射状态了

			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
		}
		t1 = t2;
	}
}

void Shoot()
{
	//13个烟花弹
	for (int i = 0; i < NUM; i++)
	{
		//速度  jet[].t2  t1  dt
		//shoot = true	
		jet[i].t2 = GetTickCount();
		if (jet[i].t2 - jet[i].t1 >= jet[i].dt&&jet[i].shoot == true)
		{
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
			//y--  不能一直减  太空去了。
			if (jet[i].y >= jet[i].hy)  //0
			{
				jet[i].y-=5;  //上升
				jet[i].n++;  //闪闪惹人爱
			}
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);

			//当烟花弹飞到最高点之后
			if (jet[i].y <= jet[i].hy)
			{
				putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
				jet[i].shoot = false;
				fire[i].x = jet[i].hx;   //最高点的坐标留着  给烟花  
				fire[i].y = jet[i].hy;
				fire[i].show = true;
			}
			jet[i].t1 = jet[i].t2;
		}
	}
}

void ShowFire(DWORD* pMem)   //pMem  什么指针  显存指针
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
				fire[i].dt = drt[fire[i].r / 10];  //？？？？？？？
				fire[i].draw = true;
			}
			if (fire[i].r >= fire[i].max_r - 1)
			{
				fire[i].draw = false;
				FireInit(i);
			}
			fire[i].t1 = fire[i].t2;
		}

		if (fire[i].draw)  //在绘制
		{
			for (double a = 0; a <= 6.28; a += 0.01)  //编程 弧度  数学当中的角度
			{
				//付费。  x = a + r*cos()  //cen_x  cen_y  圆
				int x1 = (int)(fire[i].cen_x + fire[i].r*cos(a));
				int y1 = (int)(fire[i].cen_y + fire[i].r*sin(a));

				if (x1 > 0 && x1<fire[i].width&&y1>0 && y1 < fire[i].height)
				{
					int b = fire[i].xy[x1][y1] & 0xff;
					int g = (fire[i].xy[x1][y1]>>8) & 0xff;;
					int r = fire[i].xy[x1][y1] >> 16;
					//RGB(0,0,0);  黑色

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
	//打开一个窗口！ 宽度1200 高度800  ,SHOWCONSOLE
	initgraph(1200,1000);  //init初始化  graph图形界面
	srand((unsigned int)time(NULL));

	mciSendString(L"open 小幸运.mp3 alias music", 0, 0, 0);
	mciSendString(L"play music", 0, 0, 0);


	DWORD t1 = GetTickCount();
	DWORD *pMem = GetImageBuffer(NULL);

	LoadImg();  //初始化13个烟花弹的img
	for (int i = 0; i < NUM; i++)  //初始化13个烟花弹的其他数据
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
