// ������ ��� ���� ���α׷�

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{

	char op;
	int x, y, result;

	printf("������ �Է��Ͻÿ�\n(��: 2 + 5)\n>> ");
	scanf("%d %c %d", &x, &op, &y);

	switch (op) {
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		result = x / y;
		break;
	case '%':
		result = x % y;
		break;
	default:
		printf("�������� �ʴ� �������Դϴ�.\n");
		break;
	}
	printf("%d %c %d = %d\n", x, op, y, result);
}