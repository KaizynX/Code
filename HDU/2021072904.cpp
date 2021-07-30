/*
 * @Author: Kaizyn
 * @Date: 2021-07-29 13:31:14
 * @LastEditTime: 2021-07-29 14:53:02
 */
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

int n;
ll k;
char str[N];
int cost[26], sum[N];

struct SAM {
  static const int A = 26;
  static const char C = 'a';
  struct State {
    int len, link, ed, nex[A];
    State& operator =(const State &st) {
      ed = st.ed;
      len = st.len;
      link = st.link;
      memcpy(nex, st.nex, sizeof(nex));
      return *this;
    }
  } st[N<<1];
  int sz, last;
  void init() {
    memset(st, 0, sizeof(State)*sz);
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
  }
  int extend(int id) {
    int c = str[id]-C, cur = sz++;
    st[cur].len = st[last].len+1;
    st[cur].ed = id;
    int p = last;
    while (~p && !st[p].nex[c]) {
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
        st[clone] = st[q];
        // st[clone].ed = 0;
        // st[clone].ed = id;
        st[clone].len = st[p].len+1;
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
  ll check(int val) { // < val 子串有几个
    ll cnt = 1;
    for (int i = 1, j, ed, li, lj; i < sz; ++i) {
      j = st[i].link;
      ed = st[i].ed;
      // if (!ed) continue;
      // len[j]+1, len[i] at ed
      li = ed-st[i].len;
      lj = ed-st[j].len;
      // first pos sum[ed]-sum[pos] < val
      // int pos = upper_bound(sum+li, sum+lj, sum[ed]-val)-sum;
      // cnt += lj-pos;
      cnt += lj-(upper_bound(sum+li, sum+lj, sum[ed]-val)-sum);
    }
    return cnt;
  }
} sam;

inline void solve() {
  scanf("%d%lld%s", &n, &k, str+1);
  for (int i = 0; i < 26; ++i) scanf("%d", cost+i);
  sam.init();
  ll all = 0;
  for (int i = 1; i <= n; ++i) {
    all += sam.extend(i);
    sum[i] = sum[i-1]+cost[str[i]-'a'];
  }
  // cout << all << '\n';
  if (all < k) return puts("-1"), void();
  int l = 1, r = sum[n], mid;
  while (l < r) {
    mid = (l+r+1)/2;
    if (sam.check(mid) <= k) l = mid;
    else r = mid-1;
  }
  printf("%d\n", l);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}