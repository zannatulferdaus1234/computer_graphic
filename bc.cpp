#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

// void dda(float x0, float y0, float xN, float yN, int color)
// {
//     float dx, dy, x_inc, y_inc,x0,y0;
//     int steps, i;
    
//     dx = (xN - x0);
//     dy = (yN - y0);

//     steps = max(abs(dy), abs(dx));

//     x_inc = dx / steps;
//     y_inc = dy / steps;

// 	    //     round(x0);
// 		// round(y0);

// 	x0=x1;
// 	y0=y1;

//     for (i = 1; i <= steps; i++)
//     {
        

//         // x0 += x_inc;
//         // y0 += y_inc;
// 		setcolor(YELLOW);
//         line(0, midy, width, midy);
//         line(midx, 0, midx, height);
//         setcolor(RED);
//         line(x1, y1, x2, y2);

//         circle(x, y, 20);

//         delay(20);
//         x0 += x_inc;
//         y0 += y_inc;
//         x = round(x0);
//         y = round(y0);

//         delay(10);
//         cleardevice();
//     }
// }


void circle(float x1, float y1, float r)
{
	int i;
	float dx, dy, steps, x_inc, p,x,y;

	x=0;y=r;
	p=1-r;

	while (x<=y)
	{
        putpixel(x1 + x, y1 + y, 7);
        putpixel(x1 + y, y1 + x, 7);
        putpixel(x1 - y, y1 + x, 7);
        putpixel(x1 - x, y1 + y, 7);
        putpixel(x1 - x, y1 - y, 7);
        putpixel(x1 - y, y1 - x, 7);
        putpixel(x1 + y, y1 - x, 7);
        putpixel(x1 + x, y1 - y, 7);		
		if(p>0)
		{
			x++;
			y--;
			p+=2*x-2*y+1;
			
		}
		
		else{
			x++;
			y=y;
			p+=2*x+1;
		
		}
		//cout<<(x)<<",	"<<(y)<<endl;

		
	}
}



int main()
{

	int i;
	float x1, y1,x2,y2, r;

	cout << "Enter (x1,y1),r	:	" << endl;
	cin >> x1 >> y1 >> x2>>y2;

	int gd = DETECT, gm, midx, midy;
	initgraph(&gd, &gm, (char *)"");

	midx = GetSystemMetrics(SM_CXSCREEN)/ 2;
	midy = GetSystemMetrics(SM_CYSCREEN)/ 2;

	setcolor(YELLOW);
	line(midx, 0, midx, GetSystemMetrics(SM_CXSCREEN));
	line(0, midy, GetSystemMetrics(SM_CXSCREEN), midy);

	x1 = midx + x1;
	y1 = midy - y1;
	x2 = midx + x2;
	y2 = midy - y2;

	setcolor(WHITE);
	outtextxy(midx + 5, midy + 5, "(0,0)");

	float dx, dy, x_inc, y_inc,x0,y0;
    int steps,x,y;
    
    dx = (x2 - x1);
    dy = (y2 - y1);

    steps = max(abs(dy), abs(dx));

    x_inc = dx / steps;
    y_inc = dy / steps;

	    //     round(x0);
		// round(y0);
	x=x1;
	y=y1;
	x0=x1;
	y0=y1;

    for (i = 1; i <= steps; i++)
    {
        

        // x0 += x_inc;
        // y0 += y_inc;
		setcolor(YELLOW);
	line(midx, 0, midx, GetSystemMetrics(SM_CXSCREEN));
	line(0, midy, GetSystemMetrics(SM_CXSCREEN), midy);
        setcolor(RED);
        line(x1, y1, x2, y2);

        circle(x, y, 20);

        delay(20);
        x0 += x_inc;
        y0 += y_inc;
        x = (x0);
        y = (y0);

        delay(10);
        cleardevice();
    }

	getch();
	closegraph();
}