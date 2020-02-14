#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;

int n, m;
vector<int> cnt;
vector<vector<int>> a;

pair<int, int> pos(int v)
{
    if (v < 1 || v > n*m) return {-1, -1};
    --v;
    int x = v/m, y = v%m;
    return {x, y};
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    a = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    int res = 0;
    for (int j = 0, tmp; j < m; ++j) {
        vector<int>(n, 0).swap(cnt);
        tmp = n;
        for (int i = 0; i < n; ++i) {
            pair<int, int> p = pos(a[i][j]);
            if (p.second == j)
                ++cnt[(i-p.first+n)%n];
        }
        for (int i = 0; i < n; ++i)
            tmp = min(tmp, i+n-cnt[i]);
#ifdef DEBUG
        for (int i = 0; i < n; ++i)
            cout << i << " " << cnt[i] << endl;
        cout << tmp << "****\n";
#endif
        res += tmp;
    }
    cout << res << endl;
    return 0;
}
