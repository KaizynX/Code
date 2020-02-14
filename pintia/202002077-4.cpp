#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, m, tot;
int vis[N], res[N];

int main()
{
    cin >> n;
    for (int i = 1, k; i <= n; ++i) {
        cin >> k;
        for (int j = 1, a; j <= k; ++j) {
            cin >> a;
            if (k > 1) res[a] = 1;
        }
    }
    cin >> m;
    int cnt = 0;
    for (int i = 1, x; i <= m; ++i) {
        cin >> x;
        if (res[x] || vis[x]) continue;
        if (cnt) cout << " ";
        ++cnt;
        printf("%05d", x);
        vis[x] = 1;
    }
    if (!cnt) cout << "No one is handsome" << endl;
    else cout << endl;
    return 0;
}
