// 간단한 산술 계산기 프로그램

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{

	char op;
	int x, y, result;

	printf("수식을 입력하시오\n(예: 2 + 5)\n>> ");
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
		printf("지원되지 않는 연산자입니다.\n");
		break;
	}
	printf("%d %c %d = %d\n", x, op, y, result);
}