/*
 * @Author: Kaizyn
 * @Date: 2020-05-02 11:13:45
 * @LastEditTime: 2020-05-02 12:47:39
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
int f[2][N];

inline long long solve()
{
    cin >> n >> k;
    long long suma = 0, sumb = 0, cnt;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        suma += a[i];
        sumb += b[i];
        memcpy(f[i&1], f[~i&1], sizeof f[0]);
        // memset(f[i&1], 0, sizeof f[i&1]);
        for (int aa = 1, bb; aa < k && aa <= a[i]; ++aa) {
            bb = k-aa;
            if (bb > b[i]) continue;
            f[i&1][aa] = 1;
            for (int aaa = 0; aaa < k; ++aaa) {
                if (f[~i&1][aaa]) f[i&1][(aaa+aa)%k] = 1;
            }
        }
    }
    cnt = suma/k+sumb/k;
    if (cnt == (suma+sumb)/k) return cnt;
    suma %= k; sumb %= k;
    for (int aa = 1, bb; aa < k && aa <= suma; ++aa) {
        bb = k-aa;
        if (bb > sumb || !f[n&1][aa]) continue;
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