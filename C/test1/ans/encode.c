#include <stdio.h>

void encode(int c, int a[])
{
	int i = 0,d;
	for(i = 0; i < 8; i++)
	{
		if((c)&1)
			a[i] |= 1;
		else
			a[i] &= ~1;
		c >>= 1;
	}
}

main()
{
	int i;
	int t = 0xaa;
	
	int m[] = {9, 8, 124, 277, 14, 16, 19, 23};

	encode(t, m);

	for(i = 0; i < 8; i++)
		printf("%d ", m[i]);
	printf("\n");

	// result: 8 9 124 277 14 17 18 23

        /*
         * What does `encode' do? Look at the binary pattern
         * for `t' - it is 10101010.
         * `encode' simply "spreads" the 8 bits of `t' over the
         * LSB's of the eight numbers stored in `m'. 
         */

}

