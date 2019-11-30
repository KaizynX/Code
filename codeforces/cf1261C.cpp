#include <bits/stdc++.h>

using namespace std;

const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int n, m;
vector<vector<int>> a, sum, res, vis;

inline bool check(int mid)
{
    res = vector<vector<int>>(n+1, vector<int>(m+1, 0));
    vis = vector<vector<int>>(n+1, vector<int>(m+1, 0));
    long long need = (2*mid+1ll)*(2*mid+1ll);
    queue<pair<int,int>> q;
    for (int i = mid+1; i+mid <= n; ++i) {
        for (int j = mid+1; j+mid <= m; ++j) {
            if (sum[i+mid][j+mid]+sum[i-mid-1][j-mid-1]-sum[i+mid][j-mid-1]-sum[i-mid-1][j+mid]
                == need) {
                res[i][j] = 1;
                vis[i][j] = mid+1;
                q.push({i, j});
            }
        }
    }
    while (q.size()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        if (vis[x][y] <= 1) continue;
        for (int i = 0, nx, ny; i < 8; ++i) {
            nx = x+dx[i];
            ny = y+dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (vis[nx][ny] >= vis[x][y]-1) continue;
            vis[nx][ny] = vis[x][y]-1;
            q.push({nx, ny});
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if ((a[i][j] && !vis[i][j]) || (!a[i][j] && vis[i][j]))
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    a = vector<vector<int>>(n+1, vector<int>(m+1));
    sum = vector<vector<int>>(n+1, vector<int>(m+1));
    string str;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        for (int j = 0; j < m; ++j)
            a[i][j+1] = str[j] == 'X' ? 1 : 0;
        for (int j = 1; j <= m; ++j)
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    }

    int l = 0, r = min(n, m);
    while (l < r) {
        int mid = (l+r+1)>>1;
        if (check(mid)) l = mid;
        else r = mid-1;
    }

    cout << l << endl;
    check(l);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cout << (res[i][j] ? 'X' : '.');
        cout << endl;
    }
    return 0;
}
