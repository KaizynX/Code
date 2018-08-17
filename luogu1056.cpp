#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e3+7;

int N, M, K, L, D;
int tmp[Maxn];
struct Node
{
	int v, num;
	bool operator < (const Node &b) const
	{
		return v > b.v;
	}
} k[Maxn], l[Maxn];

int main()
{
	scanf("%d%d%d%d%d", &M, &N, &K, &L, &D);
	for(int i = 1; i <= M; ++i) k[i].num = i;
	for(int i = 1; i <= N; ++i) l[i].num = i;
	for(int i = 0, x_1, x_2, y_1, y_2; i < D; ++i)
	{
		scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
		if     (x_1 == x_2) l[min(y_1, y_2)].v++;
		else if(y_1 == y_2) k[min(x_1, x_2)].v++;
	}
	sort(l+1, l+N+1);
	sort(k+1, k+M+1);
	for(int i = 1; i <= K; ++i) tmp[i] = k[i].num;
	sort(tmp+1, tmp+K+1);
	for(int i = 1; i < K; ++i) printf("%d ", tmp[i]);
	printf("%d\n", tmp[K]);
	for(int i = 1; i <= L; ++i) tmp[i] = l[i].num;
	sort(tmp+1, tmp+L+1);
	for(int i = 1; i < L; ++i) printf("%d ", tmp[i]);
	printf("%d\n", tmp[L]);
	return 0;
}
