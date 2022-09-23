// bresenhumLineDrawing
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void bresenhum(int x0, int y0, int xN, int yN, int color)
{
    int dx, dy, steps, x_inc, y_inc, p;
    int i;

    dx = xN - x0;
    dy = yN - y0;

    p = 2 * dy - dx;

    while (x0 <= xN)
    {
        putpixel(x0, y0, color);

        if (p < 0)
        {

            p = p + 2 * dy;
        }
        else
        {
            p = p + 2 * dy - 2 * dx;
            y0++;
        }
        
        x0++;
        // cout<<x0<<", "<<y0<<endl;
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
    float x0, y0, xN, yN;

    cout << "Enter start Point (x0, y0) :";
    cin >> x0 >> y0;

    cout << "Enter End Point (xN, yN) :";
    cin >> xN >> yN;

    // graph initialization
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    draw_plot(screenWidth, screenHeight);

    int midx = screenWidth / 2;
    int midy = screenHeight / 2;
    x0 = midx + x0;
    xN = midx + xN;
    y0 = midy - y0;
    yN = midy - yN;
    setcolor(WHITE);
    outtextxy(midx + 20, midy + 20, "(0,0)");
    setcolor(WHITE);
    outtextxy(x0 + 5, y0 + 5, "Starting point");
    setcolor(WHITE);
    outtextxy(xN + 5, yN + 5, "Ending Point");

    ///  bresenhum function call
    bresenhum(x0, y0, xN, yN, RED);

    // cloase graph
    getch();
    closegraph();

    return 0;
}
