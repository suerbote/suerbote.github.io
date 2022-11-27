#include <cmath>
#include <conio.h>
#include <graphics.h>
#include <iostream>
using namespace std;

#define PI 3.1415926

#define R 5
//二维点半径

short FOCAL = 300;	   //焦点
short l = 100;		   //立方体棱长
short B = 250;		   //移动画面
double theta = PI / 6; //旋转角度

struct point//三维点
{
	double x;
	double y;
	double z;
};
struct dot//二维点
{
	double x;
	double y;
};
struct lines//线
{
	short a;
	short b;
};

point edge_table[8];//三维点组，立方体的各个点三维坐标
dot dot_table[8];//二维点组，决定投影在屏幕上的点在哪
lines line_table[12];//线组，决定哪俩点相连

point p2p(short x, short y, short z);//三维坐标变成三维点
dot p2d(point x, int choise);//三维点映射成二维点
//choise是旋转模式（x,y,z三轴,可填1,2,3）
short sig(short x);//符号函数，大于0输出1，小于零输出-1，0输出0

void Box()//创建立方体
{
/*这里利用了二进制生成三维点坐标
这些点分别是
000 001 010 011 100 101 110 111
*/
	for (int i = 0, j = 0; i < 8; ++i)
	{
		edge_table[i] = p2p(sig(i / 4) * l,
							sig(i / 2 % 2) * l,
							sig(i % 2) * l);
		if (!(i % 2))//点点对应
			line_table[j++] = {i, i + 1};
		if (!(i / 2 % 2))
			line_table[j++] = {i, i + 2};
		if (!(i / 4))
			line_table[j++] = {i, i + 4};
	}
}

void Draw()//绘制
{
	cleardevice();
	for (short i = 0; i < 8; ++i)//绘制二维点
	{
		dot_table[i] = p2d(edge_table[i], 2);//三维点转二维点
		solidcircle(dot_table[i].x + B, dot_table[i].y + B, R);
	}

	for (short i = 0; i < 12; ++i)//划线
	{
		line(dot_table[line_table[i].a].x + B,
			 dot_table[line_table[i].a].y + B,
			 dot_table[line_table[i].b].x + B,
			 dot_table[line_table[i].b].y + B);
	}
}

int main()
{

	initgraph(500,500);
        //设置颜色
	setfillcolor(RED);//点
	setlinecolor(WHITE);//线

	BeginBatchDraw();
	for (;;)
	{
		Box();
		Draw();
		theta += 0.002;//增加旋转的角度
		FlushBatchDraw();
	}
	EndBatchDraw();

	_getch();
	return 0;
}

point p2p(short x, short y, short z)
{
	return (point){x, y, z};
}

dot p2d(point x, int choise)
{
	if (choise == 1)
		return (dot){
			FOCAL * x.x / (FOCAL + x.z * cos(theta) - x.y * sin(theta)),
			FOCAL * (x.y * cos(theta) + x.z * sin(theta)) / (FOCAL + x.z * cos(theta) - x.y * sin(theta))};
	if (choise == 2)
		return (dot){FOCAL * (x.x * cos(theta) - x.z * sin(theta)) / (FOCAL + x.x * sin(theta) + x.z * cos(theta)),
					 FOCAL * x.y / (FOCAL + x.x * sin(theta) + x.z * cos(theta))};
	if (choise == 3)
		return (dot){FOCAL * (x.x * cos(theta) + x.y * sin(theta)) / (FOCAL + x.z),
					 FOCAL * (x.y * cos(theta) - x.x * sin(theta)) / (FOCAL + x.z)};
}

short sig(short x)
{
	if (x)
		return 1;
	else
		return -1;
}