/*
 * @Author: Kaizyn
 * @Date: 2020-03-14 18:45:15
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-14 18:45:15
 * @FilePath: \Code\HDU\hdu2827_2.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, MOD;
long long a[N][N];

template <typename T>
T exgcd(const T a, const T b, T &x, T &y)
{
    if (!b) { x = 1; y = 0; return a; }
    T d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

template <typename T>
inline T mul_inverse(const T &a, const T &mo = MOD)
{
    T x, y;
    exgcd(a, mo, x, y);
    return (x%mo+mo)%mo;
}

template <typename T>
T Determinant(T a[N][N], const int &n) {
    int tag = 0;
    T res = 1;
    for (int i = 1, j, k; i < n; ++i) {
        for (j = i, k = 0; j <= n; ++j)
            if (a[k][i] != 0) { k = j; break; }
        if (k == 0) return 0;
        if (k != i) swap(a[k], a[i]), ++tag;
        for (j = i+1; j <= n; ++j) {
            T d = a[j][i]*mul_inverse(a[i][i])%MOD;
            for (k = 1; k <= n; ++k)
                a[j][k] = (a[j][k]-d*a[i][k]%MOD+MOD)%MOD;
        }
    }
    for (int i = 1; i <= n; ++i) res = res*a[i][i]%MOD;
    if (tag&1) res = -res;
    return (res+MOD)%MOD;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> MOD) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> a[i][j];
        cout << Determinant(a, n) << endl;
    }
    return 0;
}