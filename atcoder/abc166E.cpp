/*
 * @Author: Kaizyn
 * @Date: 2020-05-07 10:34:34
 * @LastEditTime: 2020-05-07 11:50:13
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
int a[N];
map<int, int> cnt;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        res += cnt[-(a[i]-i)];
        ++cnt[a[i]+i];
    }
    cout << res << endl;
    return 0;
}