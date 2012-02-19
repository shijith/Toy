#include<stdio.h>

void tower(int n, int l, int m, int r)
{
	if(n  > 0) {
		tower(n-1 , l, r, m);
		printf("%d %d\n",l, r);
		tower(n-1, m, l, r);
	}
}
main()
{
	int n = 2;
	tower(n, 1, 2, 3);
}
