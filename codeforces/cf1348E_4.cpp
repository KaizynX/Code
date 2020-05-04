/*
 * @Author: Kaizyn
 * @Date: 2020-05-02 11:13:45
 * @LastEditTime: 2020-05-02 11:19:59
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

int n, k;
int a[N], b[N];
int f[N];

inline long long solve()
{
    cin >> n >> k;
    long long suma = 0, sumb = 0, cnt;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    for (int i = 1; i <= n; ++i) {
        suma += a[i];
        sumb += b[i];
        for (int aa = 1, bb; aa < k && aa <= a[i]; ++aa) {
            bb = k-aa;
            if (bb > b[i]) continue;
            f[aa] = 1;
        }
    }
    cnt = suma/k+sumb/k;
    if (cnt == (suma+sumb)/k) return cnt;
    suma %= k; sumb %= k;
    for (int aa = 1, bb; aa < k && aa <= suma; ++aa) {
        bb = k-aa;
        if (bb > sumb || !f[aa]) continue;
        return ++cnt;
    }
    return cnt;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << solve() << endl;
    }
    return 0;
}