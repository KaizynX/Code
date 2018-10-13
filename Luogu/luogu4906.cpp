#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 25;

int n, ans = -1;
int a[Maxn][Maxn], b[Maxn][Maxn];
int now[Maxn];

void solve(int cur, int cnt)
{
    if(cur > n)
    {
        int flag = 1;
        for(int i = 1; i <= n; ++i)
            if(now[i] == 0) flag = 0;
        if(flag)
        {
            if(ans == -1 || cnt < ans)
                ans = cnt;
        }
        return;
    }
    // not choose
    solve(cur+1, cnt);
    // choose
    for(int i = 1; i <= n; ++i)
        now[i] ^= b[cur][i];
    solve(cur+1, cnt+1);
    for(int i = 1; i <= n; ++i)
        now[i] ^= b[cur][i];
}

int main()
{
    scanf("%d", &n);
    for(int i = 1, m, tmp; i <= n; ++i)
    {
        scanf("%d", &m);
        for(int j = 1; j <= m; ++j)
        {
            scanf("%d", &tmp);
            a[i][tmp] = 1;
        }
    }
    // init
    for(int i = 1; i <= n; ++i)
    {
        b[i][i] ^= 1;
        for(int j = 1; j <= n; ++j)
		{
            if(a[i][j] && i != j) // i relate to j
			{
				b[i][j] ^= 1;
                for(int k = 1; k <= n; ++k)
                    if(a[j][k] && k != j)
						b[i][k] ^= 1;
			}
		}
    }

    solve(1, 0);
    if(ans == -1) puts("Change an alarm clock£¬please!");
    else printf("%d\n", ans);
    return 0;
}
