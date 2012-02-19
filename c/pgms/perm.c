#include<stdio.h>
#include<string.h>

char a[] = "abcdefghijkl";

void swap(int p, int q)
{
	char temp;
	temp = a[p];
	a[p] = a[q];
	a[q] = temp;
}

void perm(int p, int q)
{
	int i;
	if(p == q)
		printf("%s\n", a);
	else {
		for(i = p; i <= q; i++) {
			swap(p, i);
			perm(p+1, q);
			swap(p, i);
		}
	}
}

main()
{
	perm(0, strlen(a) -1);
}
