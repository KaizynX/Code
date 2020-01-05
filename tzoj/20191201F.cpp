#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int T = 2e1+7;
const int d[] = { 0, -1, 0, 1, 0 };

int t, n;
int a[T][N][N], vis[T][N][N];
pair<int, int> s[T], p[T];
queue<pair<int, int> > q;

inline void clear(queue<pair<int, int> > &tar) {
    queue<pair<int, int> > tmp;
    swap(tmp, tar);
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t >> n;
    char c;
    for (int k = 1; k <= t; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> c;
                if (c == '#') a[k][i][j] = 0;
                else {
                    a[k][i][j] = 1;
                    if (c == 'S') s[k] = {i, j};
                    if (c == 'P' || c == 'B') p[k] = {i, j};
                }
            }
        }
    }
    for (int k = 1, x, y, nx, ny, flag; k <= t; ++k) {
        clear(q);
        q.push(s[k]);
        vis[k][s[k].first][s[k].second] = 1;
        flag = 0;
        while (q.size()) {
            pair<int, int> cur = q.front();
            q.pop();
            x = cur.first; y = cur.second;
            for (int dd = 0; dd < 4; ++dd) {
                nx = x+d[dd]; ny = y+d[dd+1];
                if (nx < 1 || ny < 1 || nx > n || ny > n
                    || !a[k][nx][ny] || vis[k][nx][ny]) continue;
                if (make_pair(nx, ny) == p[k]) { flag = 1; break; }
                vis[k][nx][ny] = 1;
                q.push({nx, ny});
            }
        }
        if (!flag) {
            cout << k << endl
                 << "sorry, my love!" << endl;
            return 0;
        }
    }
    cout << t << endl
         << "oh, no!" << endl;
    return 0;
}
