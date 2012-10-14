#include "inverse/inverse.h"

void VGA_inverse_attrib(unsigned char far *attrib)
{
	unsigned char origin_attrib;

	origin_attrib = *attrib;			 //attrib�� ���� 4bit�� ����  4bit�� �ű�	
	*attrib = *attrib & 0x0f;			 //0000 1111 *attrib�� ���� 4bit�� 0���� ���� 
	origin_attrib <<= 4;				 //���� �Ӽ� ���� ����
	*attrib >>= 4;						 //*origin_attrib�� ���� 4bit�� ���� 4bit�� �ű�
	*attrib = *attrib | origin_attrib;	 //*attrib�� ���� 4bit�� origin_attrib�� ���� 4bit�� ������ �ٲ�
										 ///*origin_attrib�� ���� 4bit�� ���� ���� *attrib�� ����4bit�� ����					
}

void VGA_inverse_bar(int x, int y, int length)
{
int i = 0;
unsigned char far *attr_memory = (unsigned char far *) 0xb8000001L;
attr_memory = attr_memory + y * 160 + x * 2; /* ���ڿ��� �Ӽ����� ����Ǿ� �ִ�
RAM �ּҸ� ���� */
for(i = 0; i < length; i++){ /* length��ŭ �ݺ� */
VGA_inverse_attrib(attr_memory); /* ������ �Ӽ��� �������� ����*/
attr_memory += 2;
}
}
//void VGA_inverse_bar(int y,int x,int length)
//{
//	int i = 0;
//	unsigned char far *attr_memory = (unsigned char far *)0xb8000001L;
//	
//	attr_memory =attr_memory + y * 160 + x *2;//���ڿ��� �Ӽ����� ����Ǿ� �ִ� RAM �ּҸ� ����
//	
//	for(i=0;i<length;++i)                     //length��ŭ �ݺ�
//	{
//		VGA_inverse_attrib(attr_memory);      //������ �Ӽ��� �������� ����
//		attr_memory + = 2;
//	}
//}