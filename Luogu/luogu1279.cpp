#include <cstdio>
#include <cstring>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 2e3+7;

int k;
string A, B;
int f[Maxn][Maxn];

inline int abs(int x)
{
	return x < 0 ? -x : x;
}

int main()
{
	cin >> A >> B >> k;
	for(int i = 1; i <= A.length(); ++i) f[i][0] = k*i;
	for(int i = 1; i <= B.length(); ++i) f[0][i] = k*i;
	for(int i = 1; i <= A.length(); ++i)
		for(int j = 1; j <= B.length(); ++j)
		{
			f[i][j] = min(f[i-1][j]+k, f[i][j-1]+k);
			f[i][j] = min(f[i][j], f[i-1][j-1]+abs(A[i-1]-B[j-1]));
#ifdef DEBUG
			printf("%d %d %d\n", i, j, f[i][j]);
#endif
		}
	printf("%d\n", f[A.length()][B.length()]);
	return 0;
}
