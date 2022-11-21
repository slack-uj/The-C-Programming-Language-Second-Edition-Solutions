
/* reverse: reverse string s in place */
#include<string.h>
void reverse(char s[])
{
	int c,i,j;
	for(i=0,j=strlen(s) - 1;i<j;i++,j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
#include<ctype.h>
/* atoi: convert s to integer */
int atoi(char s[])
{
	int i,n,sign;

	for (i=0;isspace(s[i]);i++) /* skip white space */
		;
	sign = (s[i] == '-')? -1 : 1;
	if (s[i] == '+' || s[i] == '-') /* skip sign */
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}

/* itoa: convert n to characters in s */
#define max 64
void itoa(int n,char s[])
{
	int i,sign;

	if ((sign = n) < 0) /*record sign */
		n = -n;	/* make n positive */
	i=0;
	do
	{
		/*generate digits in reverse order */
		s[i++] = n%10 + '0'; /* get next digit */
	}
	while ((n /= 10) > 0); /* delete it */
	s[i] = '\0';
	reverse(s);
}
