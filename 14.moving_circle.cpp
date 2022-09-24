#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    float x1, y1, x2, y2, x0, y0;
    float dx, dy;
    int steps, x, y;

    cout << "Enter start Point (x1, y1) :";
    cin >> x1 >> y1;

    cout << "Enter End Point (x2, y2) :";
    cin >> x2 >> y2;

    int width = GetSystemMetrics(SM_CXSCREEN);
    int height = GetSystemMetrics(SM_CYSCREEN);

    int midx = width / 2;
    int midy = height / 2;

    x1 = midx + x1;
    x2 = midx + x2;
    y1 = midy - y1;
    y2 = midy - y2;
    dx = x2 - x1;
    dy = y2 - y1;

    int gd, gm;
    initgraph(&gd, &gm, (char *)" ");
    steps = (int)max(abs(dx), abs(dy));
    float x_inc, y_inc;

    x_inc = dx / (float)(steps);
    y_inc = dy / (float)(steps);

    x = round(x1);
    y = round(y1);

    
    line(0, midy, width, midy);
    line(midx, 0, midx, height);
    delay(4000);

    x0 = x1;
    y0 = y1;
    for (int i = 0; i < steps; i++)
    {
        setcolor(YELLOW);
        line(0, midy, width, midy);
        line(midx, 0, midx, height);
        setcolor(RED);
        line(x1, y1, x2, y2);

        circle(x, y, 20);

        delay(20);
        x0 += x_inc;
        y0 += y_inc;
        x = round(x0);
        y = round(y0);

        delay(10);
        cleardevice();
    }

    delay(10000);

    getchar();
    closegraph();
    return 0;
}