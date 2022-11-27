#include <cmath>
#include <conio.h>
#include <graphics.h>
#include <windows.h>
#define pi acos(-1)//如果这行无法运行，把acos改成acosf
using namespace std;
short size = 500, r = 20;//屏幕大小和球的半径
float g = 0.5;//重力
float v = 10, theta = 45;//初始速度和抛射角度

float vy = -v * sin(theta * pi / 180);//拆合速度 为x,y方向上的速度
float vx = v * cos(theta * pi / 180);
/*
(0,0)------------>x正方向
  | easyx的坐标系方向
  | 和数学的平面直角坐标系不一样
  | 向右下是正
  |
  |
  |
  V
  y正方向
 */
float x = size / 2;//球（圆心）坐标
float y = size / 2;

//wasd移动球
void move()
{
    if (GetAsyncKeyState(65) & 0x8000)//GetAsyncKeyState用法自行搜索学习
    {
        vx -= 1;
    }
    if (GetAsyncKeyState(87) & 0x8000)
    {
        vy -= 1;
    }
    if (GetAsyncKeyState(68) & 0x8000)
    {
        vx += 1;
    }
    if (GetAsyncKeyState(83) & 0x8000)
    {
        vy += 1;
    }
	
    vx *= 0.99;//速度衰减
    vy *= 0.99;
	
    x += vx;
    vy += g;//y方向上的速度因 重力 而减小
    y += vy;
	
    if (x >= size - r)//判断是否碰到边框，碰到就反弹
    {
        vx *= -0.95;//速度方向相反，并衰减
        x = size - r;
    }
    if (x <= r)
    {
        vx *= -0.95;
        x = r;
    }

    if (y >= size - r)
    {
        y = size - r;
        vy *= -0.95;
    }
    if (y <= r)
    {
        y = r;
        vy *= -0.95;
    }
}
int main()
{

    initgraph(size, size);//初始界面

    for (;;)//for(;;)的效率好像比while(true)高
    {
        move();//调用函数move
        cleardevice();//清除画面
        
		BeginBatchDraw();//[B]开始预渲染画面（用BFE三个函数可以预渲染防止画面闪烁）

        solidcircle(x, y, r);//绘制球球
		
        FlushBatchDraw();//[F]展示一帧画面，因为绘制过，所以不会闪烁
		
        Sleep(15);//停顿15ms（1000ms/15ms ≈》60fps），不停顿就帧率太高辣
    }
    EndBatchDraw();//[E]结束绘制
    return 0;
}
