// 구구단 출력 프로그램

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main() 
{
	int i = 1;

loop:
	printf("%d * %d = %d\n", 3, i, 3 * i);
	i++;
	if (i == 10)
		goto end;
	goto loop;
end:
	;
}
