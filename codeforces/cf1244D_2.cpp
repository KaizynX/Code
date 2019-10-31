#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e5+7;
const long long INF = 1e18;

int n;
int a[N], c[N][3], col[N], p[3];
vector<int> e[N];

int main()
{
    cin >> n;
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> c[j][i];
        }
    }
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int st;
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() > 2) {
            cout << -1 << endl;
            return 0;
        }
        if (e[i].size() == 1)
            st = i;
    }
    for (int i = 0, cur = st, last = 0; i < n; ++i) {
        a[i] = cur;
        int tmp = cur;
        cur = (e[cur][0] == last ? e[cur][1] : e[cur][0]);
        last = tmp;
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i)
        cout << a[i] << " \n"[i==n-1];
#endif
    
    long long res = INF, tmp;
    for (int i = 0; i < 3; ++i) p[i] = i;
    do {
        tmp = 0;
        for (int i = 0; i < n; ++i)
            tmp += c[a[i]][p[i%3]];
        if (tmp < res) {
            res = tmp;
            for (int i = 0; i < 3; ++i)
                col[a[i]] = p[i]+1;
        }
    } while (next_permutation(p, p+3));
    cout << res << endl;
    for (int i = 3; i < n; ++i) 
        col[a[i]] = col[a[i%3]];
    for (int i = 1; i <= n; ++i)
        cout << col[i] << " \n"[i==n];
    return 0;
}
