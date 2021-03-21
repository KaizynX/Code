/*
 * @Author: Kaizyn
 * @Date: 2021-03-21 20:57:00
 * @LastEditTime: 2021-03-21 21:59:35
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

int n, m;
int a[N], pre[N], nex[N], vis[N];
vector<int> res;
set<int> st;

void del(int x) {
  ++m;
  vis[x] = 1;
  nex[pre[x]] = nex[x];
  pre[nex[x]] = pre[x];
  if (__gcd(a[pre[x]], a[nex[x]]) == 1) {
    st.insert(pre[x]);
  }
}

inline void solve() {
  cin >> n;
  m = 0;
  res.clear();
  st.clear();
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    vis[i] = 0;
    pre[i] = (i-1+n)%n;
    nex[i] = (i+1)%n;
  }
  for (int i = 0; i < n; ++i) {
    if (__gcd(a[i], a[(i+1)%n]) == 1) {
      st.insert(i);
    }
  }
  // i refer to edge between i and nex[i]
  for (int i = 0, j; st.size() && m < n; i = j) {
    #ifdef DEBUG
    for (auto &j : st) cout << j << " ";
    cout << '\n';
    #endif
    auto it = st.lower_bound(i);
    if (vis[*it]) {
      st.erase(it);
      if (st.empty()) break;
      it = st.lower_bound(i);
    }
    if (it == st.end()) it = st.begin();
    j = nex[*it];
    st.erase(it);
    res.emplace_back(j);
    del(j);
  }
  cout << res.size() << ' ';
  for (int &i : res) cout << i+1 << ' ';
  cout << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}