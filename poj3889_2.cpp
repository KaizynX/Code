#include <iostream>
#include <cstdio>
#include <cmath>

#define DEBUG

using namespace std;

inline int getint();
inline double cal_dis(int h_x, int h_y, int o_x, int o_y)
{
	return sqrt((double( (long long)(h_x-o_x)*(h_x-o_x) + (long long)(h_y-o_y)*(h_y-o_y) )*100));
}

inline void getpos(int n,int a,int &x,int &y,int angle)
{
	// cur ==> the first number of the area
	// num ==> number of every four block
	// (x,y) ==> pos of cur
	// edge : 1<<n * 1<<n

	/******************************
	 * angle == 0   90   180  270 *
	 *         1-2  1 4  3-4  3-2 *
	 *           |  | |  |    | | *
	 *         4-3  2-3  2-1  4 1 *
	 *****************************/
	x = 1; y = 1;
	for(int i = n, cur = 1,num; i; --i)
	{
		num = (1<<(i-1)) * (1<<(i-1));

		if(a <= cur + num -1)
		{
			if(angle == 0) angle = 270;
			else if(angle == 90) angle = 0;
			else if(angle == 180) ;
			else ;
		}
		else if( a <= cur + num*2 -1) // right up
		{
			cur += num;
			x += 1 << (i-1);
		}
		else if( a <= cur + num*3 -1) // right down
		{
			cur += num * 3;
			x += 1 << (i-1);
			y += 1 << (i-1);
		}
		else // left down
		{
			cur += num * 2;
			y += 1 << (i-1);
		}
	}
}

int main()
{
	int n, h, o;
	int h_x,h_y,o_x,o_y;
	int T = getint();
	while(T--)
	{
		// n < 16   h,o < 2^31 = 1<<31
		n = getint(); h = getint(); o = getint();
		getpos(n,h,h_x,h_y,0);
		getpos(n,o,o_x,o_y,0);
#ifdef DEBUG
		printf("%d %d %d %d\n",h_x,h_y,o_x,o_y);
#endif
		printf("%.0f\n",cal_dis(h_x,h_y,o_x,o_y));
	}
	return 0;
}

inline int getint()
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	int res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	return res;
}

