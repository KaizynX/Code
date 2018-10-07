#include <cstdio>
#include <iostream>

using namespace std;

int n, p;

void ex_gcd(int a, int b, int &x, int &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	ex_gcd(b, a%b, y, x);
	y -= a/b*x;
}

inline int mul_inverse(int i)
{
	int x, y;
	// i*x + p*y = gcd(i, p) = 1
	ex_gcd(i, p, x, y);
	return (x%p+p)%p;
}

void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

int main()
{
	scanf("%d%d", &n, &p);
	for(int i = 1; i <= n; ++i)
		write(mul_inverse(i)), putchar('\n');
	return 0;
}
