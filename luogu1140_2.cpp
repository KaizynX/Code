#include <iostream>
#include <cstring>

using namespace std;

const int Maxn = 100 + 7;
const int v[5][5] = {
{5,-1,-2,-1,-3},
{-1,5,-3,-2,-4},
{-2,-3,5,-2,-2},
{-1,-2,-2,5,-1},
{-3,-4,-2,-1,0} };

int na, nb, a[Maxn], b[Maxn];
int f[Maxn][Maxn];
// f[i][j] a[i] match with b[j]

inline int query(char);

int main()
{
	string A, B;
	cin >> na >> A >> nb >> B;
	for(int i = 1; i <= na; ++i)
	{
		a[i] = query(A[i-1]);
		f[i][0] = f[i-1][0] + v[a[i]][4];
	}
	for(int i = 1; i <= nb; ++i)
	{
		b[i] = query(B[i-1]);
		f[0][i] = f[0][i-1] + v[4][b[i]];
	}
	for(int i = 1; i <= na; ++i)
	{
		for(int j = 1; j <= nb; ++j)
		{
			f[i][j] = max( f[i-1][j-1]+v[a[i]][b[j]], 
						  max(f[i][j-1]+v[4][b[j]], f[i-1][j]+v[a[i]][4]) );
		}
	}
	cout << f[na][nb] << endl;
	return 0;
}

inline int query(char c)
{
	/*
	switch (c)
	{
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
		case '-': return 4;
	}
	return -1; // ???
	*/
	if(c == 'A') return 0;
	else if(c == 'C') return 1;
	else if(c == 'G') return 2;
	else if(c == 'T') return 3;
}
