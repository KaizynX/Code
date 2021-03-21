/*
 * @Author: Kaizyn
 * @Date: 2021-03-21 22:01:24
 * @LastEditTime: 2021-03-21 22:09:17
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
int a[N], pre[N], nex[N];
vector<int> res;
set<int> st;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

void del(int x) {
  nex[pre[x]] = nex[x];
  pre[nex[x]] = pre[x];
  if (st.find(x) != st.end()) st.erase(st.find(x));
  if (gcd(a[pre[x]], a[nex[x]]) == 1) st.insert(pre[x]);
}

inline void solve() {
  cin >> n;
  m = 0;
  res.clear();
  st.clear();
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pre[i] = (i-1+n)%n;
    nex[i] = (i+1)%n;
  }
  for (int i = 0; i < n; ++i) {
    if (gcd(a[i], a[(i+1)%n]) == 1) {
      st.insert(i);
    }
  }
  // i refer to edge between i and nex[i]
  for (int i = 0, j; st.size() && m < n; i = j, ++m) {
    #ifdef DEBUG
    for (auto &j : st) cout << j << " ";
    cout << '\n';
    #endif
    auto it = st.lower_bound(i);
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