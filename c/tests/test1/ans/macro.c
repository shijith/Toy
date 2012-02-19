#include<stdio.h>

#define offset_of(X,Y)	(int )&((X *)0) -> Y

struct foo {
	int m, k;
	int t;
	int x, y;
};
main()
{
	printf("m -> %d\n", offset_of(struct foo, m));
	printf("k -> %d\n", offset_of(struct foo, k));
	printf("t -> %d\n", offset_of(struct foo, t));
	printf("x -> %d\n", offset_of(struct foo, x));
	printf("y -> %d\n", offset_of(struct foo, y));
}

