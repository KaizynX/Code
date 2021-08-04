/*
 * @Author: Kaizyn
 * @Date: 2021-08-04 23:31:19
 * @LastEditTime: 2021-08-04 23:40:10
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

/*
树上可能出现完全相同的字符串,增加上一轮的有序状态rk为"第三关键字"
*/
struct SAonTree {
  static const int LOGN = 33-__builtin_clz(N);
  int n, d[N], cnt[N], sa[N], rk[N<<1], _rk[N<<1], _oldrk[N<<1], tp[N<<1];
  template <typename T>
  void tsort(int *sa, T *rk, int *tp, int m) {
    memset(cnt, 0, sizeof(int)*(m+1));
    for (int i = 1; i <= n; ++i) ++cnt[rk[i]];
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
    for (int i = n; i; --i) sa[cnt[rk[tp[i]]]--] = tp[i];
  }
  template <typename T>
  void build(int *f, const T *a, const int n) {
    this->n = n;
    int p = 128, i;
    iota(tp+1, tp+n+1, 1);
    tsort(sa, a, tp, p);
    for (i = 1, p = 0; i <= n; ++i) {
      _rk[sa[i]] = a[sa[i-1]] == a[sa[i]] ? p : ++p;
      rk[sa[i]] = i;
    }
    for (int w = 1, t = 0; w < n; w <<= 1, ++t) {
      for (i = 1; i <= n; ++i) _oldrk[i] = rk[f[i]];
      tsort(tp, _oldrk, sa, n);
      tsort(sa, _rk, tp, p);
      swap(_rk, tp);
      for (i = 1, p = 0; i <= n; ++i) {
        _rk[sa[i]] = tp[sa[i-1]] == tp[sa[i]]
            && tp[f[sa[i-1]]] == tp[f[sa[i]]] ? p : ++p;
        rk[sa[i]] = i;
      }
      for (int i = n; i; --i) f[i] = f[f[i]];
    }
  }
};

int n;
int f[N];
char a[N];
SAonTree sa;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    cin >> f[i];
  }
  cin >> (a+1);
  sa.build(f, a, n);
  for (int i = 1; i <= n; ++i) cout << sa.sa[i] << " \n"[i==n];
  // for (int i = 1; i <= n; ++i) cout << sa.rk[i] << " \n"[i==n];
  // for (int i = 1; i <= n; ++i) cout << sa._rk[i] << " \n"[i==n];
  return 0;
}