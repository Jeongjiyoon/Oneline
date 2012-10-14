#include "inverse/inverse.h"

void VGA_inverse_attrib(unsigned char far *attrib)
{
	unsigned char origin_attrib;

	origin_attrib = *attrib;			 //attrib의 상위 4bit를 하위  4bit로 옮김	
	*attrib = *attrib & 0x0f;			 //0000 1111 *attrib의 상위 4bit를 0으로 만듦 
	origin_attrib <<= 4;				 //원래 속성 값을 저장
	*attrib >>= 4;						 //*origin_attrib의 하위 4bit를 상위 4bit로 옮김
	*attrib = *attrib | origin_attrib;	 //*attrib의 상위 4bit를 origin_attrib의 상위 4bit의 값으로 바꿈
										 ///*origin_attrib의 상위 4bit의 값은 원래 *attrib의 하위4bit의 값임					
}

void VGA_inverse_bar(int x, int y, int length)
{
int i = 0;
unsigned char far *attr_memory = (unsigned char far *) 0xb8000001L;
attr_memory = attr_memory + y * 160 + x * 2; /* 문자열의 속성값이 저장되어 있는
RAM 주소를 구함 */
for(i = 0; i < length; i++){ /* length만큼 반복 */
VGA_inverse_attrib(attr_memory); /* 문자의 속성을 역상으로 만듦*/
attr_memory += 2;
}
}
//void VGA_inverse_bar(int y,int x,int length)
//{
//	int i = 0;
//	unsigned char far *attr_memory = (unsigned char far *)0xb8000001L;
//	
//	attr_memory =attr_memory + y * 160 + x *2;//문자열의 속성값이 저장되어 있는 RAM 주소를 구함
//	
//	for(i=0;i<length;++i)                     //length만큼 반복
//	{
//		VGA_inverse_attrib(attr_memory);      //문자의 속성을 역상으로 만듬
//		attr_memory + = 2;
//	}
//}