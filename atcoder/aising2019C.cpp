#include <bits/stdc++.h>

using namespace std;

const int Maxn = 407;
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

int h, w;
long long ans, cnt[2];
int a[Maxn][Maxn], vis[Maxn][Maxn];

inline void dfs(int x, int y)
{
    cnt[a[x][y]]++;
    vis[x][y] = 1;
    for(int i = 0, nx, ny; i < 4; ++i)
    {
        nx = x+dx[i]; ny = y+dy[i];
        if(nx < 1 || ny < 1 || nx > h || ny > w
        || vis[nx][ny] || a[x][y] == a[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main()
{
    cin >> h >> w;
    for(int i = 1; i <= h; ++i)
    {
        char c;
        for(int j = 1; j <= w; ++j)
        {
            cin >> c;
            if(c == '#') a[i][j] = 1;
            // else a[i][j] = 0;
        }
    }

    for(int i = 1; i <= h; ++i)
    {
        for(int j = 1; j <= w; ++j)
        {
            if(!vis[i][j])
            {
                cnt[0] = cnt[1] = 0;
                dfs(i, j);
                ans += cnt[0]*cnt[1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
