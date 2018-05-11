#include <iostream>
#include <cstdio>
#include <cmath>

#define DEBUG

using namespace std;

inline int getint();
inline double cal_dis(int h_x, int h_y, int o_x, int o_y)
{
	return sqrt((double( (h_x-o_x)*(h_x-o_x) + (h_y-o_y)*(h_y-o_y) )));
	/*
	int dis_2 = (h_x-o_x)*(h_x-o_x) + (h_y-o_y)*(h_y-o_y);
	double res = sqrt( static_cast<double>(dis_2) );
	double up = ceil(res), down = floor(res) ;
	// return the nearest integer
	return ( up - res < res - down) ? up : down;
	*/
}
inline void getpos(int n,int a,int &x,int &y)
{
	x = 1; y = 1;
	// cur ==> the number of left up point
	// num ==> number of every four block
	// (x,y) ==> pos of cur
	// 1<<n * 1<<n
	for(int i = n, cur = 1,num; i; --i)
	{
		num = (1<<(i-1)) * (1<<(i-1));
		if(a <= cur + num -1) ; // left up
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
		getpos(n,h,h_x,h_y);
		getpos(n,o,o_x,o_y);
#ifdef DEBUG
		printf("%d %d %d %d\n",h_x,h_y,o_x,o_y);
#endif
		printf("%.0f\n",cal_dis(h_x*10,h_y*10,o_x*10,o_y*10));
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
