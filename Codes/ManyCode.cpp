#include <algorithm>
#include <cmath>
#include <conio.h>
#include <ctime>
#include <easyx.h>
#include <graphics.h>
#include <iostream>
#include <random>
using namespace std;

//自然数平方求和
void N2()
{
    unsigned int n, k;
    unsigned long ans = 0;
    scanf("%d%d", &k, &n);

    for (unsigned int i = 0; i <= n; ++i)
        ans += pow(i, k);

    printf("Sum of %d powers of integers from 1 to %d = %ld", n, k, ans);
}

// 5个数据求平均
void Sum()
{
    int fs[5], zf = 0;

    for (int i = 0; i < 5; ++i)
        scanf("%d", &fs[i]);

    for (int i = 0; i < 5; ++i)
        zf += fs[i];

    printf("%lf", (double)zf / 5.0);
}

//输入数据找相同数字
void Find()
{
    int num, n, s, ans = 0;
    scanf("%d%d", &num, &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &s);

        if (s == num)
            ++ans;
    }

    printf("有%d个相同数字！", ans);
}

//输出中间数
void SecondNum1()
{
    int n[3];
    scanf("%d", &n[0]);
    scanf("%d", &n[1]);
    scanf("%d", &n[2]);
    sort(n, n + 3);
    printf("%d", n[1]);
}
void SecondNum2()
{

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if ((b <= a && a <= c) || (c <= a && a <= b))
        printf("%d", a);
    else if ((a <= b && b <= c) || (c <= b && b <= a))
        printf("%d", b);
    else if ((a <= c && c <= b) || (b <= c && c <= a))
        printf("%d", c);
}

//判断素数
bool Prime(unsigned long long num)
{
    if (num == 2 || num == 3 || num == 5 || num == 7)
        return 1;

    if (num % 6 != 1 && num % 6 != 5)
        return 0;

    int tmp = sqrt(num);

    for (int i = 5; i <= tmp; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;

    return 1;
}

//冒泡排序
void BubbleSort(unsigned short *list, unsigned short len)
{
    unsigned short i, j;
    for (i = 0; i < len - 1; ++i)
        for (j = 0; j < len - 1 - i; ++j)
            if (list[j] > list[j + 1])
                swap(list[j], list[j + 1]);
}

//随机输出名字-C语言
void RandName()
{
    char a[5][3];
    int ran = rand() % 5;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; ++i)
        cin >> a[i];
    for (int i = 0; i < 3; ++i)
        printf("%c", a[ran][i]);
}

//算直角三角形面积
double RtAngleArea(double a, double b, bool co = true)
{
    if (co)
        cout << "Area: " << a * b / 2 << endl;
    return a * b / 2;
}
//求扇形面积
double ShanArea(double r, double n, bool co = true)
{
    if (co)
        cout << "Area:" << n * r * r / 360.0 << "π" << endl;
    return n * 3.1415926 * r * r / 360.0;
}

//算扇形弧长
double ShanL(double r, double n, bool co = true)
{
    if (co)
        cout << n * r / 180 << "π" << endl;
    return n * r * 3.1415926 / 180.0;
}

//十进制转二进制
void Ten_Two()
{
    int *a = new int[50];
    int n;
    int i = 0;
    printf("请输入十进制数：");
    cin >> n;
    while (n > 0)
    {
        a[i] = n % 2;
        ++i;
        n /= 2;
    }
    for (i--; i >= 0; i--)
    {
        cout << a[i];
    }
    cout << endl;
    delete[] a;
}

void PRect(int *arr, int w, int h)
{
    for (int i = 0; i < w / 2; ++i)
    {
        for (int j = 0; j < h / 2; ++j)
        {
            arr[i + j * w] = arr[w * (h - j) - i];
        }
    }
}

int main()
{
    int arr[10][5];
    int *a = *arr;
    for (size_t j = 0; j < 10; ++j)
    {
        for (size_t i = 0; i < 5; ++i)
        {
            arr[j][i] = i * j + i + j;
        }
    }
    PRect(*arr, 10, 5);
    for (size_t i = 0; i < 50; ++i)
    {
        cout << a[i] << endl;
    }

    _getch();
    return 0;
}
