#include <dos.h>
#include "print/print.h"

void print_char(int y, int x, char ch, char attr)
{
	char far *location; // location은 위의 공식에 의해서 값을 갖는다.
	
	location = 0xb8000000 + y * 160 + x * 2 ;
	
	*location++ = ch;
	*location = attr;
}

void print_string(int y, int x, char *string, char attr)
{
	int i;
	char buff[255];
	strcpy(buff,string);

	for(i=0;i<=strlen(buff);i++)
	{
		print_char( y,  x, *(buff+i),  attr);
		++x;
		if(buff[i]=='\n')
		{
			break;
		}
	}
	
}
