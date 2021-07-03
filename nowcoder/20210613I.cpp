/*
 * @Author: Kaizyn
 * @Date: 2021-06-13 16:21:12
 * @LastEditTime: 2021-06-13 16:36:46
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n, m;
int t[N], c[N];
string s;
ll k, all;

inline ll sum(ll x) {
  return x*(x+1)/2;
}

inline ll calc(int t, int d) {
  if (d >= t) return 0;
  int x = (t-d)/(d+1), y = (t-d)%(d+1);
  return y*sum(x+1)+(d+1-y)*sum(x);
}

ll check(int mid) {
  priority_queue<pli> q;
  ll cur = all;
  for (int i = 1; i <= m; ++i) {
    c[i] = 0;
    q.push(pli{calc(t[i], c[i])-calc(t[i], c[i]+1), i});
  }
  while (mid-- && q.size()) {
    cur -= q.top().first;
    int i = q.top().second;
    q.pop();
    if (++c[i] < t[i])
      q.push(pli{calc(t[i], c[i])-calc(t[i], c[i]+1), i});
  }
  return cur;
}

inline void solve() {
  cin >> n >> k >> s;
  m = 0;
  for (int i = 0, j; i < n; i = j) {
    j = i+1;
    if (s[i] == '0') continue;
    while (j < n && s[j] == '1') ++j;
    t[++m] = j-i;
    all += sum(j-i);
  }
  int l = 0, r = n, mid;
  while (l < r) {
    mid = (l+r)>>1;
    if (check(mid) <= k) r = mid;
    else l = mid+1;
  }
  cout << l << '\n';
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