#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <windows.h>
short qiPan[19][19];
short x = 9, y = 9;
_Bool wanJia = false;
void PanDing()
{
    short shu = 1, heng = 1, pie = 1, na = 1; //横竖撇捺

    for (short i = 1; i <= 4; i++)
    {
        if (qiPan[y + i][x] == qiPan[y][x] && qiPan[y][x])
            shu++;
        else
            break;
    }

    for (short i = 1; i <= 4; i++)
    {
        if (qiPan[y - i][x] == qiPan[y][x] && qiPan[y][x])
            shu++;
        else
            break;
    }

    for (short i = 1; i <= 4; i++)
    {
        if (qiPan[y][x - i] == qiPan[y][x] && qiPan[y][x])
            heng++;
        else
            break;
    }

    for (short i = 1; i <= 4; i++)
    {
        if (qiPan[y][x + i] == qiPan[y][x] && qiPan[y][x])
            heng++;
        else
            break;
    }

    for (short i = 1; i <= 4; i++)
    {
        if (qiPan[y + i][x - i] == qiPan[y][x] && qiPan[y][x])
            pie++;
        else
            break;
    }

    for (short i = 1; i <= 4; i++)
    {
        if (qiPan[y - i][x + i] == qiPan[y][x] && qiPan[y][x])
            pie++;
        else
            break;
    }

    for (short i = 1; i <= 4; i++)
    {
        if (qiPan[y + i][y + i] == qiPan[y][x] && qiPan[y][x])
            na++;
        else
            break;
    }

    for (short i = 1; i <= 4; i++) //左上
    {
        if (qiPan[y - i][x - i] == qiPan[y][x] && qiPan[y][x])
            na++;
        else
            break;
    }

    if (shu == 5 || heng == 5 || pie == 5 || na == 5)
    {
        if (qiPan[y][x] == 1)
        {
            printf("白子获胜!");
            system("pause");
            exit(0);
        }
        else
        {
            printf("黑子获胜!");
            system("pause");
            exit(0);
        }
    }
}
void XiaZi()
{
    char c;
    c = getch();

    switch (c)
    {
    case 'w':
        if (y > 0)
            y--;

        break;

    case 'a':
        if (x > 0)
            x--;

        break;

    case 's':
        if (y < 19)
            y++;

        break;

    case 'd':
        if (x < 19)
            x++;

        break;

    case 'j':
        if (qiPan[y][x] == 0)
        {
            qiPan[y][x] = wanJia + 1;
            wanJia = !wanJia;
        }
    }
}
void DaYinQiPan()
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (i == y && j == x)
            {
                printf("╋");
            }
            else if (qiPan[i][j] == 0)
            {
                printf("·");
            }
            else if (qiPan[i][j] == 1)
            {
                printf("●");
            }
            else if (qiPan[i][j] == 2)
            {
                printf("○");
            }
        }

        printf("\n");
    }
}
int main()
{
    memset(qiPan, 0, sizeof(qiPan));
    DaYinQiPan();

    while (true)
    {
        XiaZi();
        PanDing();
        system("cls");
        DaYinQiPan();
    }

    return 0;
}
