#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Maxn = 57;

int T, n, t;
int a[Maxn]; // a[i] <= 180 ==> t <= 9000
int song_time[9007], song_num[9007];

int main()
{
	scanf("%d", &T);
	for(int k = 1; k <= T; ++k)
	{
		memset(song_time, 0, sizeof song_time);
		memset(song_num, 0, sizeof song_num);
		scanf("%d%d", &n, &t);
		for(int i = 1; i <= n; ++i) scanf("%d", a+i);
		for(int i = 1; i <= n; ++i)
			for(int v = t-1; v >= a[i]; --v)
			{
				if(song_num[v-a[i]] + 1 > song_num[v])
				{
					song_num[v] = song_num[v-a[i]] + 1;
					song_time[v] = song_time[v-a[i]] + a[i];
				}
				else if(song_num[v-a[i]] + 1 == song_num[v])
					song_time[v] = max(song_time[v], song_time[v-a[i]]+a[i]);
			}
		printf("Case %d: %d %d\n", k, song_num[t-1]+1, song_time[t-1]+678);
	}
	return 0;
}
