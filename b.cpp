// Scalling Line Drawing - DDA 5,6 80,120

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

void graph(int x, int y, int x1, int y1)
{

    // graph initialization
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    draw_plot(screenWidth, screenHeight);

    int midx = screenWidth / 2;
    int midy = screenHeight / 2;
    x = midx + x;
    x1 = midx + x1;

    y = midy - y;
    y1 = midy - y1;

    setcolor(WHITE);
    outtextxy(midx + 20, midy + 20, "(0,0)");
    setcolor(WHITE);
    outtextxy(x + 5, y + 5, "S");
    setcolor(WHITE);
    outtextxy(x1 + 5, y1 + 5, "E");


    line(x, y, x1, y1);

}

int main()
{
    int x, y, x1, y1;
    int scl_fctr_x, scl_fctr_y;

    cout << "Scaling Triangle" << endl;
    cout << "Enter first coordinate of Triangle = ";
    cin >> x >> y;

    cout << "Enter second coordinate of Triangle = ";
    cin >> x1 >> y1;


    cout << "Enter Scaling factor x and y = ";
    cin >> scl_fctr_x >> scl_fctr_y;

    graph(x, y, x1, y1);


    x = x * scl_fctr_x;
    x1 = x1 * scl_fctr_x;
   
    y = y * scl_fctr_y;
    y1 = y1 * scl_fctr_y;
 

    graph(x, y, x1, y1);


    getch();
    closegraph();
}