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

