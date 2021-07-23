/*
 * @Author: Kaizyn
 * @Date: 2021-07-23 16:25:02
 * @LastEditTime: 2021-07-23 17:12:29
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

template <typename T>
struct SAM {
  struct State {
    int len, link;
    map<T, int> nex;
  } st[N<<1];
  int sz, last;
  void init() {
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
  }
  int extend(T c) {
    int cur = sz++;
    st[cur].len = st[last].len+1;
    int p = last;
    while (~p && !st[p].nex.count(c)) {
      st[p].nex[c] = cur;
      p = st[p].link;
    }
    if (p == -1) {
      st[cur].link = 0;
    } else {
      int q = st[p].nex[c];
      if (st[p].len+1 == st[q].len) {
        st[cur].link = q;
      } else {
        int clone = sz++;
        st[clone].len = st[p].len+1;
        st[clone].nex = st[q].nex;
        st[clone].link = st[q].link;
        while (~p && st[p].nex[c] == q) {
          st[p].nex[c] = clone;
          p = st[p].link;
        }
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
    return st[cur].len-st[st[cur].link].len;
  }
};

int n;
SAM<int> sam;

inline void solve() {
  cin >> n;
  ll res = 0;
  sam.init();
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    res += sam.extend(a);
    cout << res << '\n';
  }
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