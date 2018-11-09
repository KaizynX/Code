#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 15;
const int INF = 0x3f3f3f3f;

int n, m, V = -1, flagV = 1, ans = INF;
int d[Maxn], e[Maxn][Maxn];

void brute(int cur, int val)
{
    if(cur > n)
    {
        ans = min(ans, val);
#ifdef DEBUG
        for(int i = 1; i <= n; ++i)
            printf("%d ", d[i]);
        printf("  %d\n", val);
#endif
        return;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(d[i] == -1)
        {
            // search for the closest way
            int minv = INF, mini = -1;
            for(int j = 1; j <= n; ++j)
            {
                // j to i is avaliable
                if(d[j] != -1 && e[j][i] != -1)
                {
                    if((d[j]+1)*e[j][i] < minv)
                    {
                        minv = (d[j]+1)*e[j][i];
                        mini = j;
                    }
                }
            }
            if(mini != -1)
            {
                d[i] = d[mini]+1;
                brute(cur+1, val+minv);
                d[i] = -1;
            }
        }
    }
}

inline void solve1() // 40, if v is same
{
    for(int S = 1; S <= n; ++S)
    {
        // bfs
        queue<int> q;
        int sumd = 0;
        memset(d, -1, sizeof d);
        q.push(S);
        d[S] = 0;
        while(q.size())
        {
            int cur = q.front();
            q.pop();
            for(int i = 1; i <= n; ++i)
                if(d[i] == -1 && e[cur][i])
                    sumd += (d[i] = d[cur]+1);
        }
        ans = min(ans, sumd*V);
    }
}

inline void solve2() // 70???
{
    for(int i = 1; i <= n; ++i)
    {
        d[i] = 0;
        brute(2, 0);
        d[i] = -1;
    }
}

inline void solve3()
{
    solve2(); // emmmm
}

int main()
{
    memset(e, -1, sizeof e);
    memset(d, -1, sizeof d);
    scanf("%d%d", &n, &m);
    for(int i = 1, x, y, v; i <= m; ++i)
    {
        scanf("%d%d%d", &x, &y, &v);
        if(e[x][y] == -1) e[x][y] = v;
        else e[x][y] = min(e[x][y], v);
        if(e[y][x] == -1) e[y][x] = v;
        else e[y][x] = min(e[y][x], v);
        if(flagV)
        {
            if(V == -1) V =v;
            if(V != v) flagV = 0;
        }
    }
    if(flagV) solve1();
    else if(n <= 8) solve2();
    else solve3();
    printf("%d\n", ans);
    return 0;
}
