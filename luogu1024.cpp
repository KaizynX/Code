#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

double a, b, c, d;
// ax^3 + bx^2 + cx + d = 0

int main()
{
	cin >> a >> b >> c >> d;
	for(double i = -100.00, j; i <= 100.00; i += 0.001)
	{
		j = i + 0.001;
		double pre = i*i*i*a + i*i*b + i*c + d;
		double nex = j*j*j*a + j*j*b + j*c + d;
		if(pre <= 0 && nex >= 0 || pre >= 0 && nex <= 0)
		{
			printf("%.2f ",(i+j)/2);
			i += 0.999;
		}
	}
	return 0;
}
