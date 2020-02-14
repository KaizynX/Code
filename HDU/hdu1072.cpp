#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 100;

int T, n, m, k;
int a[N], d[N][N];

inline void update(int &x, const int y) { if (x == -1 || x > y) x = y; }

inline void dfs(int ori, int cur, int time)
{
    if (time > 5 || !a[cur]) return;
    if (d[ori][cur] != -1 && d[ori][cur] < time) return;
    d[ori][cur] = time;
    if (cur%m) dfs(ori, cur-1, time+1);
    if (cur%m < m-1) dfs(ori, cur+1, time+1);
    if (cur/m) dfs(ori, cur-m, time+1);
    if (cur/m < n-1) dfs(ori, cur+m, time+1);
}

#ifdef DEBUG
inline void print()
{
    puts("***********");
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (d[i][j] == -1) continue;
            int ix = i/m, iy = i%m,
                jx = j/m, jy = j%m;
            printf("(%d, %d)->(%d, %d) = %d\n", ix, iy, jx, jy, d[i][j]);
        }
    }
    puts("***********");
}
#endif

inline void solve()
{
    int s, t;
    scanf("%d %d", &n, &m);
    k = n*m;
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < k; ++j)
            d[i][j] = -1;
    for (int i = 0; i < k; ++i) {
        scanf("%d", a+i);
        if (a[i] == 2) s = i;
        if (a[i] == 3) t = i;
    }
    for (int i = 0; i < k; ++i)
        if (a[i] == 2 || a[i] == 4)
            dfs(i, i, 0);
#ifdef DEBUG
    print();
#endif
    // floyd
    for (int mid = 0; mid < k; ++mid)
    for (int i = 0; i < k; ++i)
    for (int j = 0; j < k; ++j)
        if (d[i][mid] != -1 && d[mid][j] != -1)
            update(d[i][j], d[i][mid]+d[mid][j]);
#ifdef DEBUG
    print();
#endif
    printf("%d\n", d[s][t]);
}

int main()
{
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}
