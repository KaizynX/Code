#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, k;
int vis[N];
long long b[N], c[N];
vector<int> p[2][2], res;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        c[i] = b[i];
        int bit = static_cast<int>(b[i]&1);
        if (bit) p[0][1].push_back(i);
        else p[0][0].push_back(i), c[i] >>= 1;
    }
    k = p[0][1].size();
    res.assign(p[0][1].begin(), p[0][1].end());

    int cur = 0;
    while (p[cur][0].size()) {
        p[cur^1][0].clear();
        p[cur^1][1].clear();

        for (int i : p[cur][0]) {
            if (c[i]&1) p[cur^1][1].push_back(i);
            else p[cur^1][0].push_back(i), c[i] >>= 1;
        }
        if (p[cur^1][1].size() > k) {
            k = p[cur^1][1].size();
            res.assign(p[cur^1][1].begin(), p[cur^1][1].end());
        }
        cur ^= 1;
    }
    cout << n-k << endl;
    for (int i : res) {
        vis[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}
