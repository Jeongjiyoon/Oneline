#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include "print/print.h"
#include "inverse/inverse.h"

int main()
{
	int x;
	int y;
	
	clrscr();
	
	/*에디터 창*/
	print_char(0, 0, 218,7);
	print_char(0, 79,195,7);
	print_char(4, 0, 195,7);
	print_char(4, 79, 180,7);
	print_char(24, 0, 192,7);
	print_char(24, 79, 217,7);	
	for(y=1;y<4;++y)
	{	
		for(x=1;x<79;++x)
		{			
			print_char(0,x,196,7);
			print_char(4,x,196,7);		
			
		}
		print_char(y,0,179,7);
		print_char(y,79,179,7);	
	}
	for(y=5;y<24;++y)
	{	
		for(x=1;x<79;++x)
		{			
			
			print_char(24,x,196,7);		
			
		}
		print_char(y,0,179,7);
		print_char(y,79,179,7);	
	}
	
	print_char(5, 1, 218,7);
	print_char(5, 78, 191,7);
	print_char(18, 1, 192,7);
	print_char(18, 78, 217,7);	
	for(y=6;y<18;++y)
	{	
		for(x=2;x<78;++x)
		{			
			print_char(5,x,196,7);
			print_char(18,x,196,7);		
			
		}
		print_char(y,1,179,7);
		print_char(y,78,179,7);	
	}
	
	print_char(6, 3, 218,7);
	print_char(6, 76, 191,7);
	print_char(17, 3, 192,7);
	print_char(17, 76, 217,7);	
	for(y=7;y<17;++y)
	{	
		for(x=4;x<76;++x)
		{			
			print_char(6,x,196,7);
			print_char(17,x,196,7);		
			
		}
		print_char(y,3,179,7);
		print_char(y,76,179,7);	
	}
		
	print_char(19, 1, 218,7);
	print_char(19, 78, 191,7);
	print_char(23, 1, 192,7);
	print_char(23, 78, 217,7);
	for(y=20;y<23;++y)
	{	
		for(x=2;x<78;++x)
		{			
			print_char(19,x,196,7);
			print_char(23,x,196,7);		
			
		}
		print_char(y,1,179,7);
		print_char(y,78,179,7);	
	}

	print_string(2,7,"New          Load          Save          Save as          Exits",7);    
	print_string(21,11,"F10 - Menu          Alt + x - Exit          F1 - Help",7);

	VGA_inverse_bar(5,5,3);
	

	getche();
	
	
	return 0;
}

