// ���� �ϼ��� ����ϴ� ���α׷�
#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	int month, days;
	
	printf("���� �Է��Ͻÿ�: ");
	scanf("%d", &month);

	switch(month) {
	case 2:
		days = 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		days = 30;
		break;
	default:
		days = 31;
	}
	printf("%d���� �ϼ��� %d�Դϴ�.\n", month, days);
}