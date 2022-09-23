// Midpoint Ellipse 0,0, 8,6
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;
void ellipse(int xc, int yc, int rx, int ry)
{
    float x, y, pk, pk1;

    x = 0;
    y = ry;

    pk = (ry * ry) - (rx * rx * ry) + ((rx * rx) / 4);
    while ((2 * x * ry * ry) < (2 * y * rx * rx))
    {
        if (pk <= 0)
        {
            x = x + 1;
            pk1 = pk + (2 * ry * ry * x) + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            pk1 = pk + (2 * ry * ry * x) - (2 * rx * rx * y) + (ry * ry);
        }
        pk = pk1;
        putpixel(xc + x, yc + y, 2);
        putpixel(xc - x, yc + y, 2);
        putpixel(xc + x, yc - y, 2);
        putpixel(xc - x, yc - y, 2);
    }

    pk = ((x + 0.5) * (x + 0.5) * ry * ry) + ((y - 1) * (y - 1) * rx * rx) - (rx * rx * ry * ry);
    while (y > 0)
    {
        if (pk > 0)
        {
            y = y - 1;
            pk1 = pk - (2 * rx * rx * y) + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            pk1 = pk + (2 * ry * ry * x) - (2 * rx * rx * y) + (rx * rx);
        }
        pk = pk1;
        putpixel(xc + x, yc + y, 2);
        putpixel(xc - x, yc + y, 2);
        putpixel(xc + x, yc - y, 2);
        putpixel(xc - x, yc - y, 2);
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
    float xc, yc, rx, ry;

    cout << "Mid point ellipse drawing algorithm\n"
         << endl;
    cout << "Enter Center for ellipse (x0,y0) :   " << endl;
    cin >> xc >> yc;

    cout << "Enter x-radius and y-radius :    " << endl;
    cin >> rx >> ry;

    // graph initialization
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    draw_plot(screenWidth, screenHeight);

    int midx = screenWidth / 2;
    int midy = screenHeight / 2;
    xc = midx + xc;
    yc = midy - yc;

    setcolor(WHITE);
    outtextxy(midx + 10, midy + 10, "(0,0)");

    ellipse(xc, yc, rx, ry);

    getch();
    closegraph();
}