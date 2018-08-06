#include<stdio.h>
void main()
{
int a[] = { 6, 6, 4, 3, 2 };
int b[] = { 8, 6, 2, 3, 1 };
	int i = 0;
	for (i = 0; i <= 4; i++)
	{
	int	tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	
	}
	for (i = 0; i <= 4; i++)
	{
		printf("%d\n", a[i]);
	}
	for (i = 0; i <= 4; i++)
	{
		printf("%d\n",b[i] );
	}
	return  0;
}