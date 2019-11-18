#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int K = 15;

int n;
int a[2][N], cnt[2][N][1<<K];
map<vector<int>, int> mp;

inline int count(int x) {
    int res = 0;
    for ( ; x; x >>= 1) res += x&1;
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[1][i];
        a[0][i] = a[1][i]&((1<<K)-1);
        a[1][i] >>= K;
        for (int j = 0; j < (1<<K); ++j) {
            cnt[0][i][j] = count(a[0][i]^j);
            cnt[1][i][j] = count(a[1][i]^j);
        }
    }
    vector<int> tmp;
    for (int j = 0; j < (1<<K); ++j) {
        tmp.resize(n, 0);
        for (int i = 0; i < n; ++i)
            tmp[i] = cnt[0][i][j];
        mp.insert({tmp, j});
    }
    for (int k = 0; k <= 30; ++k) {
        for (int j = 0; j < (1<<K); ++j) {
            tmp.resize(n, 0);
            for (int i = 0; i < n; ++i)
                tmp[i] = k-cnt[1][i][j];
            if (mp.count(tmp)) {
                cout << (j<<K)+mp[tmp] << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
