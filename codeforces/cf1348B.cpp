/*
 * @Author: Kaizyn
 * @Date: 2020-05-01 22:31:58
 * @LastEditTime: 2020-05-01 23:17:01
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e4+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, k, m;
int a[N], b[N];
map<int, int> mp;
vector<int> v;

inline void solve()
{
    cin >> n >> k;
    mp.clear();
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    if ((int)mp.size() > k) return void(cout << -1 << endl);
    vector<int>().swap(v);
    for (const auto &p : mp) v.emplace_back(p.first);
    while ((int)v.size() < k) v.emplace_back(mp.begin()->first);
    cout << n*k << endl;
    for (int i = 1; i <= n; ++i) {
        for (const int &j : v) {
            cout << j << " ";
        }
    }
    cout << endl;
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