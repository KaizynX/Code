/*
 * @Author: Kaizyn
 * @Date: 2021-08-04 22:35:09
 * @LastEditTime: 2021-08-04 23:27:52
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

int n;
int a[N], d[N], f[20][N];
vector<int> e[N];
char s[N];

void dfs(int u = 1, int fa = 0) {
    d[u] = d[fa]+1;
    f[0][u] = fa;
    for (int i = 1; (1<<i) <= d[u]; ++i)
      f[i][u] = f[i-1][f[u][i-1]];
    for (auto v : e[u]) if (v != fa)
      dfs(v, u);
  }

namespace SA {
    int sa[N], rk[N], rkk[N], tp[N], rk2[N], tx[N];

    inline void tsort(int *sa, int *rk, int *tp, int m) {
        for (int i = 0; i <= m; i++) tx[i] = 0;
        for (int i = 1; i <= n; i++) ++tx[rk[i]];
        for (int i = 1; i <= m; i++) tx[i] += tx[i-1];
        for (int i = n; i; i--) sa[tx[rk[tp[i]]]--] = tp[i];
    }

    inline bool pd(int i, int t) {
        return tp[sa[i-1]] == tp[sa[i]] && tp[f[t][sa[i-1]]] == tp[f[t][sa[i]]];
    }

    inline void main() {
        int p = 0;
        for (int i = 1; i <= n; i++) a[i] = s[i] - 'a' + 1, tp[i] = i;
        tsort(sa, a, tp, n);
        rk[sa[1]] = rkk[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++) {
            rk[sa[i]] = a[sa[i-1]] == a[sa[i]] ? p : ++p;
            rkk[sa[i]] = i;
        }
        for (int w = 1, t = 0; w < n; w <<= 1, ++t) {
            for (int i = 1; i <= n; i++) rk2[i] = rkk[f[t][i]];
        // for (int i = 1; i <= n; ++i) cout << f[t][i] << " \n"[i==n];
        // for (int i = 1; i <= n; ++i) cout << rk2[i] << " \n"[i==n];
            tsort(tp, rk2, sa, n);
            tsort(sa, rk, tp, p);
            swap(rk, tp);
            rk[sa[1]] = rkk[sa[1]] = p = 1;
            for (int i = 2; i <= n; i++) {
                rk[sa[i]] = pd(i, t) ? p : ++p;
                rkk[sa[i]] = i;
            }
        }
    }
}


inline void solve() {
  cin >> n;
  for (int i = 2, f; i <= n; ++i) {
    cin >> f;
    e[f].emplace_back(i);
  }
  cin >> (s+1);
  dfs();
  /*
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; (1<<j) <= d[i]; ++j) {
      cout << f[i][j] << " ";
    }
    cout << endl;
  }
  */
  SA::main();
  for (int i = 1; i <= n; ++i) cout << SA::sa[i] << " \n"[i==n];
  // for (int i = 1; i <= n; ++i) cout << SA::rkk[i] << " \n"[i==n];
  // for (int i = 1; i <= n; ++i) cout << SA::rk[i] << " \n"[i==n];
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}