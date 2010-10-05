#include<stdio.h>
#include<stdarg.h>

void fun(int size, ...)
{
	va_list list;
	int n, i;

	va_start(list, size);

	for(i = 0; i < size; i++) {
		n = va_arg(list, int);
		
		if(n < 10000000)
			printf("%d\n", n);
		else
			printf("%s\n", (char *)n);
	
	}
	
	va_end(list);
}

main()
{
	fun(5, 23, 1, "A", "tesing arg ", 12324);
}
