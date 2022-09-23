// Scalling line,polygon 10,10,50,50, 4,5


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

void graph(int x, int y, int r)
{

    // graph initialization
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    draw_plot(screenWidth, screenHeight);

    int midx = screenWidth / 2;
    int midy = screenHeight / 2;
    
    x = midx + x;
    y = midy - y;

    setcolor(WHITE);
    outtextxy(midx + 20, midy + 20, "(0,0)");

    setcolor(WHITE);
    outtextxy(x + 5, y + 5, "S");


    circle(x, y, r);
}

int main()
{
    int x, y, x2, y2,r,r2;
    int scl_fctr_x, scl_fctr_y,scl_fctr_r;

    cout << "Circle Triangle" << endl;
    cout << "Enter center coordinate of circle = ";
    cin >> x >> y;

 
    cout << "Enter radius = ";
    cin >> r;

    cout << "Enter Scaling factor for radius r ";
    cin >>scl_fctr_r;

    graph(x, y, r);



    r = r * scl_fctr_r;


    graph(x, y, r);


    getch();
    closegraph();
}