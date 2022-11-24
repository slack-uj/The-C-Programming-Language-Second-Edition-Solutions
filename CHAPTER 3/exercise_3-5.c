/*
 * Write the function itob(n,s,b) that converts the integer n into a base b 
 * character representation in the string s.In particular,itob(n,s,16) formats
 * n as a hexadecimal integer in s.
 */

#include<stdio.h>
#include"../mylibrary/mychar.h" /*header file containing reverse function*/
#define abs(n) (n > 0 ? n : -n)

void itob(int n,char s[],int b)
{
	int sign = n;
	int bn[32];
	int i;

	for(i=31;i>=0;--i)
	{
		bn[i] = abs(n%2);
		n/=2;
	}
	if (sign < 0)
	{
		for(i = 0;i<32;++i)
		{
			bn[i] = !bn[i];
		}
	}
	int group;

	if (b == 2) group=1;
	else if(b == 8) group=3;
	else if(b == 16) group=4;

	i=31;
	int a = 0;
	while(i>=0)
	{
		int sum=0,base=1;
		for(int j=0;j<group && i>=0;++j)
		{
			sum = bn[i--] * base + sum;
			base = base * 2;
		}
		if (sum < 10)
			s[a++]=sum+'0';
		else
			switch(sum)
			{
				case 10: s[a++]='A';
					 break;
				case 11: s[a++]='B';
					 break;
				case 12: s[a++]='C';
					 break;
				case 13: s[a++]='D';
					 break;
				case 14: s[a++]='E';
					 break;
				case 15: s[a++]='F';
					 break;
			}
	}
	reverse(s);
}

int main(void)
{
	int n,b;
	char s[max];

	printf("Enter any integer:");
	scanf("%d",&n);
	printf("Enter the base for conversion:");
	scanf("%d",&b);

	itob(n,s,b);

	printf("The representation of %d in %d base is: %s\n",n,b,s);
}
