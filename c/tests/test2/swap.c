#include<stdio.h>
void swap(int a, int b)
{
	int t;
	t = *(&a+6);
	*(&a+6) = *(&a+7);
	*(&a+7) = t;

}

main()
{
	int a = 10, b = 20;

	swap(a, b);

	printf("%d\n%d\n", a, b);
}

