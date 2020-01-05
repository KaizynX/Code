#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e1+7;

int n;
int a[3], b[N], p[N];
pair<int, int> res;

struct Node
{
    int v[3], t;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.t < n2.t;
    }
    friend istream &operator >> (istream &is, Node &node) {
        return is >> node.v >> node.t;
    }
} c[N];

void solve(int cur)
{
    if (cur >= n) {
        pair<int, int> tmp = make_pair(0, 0);
        for (int i = 0; i < 3; ++i) b[i] = a[i];
        for (int i = 0; i < n; ++i) {
            if (b[p[i]] < c[i].v[p[i]]) continue;
            b[p[i]] -= v[i][p[i]];
            ++tmp.first;
            tmp.second = tmp.second*2-t[i][p[i]];
        }
        res = max(res, tmp);
#ifdef DEBUG
        for (int i = 0; i < n; ++i)
            cout << "-" << p[i];
        cout << " " << tmp.first << " " << -tmp.second << endl;
#endif
        return;
    }
    for (int i = 0; i < 3; ++i) {
        p[cur] = i;
        solve(cur+1);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < 3; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j)
            cin >> c[i];
    }
    sort(c, c+n);
    solve(0);
    cout << res.first << " " << -res.second << endl;
    return 0;
}
