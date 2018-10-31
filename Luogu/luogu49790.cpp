#include <cmath>
#include <cstdio>
#include <iostream>
#define DEBUG

using namespace std;

int T;
long long u, v, ux, uy, vx, vy, lu, lv;

inline long long calc_l(long long id)
{
	// l*(l+1)/2 >= v
	id <<= 1;
	long long l = (long long)sqrt(id);
	// this line not fit
	while(l*(l+1) < id) l++;
	// last line fit
	while(l*(l-1) >= id) l--;
	return l;
}

inline void getpos(long long l, long long id, long long &x, long long &y)
{
	y = id-l*(l-1)/2;
	x = l+1-y;
}

inline long long calc_dis(long long ux, long long uy, long long vx, long long vy)
{
	long long minx = min(ux, vx), miny = min(uy, vy), sta = minx+miny-1,
			  midu = sta+ux-minx, midv = sta+vx-minx,
			  tou = (sta+midu-1)*(ux-minx)/2 + (midu+midu+uy-miny-1)*(uy-miny)/2,
			  tov = (sta+midv-1)*(vx-minx)/2 + (midv+midv+vy-miny-1)*(vy-miny)/2;
#ifdef DEBUG
	printf("%I64d %I64d %I64d\n", sta, tou, tov);
#endif
	return tou+tov;
}

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> u >> v;
		lu = calc_l(u);
		lv = calc_l(v);
		getpos(lu, u, ux, uy);
		getpos(lv, v, vx, vy);
#ifdef DEBUG
		printf("u(%I64d,%I64d),lu=%I64d\nv(%I64d,%I64d),lv=%I64d\n", ux, uy, lu, vx, vy, lv);
#endif
		cout << calc_dis(ux, uy, vx, vy) << endl;
	}
	return 0;
}
