/*
 * @Author: Kaizyn
 * @Date: 2021-08-04 21:57:54
 * @LastEditTime: 2021-08-04 23:29:21
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
  vector<int> *e;
  int n, d[N], f[LOGN][N], cnt[N], sa[N], rk[N<<1], _rk[N<<1], _oldrk[N<<1], tp[N<<1];
  void dfs(int u = 1, int fa = 0) {
    d[u] = d[fa]+1;
    f[0][u] = fa;
    for (int i = 1; (1<<i) <= d[u]; ++i)
      f[i][u] = f[i-1][f[u][i-1]];
    for (auto v : e[u]) if (v != fa)
      dfs(v, u);
  }
  template <typename T>
  void tsort(int *sa, T *rk, int *tp, int m) {
    memset(cnt, 0, sizeof(int)*(m+1));
    for (int i = 1; i <= n; ++i) ++cnt[rk[i]];
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
    for (int i = n; i; --i) sa[cnt[rk[tp[i]]]--] = tp[i];
  }
  bool cmp(int i, int t) {
    return tp[sa[i-1]] == tp[sa[i]] && tp[f[t][sa[i-1]]] == tp[f[t][sa[i]]];
  }
  template <typename T>
  void build(vector<int> *e, const T *a, const int n) {
    this->n = n;
    this->e = e;
    dfs();
    int p = 128, i;
    iota(tp+1, tp+n+1, 1);
    tsort(sa, a, tp, p);
    for (i = 1, p = 0; i <= n; ++i) {
      _rk[sa[i]] = a[sa[i-1]] == a[sa[i]] ? p : ++p;
      rk[sa[i]] = i;
    }
    for (int w = 1, t = 0; w < n; w <<= 1, ++t) {
      for (i = 1; i <= n; ++i) _oldrk[i] = rk[f[t][i]];
      tsort(tp, _oldrk, sa, n);
      tsort(sa, _rk, tp, p);
      swap(_rk, tp);
      for (i = 1, p = 0; i <= n; ++i) {
        _rk[sa[i]] = cmp(i, t) ? p : ++p;
        rk[sa[i]] = i;
      }
    }
  }
};

int n;
vector<int> e[N];
char a[N];
SAonTree sa;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n;
  for (int i = 2, f; i <= n; ++i) {
    cin >> f;
    e[f].emplace_back(i);
  }
  cin >> (a+1);
  sa.build(e, a, n);
  for (int i = 1; i <= n; ++i) cout << sa.sa[i] << " \n"[i==n];
  // for (int i = 1; i <= n; ++i) cout << sa.rk[i] << " \n"[i==n];
  // for (int i = 1; i <= n; ++i) cout << sa._rk[i] << " \n"[i==n];
  return 0;
}