#include <iostream>
#include <cstring>

using namespace std;

const int Maxn = 100 + 7;
const int v[5][5] = {
{5,-1,-2,-1,-3}
{-1,5,-3,-2,-4}
{-2,-3,5,-2,-2}
{-1,-2,-2,5,-1}
{-3,-4,-2,-1,0}}

int na, nb;
string a, b;
int f[Maxn][Maxn*2];
// f[i][p] the i'th char in str_b at p'th pos in str_a get the max value
int t[128]; 

inline void init();
inline int get_v(int i, int p);
inline int max();

int main()
{
	cin >> na >> a >> nb >> b;
	init();
	for(int i = 0; i < nb; ++i)
	{
		for(int p = i; p < na*2; ++p)
		{
			f[i][p] = get_v(i,p);
			for(int j = 0; j < p; ++j)
			{
				f[i][p] = max(f[i][p],f[i-1][j] + get_v(i,p));
			}
		}
	}
	return 0
}

inline void init()
{
	t['A'] = 0;
	t['C'] = 1;
	t['G'] = 2;
	t['T'] = 3;
	t['-'] = 4;
}

inline int get_v(int i,int p)
{
	return v[ a[p] ][ b[i] ];
}

inline int max(int x, int y)
{
	return x > y ? x : y;
}
