//Midpoint circle 100,100,200

#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void drawcircle(int x0, int y0, int radius)
{
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    while (x <= y)
    {
        putpixel(x0 + x, y0 + y, 7);
        putpixel(x0 + y, y0 + x, 7);
        putpixel(x0 - y, y0 + x, 7);
        putpixel(x0 - x, y0 + y, 7);
        putpixel(x0 - x, y0 - y, 7);
        putpixel(x0 - y, y0 - x, 7);
        putpixel(x0 + y, y0 - x, 7);
        putpixel(x0 + x, y0 - y, 7);

        if (p <= 0)
        {
            x++;
            y = y;
            p += 2 * x + 1;
        }

        if (p > 0)
        {
            x++;
            y--;
            p = p + 2 * x + 1 - 2 * y;
        }
        
        // cout << "( " << x << ", " << y << " ),    ";
        // cout << "( " << -x << ", " << y << " ),   ";
        // cout << "( " << x << ", " << -y << " ),   ";
        // cout << "( " << -x << ", " << -y << " )" << endl;
    }
}

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

int main()
{
    int x, y, r;

    cout << "Enter co-ordinates of center(x and y): ";
    cin >> x >> y;

    cout << "Enter radius of circle: ";
    cin >> r;

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    draw_plot(screenWidth, screenHeight);

    int midx = screenWidth / 2;
    int midy = screenHeight / 2;

    x = midx + x;
    y = midy - y;

    setcolor(WHITE);
    outtextxy(midx + 20, midy + 20, "(0,0)");

    drawcircle(x, y, r);

    getch();
    closegraph();

    return 0;
}