/*
 * @Author: Kaizyn
 * @Date: 2020-05-05 22:49:45
 * @LastEditTime: 2020-05-05 23:28:01
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m;
unsigned X, Y, Z;
multiset<int> st;
vector<int> add[N], del[N];

inline unsigned RNG61() {
    static unsigned W;
    X = X^(X<<11);
    X = X^(X>>4);
    X = X^(X<<5);
    X = X^(X>>14);
    W = X^(Y^Z);
    X = Y;
    Y = Z;
    Z = W;
    return Z;
}

inline void solve()
{
    cin >> n >> m >> X >> Y >> Z;
    for (int i = 1, l, r, v; i <= m; ++i) {
        l = RNG61()%n+1;
        r = RNG61()%n+1;
        v = RNG61()%(1<<30);
        if (l > r) swap(l, r);
        add[l].emplace_back(v);
        del[r+1].emplace_back(v);
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        for (const int &v : del[i]) st.erase(st.find(v));
        for (const int &v : add[i]) st.insert(v);
        if (st.size()) res ^= *st.rbegin()*1ll*i;
    }
    cout << res << endl;

    multiset<int>().swap(st);
    for (int i = 1; i <= n+1; ++i) {
        vector<int>().swap(add[i]);
        vector<int>().swap(del[i]);
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}