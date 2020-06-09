/*
 * @Author: Kaizyn
 * @Date: 2020-06-04 22:31:39
 * @LastEditTime: 2020-06-05 00:15:31
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n, p;
int k[N], cnt[N], inq[N];
vector<int> ls;
priority_queue<int, vector<int>, greater<int>> q;
// int a[N], b[N];

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

inline void solve() {
  cin >> n >> p;
  if (p == 1) return cout << n&1 << endl, void();
  mp.clear();
  ls.clear();
  int tk = log(1e6)/log(p)+.5;
  for (int i = 1; i <= n; ++i) {
    cin >> k[i];
    ++cnt[k[i]];
    if (!inq[k[i]]) q.push(k[i]), inq[k[i]] = 1;
  }
  // sort(k+1, k+n+1);
  // reverse(k+1, k+n+1);
  while (q.size()) {
    int u = q.top();
    q.pop();
    cnt[u+1] += cnt[u]/p;
    cnt[u] %= p;
    if (!inq[u+1]) q.push(u+1), inq[u+1] = 1;
    if (cnt[u]) ls.push_back(u);
  }
  reverse(ls.begin(), ls.end());
  long long dif = 0, last = ls.front();
  for (int i = 0; i < (int)ls.size(); ++i) {
    if (last-ls[i] >= tk) {
      break;
    }
    dif *= qpow(p, last-ls[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}