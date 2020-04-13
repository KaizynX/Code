/*
 * @Author: Kaizyn
 * @Date: 2020-04-11 11:03:39
 * @LastEditTime: 2020-04-11 11:27:48
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

struct Node
{
    int pre, nex;
} col[N*N], row[N*N];

int n, m;
int a[N*N], vis[N*N];
queue<int> q[2];

inline int mp(const int &x, const int &y) {
    return x*(m+2)+y;
}

inline bool check(const int &x) {
    if (!a[x]) return false;
    int sum = 0, cnt = 0;
    if (a[row[x].pre]) sum += a[row[x].pre], ++cnt;
    if (a[row[x].nex]) sum += a[row[x].nex], ++cnt;
    if (a[col[x].pre]) sum += a[col[x].pre], ++cnt;
    if (a[col[x].nex]) sum += a[col[x].nex], ++cnt;
    return a[x]*cnt < sum;
}

inline void del(const int &x) {
    row[row[x].pre].nex = row[x].nex;
    row[row[x].nex].pre = row[x].pre;
    col[col[x].pre].nex = col[x].nex;
    col[col[x].nex].pre = col[x].pre;
}

long long solve()
{
    cin >> n >> m;
    long long res = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[mp(i, j)];
        }
    }
    queue<int>().swap(q[0]);
    queue<int>().swap(q[1]);
    for (int i = 1; i <= n; ++i) {
        a[mp(i, 0)] = a[mp(i, m+1)] = 0;
        vis[mp(i, 0)] = vis[mp(i, m+1)] = 1;
        row[mp(i, 0)].nex = mp(i, 1);
        row[mp(i, m+1)].pre = mp(i, m);
    }
    for (int i = 1; i <= m; ++i) {
        a[mp(0, i)] = a[mp(n+1, i)] = 0;
        vis[mp(0, i)] = vis[mp(n+1, i)] = 1;
        col[mp(0, i)].nex = mp(1, i);
        col[mp(n+1, i)].pre = mp(n, i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            vis[mp(i, j)] = 0;
            sum += a[mp(i, j)];
            row[mp(i, j)].pre = mp(i, j-1);
            row[mp(i, j)].nex = mp(i, j+1);
            col[mp(i, j)].pre = mp(i-1, j);
            col[mp(i, j)].nex = mp(i+1, j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (check(mp(i, j))) {
                q[0].push(mp(i, j));
                vis[mp(i, j)] = 1;
            }
        }
    }
    for (int i = 0; q[i&1].size(); ++i) {
        res += sum;
        queue<int>().swap(q[~i&1]);
        while (q[i&1].size()) {
            int x = q[i&1].front(), y;
            q[i&1].pop();
            del(x);
            sum -= a[x];
            y = row[x].pre;
            if (!vis[y] && check(y)) q[~i&1].push(y), vis[y] = 1;
            y = row[x].nex;
            if (!vis[y] && check(y)) q[~i&1].push(y), vis[y] = 1;
            y = col[x].pre;
            if (!vis[y] && check(y)) q[~i&1].push(y), vis[y] = 1;
            y = col[x].nex;
            if (!vis[y] && check(y)) q[~i&1].push(y), vis[y] = 1;
        }
    }
    return res+sum;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}