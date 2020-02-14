#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int d[] = {0,1,0,-1,0};

int n, m;
char mp[N][N];
bool vis[N][N][4];

struct Node
{
    int x, y, s;
};

inline bool bfs()
{
    memset(vis, 0, sizeof vis);
    queue<Node> q;
    q.push({1,0,0});
    Node u, v;
    while (q.size()) {
        u = q.front();
        q.pop();
#ifdef DEBUG
        printf("%d %d %d\n", u.x, u.y, u.s);
#endif
        if (u.x == n && u.y == m) return true;
        for (int i = 0; i < 4; ++i) {
            v.x = u.x+d[i];
            v.y = u.y+d[i+1];
            v.s = u.s;
            if (v.x < 1 || v.y < 1 || v.x > n || v.y > m || mp[v.x][v.y] == '*') continue;
            char nc = mp[v.x][v.y];
            if (nc >= '3' && nc <= '4') v.s += 1<<(nc-'3');
            if (nc >= '1' && nc <= '2' && !((v.s>>(nc-'1'))&1)) continue;
            if (vis[v.x][v.y][v.s]) continue;
            vis[v.x][v.y][v.s] = 1;
            q.push(v);
        }
    }
    return false;
}

int main()
{
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 1; i <= n; ++i)
            scanf("%s", mp[i]+1);
        puts((bfs() ? "YES" : "NO"));
    }
    return 0;
}
