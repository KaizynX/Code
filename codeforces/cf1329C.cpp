/*
 * @Author: Kaizyn
 * @Date: 2020-04-04 00:27:58
 * @LastEditTime: 2020-04-04 23:56:46
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = (1<<21)+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int h, g;
int a[N];
vector<int> res;

int get_val(const int &i)
{
    if (i >= h || !a[i]) return 0;
    int v = get_val(i<<1|(a[i<<1] < a[i<<1|1]));
    if (!v && i < g) return 0;
    swap(v, a[i]);
    return v;
}

void f(const int &i)
{
    if (i >= g) return;
    while (get_val(i)) {
        res.emplace_back(i);
        #ifdef DEBUG
        for (int j = 1; j < h; ++j) cout << a[j] << " \n"[j==h-1];
        #endif
    }
    f(i<<1);
    f(i<<1|1);
}

inline void solve()
{
    res.clear();
    cin >> h >> g;
    h = (1<<h);
    g = (1<<g);
    for (int i = 1; i < h; ++i) cin >> a[i];
    f(1);
    long long sum = 0;
    for (int i = 1; i < g; ++i) sum += a[i];
    cout << sum << endl;
    for (int i : res) cout << i << " ";
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