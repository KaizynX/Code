#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e2+7;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};

int n, mina = 120, maxa = 0;
int a[Maxn][Maxn];
int vis[Maxn][Maxn];

bool bfs(int dif)
{
    typedef pair<int, int> pr;
    // [l, r r-l == dif
    for(int l = mina; l+dif <= maxa; ++l)
    {
        int r = l+dif;
        if(a[1][1] < l || a[1][1] > r || a[n][n] < l || a[n][n] > r) continue;
        queue<pr> q;
        memset(vis, 0, sizeof vis);
        q.push(make_pair(1, 1));
        while(q.size())
        {
            pr cur = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i)
            {
                int nx = cur.first+dx[i];
                int ny = cur.second+dy[i];
                if(nx < 1 || nx > n || ny <1 || ny > n) continue;
                if(a[nx][ny] < l || a[nx][ny] > r || vis[nx][ny]) continue;
                if(nx == n && ny == n) return true;
                vis[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return false;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            mina = min(mina, a[i][j]);
            maxa = max(maxa, a[i][j]);
        }
    int l = abs(a[1][1]-a[n][n]), r = maxa-mina;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(bfs(mid)) r = mid;
        else l = mid+1;
    }
    cout << l << endl;
    return 0;
}