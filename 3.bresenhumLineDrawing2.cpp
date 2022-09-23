#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;
    p = 2 * dy - dx;
    while (x < x1)
    {
        if (p >= 0)
        {
            putpixel(x, y, 7);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            putpixel(x, y, 7);
            p = p + 2 * dy;
        }
        x = x + 1;
    }
}
int main()
{
    int x0, y0, x1, y1;

    printf("Enter co-ordinates of first point: ");
    scanf("%d%d", &x0, &y0);
    printf("Enter co-ordinates of second point: ");
    scanf("%d%d", &x1, &y1);

    int gdriver = DETECT, gmode, error;
    initgraph(&gdriver, &gmode, (char *)"");

    drawline(x0, y0, x1, y1);

    getch();
    closegraph();

    return 0;
}