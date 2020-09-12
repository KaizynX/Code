/*
 * @Author: Kaizyn
 * @Date: 2020-08-31 16:53:56
 * @LastEditTime: 2020-08-31 17:04:10
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
const int K = 17;

int n, k, x, y, z, len;
int f[1<<K];

template <class T> void fwt(T a[], const int x = 1) {
  for (int l = 2; l <= len; l <<= 1)
  for (int i = 0, k = l>>1; i < len; i += l)
  for (int j = 0; j < k; ++j) {
    (a[i+j] += a[i+j+k]) %= MOD;
    a[i+j+k] = (a[i+j]-2*a[i+j+k]%MOD+MOD)%MOD;
    a[i+j] = 1ll*a[i+j]*x%MOD; a[i+j+k] = 1ll*a[i+j+k]*x%MOD;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> k;
  len = 1<<k;
  for (int i = 1; i <= n; ++i) {
    cin >> x >> y;
    memset(f, 0, sizeof(int)*len);
    f[x] = y;
    fwt(f);
    for (int i = 0; i < len; ++i) cout << f[i] << " ";
    cout << endl;
  }
  return 0;
}
/* 233 3
0 1
1 1 1 1 1 1 1 1
1 1
1 -1 1 -1 1 -1 1 -1
2 1
1 1 -1 -1 1 1 -1 -1
3 1
1 -1 -1 1 1 -1 -1 1
4 1
1 1 1 1 -1 -1 -1 -1
5 1
1 -1 1 -1 -1 1 -1 1
6 1
1 1 -1 -1 -1 -1 1 1
7 1
1 -1 -1 1 -1 1 1 -1
*/