// translation square 0,30 30,30 30,0 0,0 100,100

#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void draw_plot(int x, int y)
{
    int screenWidth = x;
    int screenHeight = y;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)" ");

    setcolor(YELLOW);
    line(0, screenHeight / 2, screenWidth, screenHeight / 2);
    setcolor(YELLOW);
    line(screenWidth / 2, 0, screenWidth / 2, screenHeight);

    for (int i = x / 2 + 20; i <= x; i += 20)
    {
        for (int j = y / 2 + 20; j <= y; j += 20)
        {
            setcolor(DARKGRAY);
            line(0, j, x, j);
            line(i, 0, i, y);
        }
    }

    for (int i = x / 2 - 20; i >= 0; i -= 20)
    {
        for (int j = y / 2 - 20; j >= 0; j -= 20)
        {
            setcolor(DARKGRAY);
            line(0, j, x, j);
            line(i, 0, i, y);
        }
    }
}

void graph(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3)
{

    // graph initialization
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    draw_plot(screenWidth, screenHeight);

    int midx = screenWidth / 2;
    int midy = screenHeight / 2;
    x = midx + x;
    x1 = midx + x1;
    x2 = midx + x2;
    x3 = midx + x3;

    y = midy - y;
    y1 = midy - y1;
    y2 = midy - y2;
    y3 = midy - y3;

    setcolor(WHITE);
    outtextxy(midx + 20, midy + 20, "(0,0)");
    setcolor(WHITE);
    outtextxy(x + 5, y + 5, "1");
    setcolor(WHITE);
    outtextxy(x1 + 5, y1 + 5, "2");
    setcolor(WHITE);
    outtextxy(x2 + 5, y2 + 5, "3");
    setcolor(WHITE);
    outtextxy(x3 + 5, y3 + 5, "4");

    line(x, y, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);

    line(x3, y3,x, y);
}

int main()
{
    int x, y, x1, y1, x2, y2,x3,y3;
    int trans_fctr_x, trans_fctr_y;

    cout << "Translation Square" << endl;
    cout << "Enter first coordinate of Square = ";
    cin >> x >> y;

    cout << "Enter second coordinate of Square = ";
    cin >> x1 >> y1;

    cout << "Enter third coordinate of Square = ";
    cin >> x2 >> y2;

        cout << "Enter fourth coordinate of Square = ";
    cin >> x3>> y3;

    cout << "Enter Translation factor x and y = ";
    cin >> trans_fctr_x >> trans_fctr_y;

    graph(x, y, x1, y1, x2, y2,x3,y3);

    x = x + trans_fctr_x;
    x1 = x1 + trans_fctr_x;
    x2 = x2 + trans_fctr_x;
    x3 = x3 + trans_fctr_x;

    y = y + trans_fctr_y;
    y1 = y1 + trans_fctr_y;
    y2 = y2 + trans_fctr_y;
    y3 = y3 + trans_fctr_y;

    graph(x, y, x1, y1, x2, y2,x3,y3);

    getch();
    closegraph();
}