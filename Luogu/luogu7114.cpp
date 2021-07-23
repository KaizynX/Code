/*
 * @Author: Kaizyn
 * @Date: 2021-07-22 15:29:35
 * @LastEditTime: 2021-07-22 16:16:06
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
const int N = (1<<20)+7;

vector<int> z_function(const string &s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { this->n = n; tr = vector<T>(n+1, 0); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

string s;
vector<int> z;
int n;
// pre[i] [0, i]奇数次字符数量
// suf[i] [i, n)奇数次字符数量
int buf[N], *pre = buf+1, suf[N], cnt[26];
BinaryIndexedTree<int> sum;

inline void solve() {
  cin >> s;
  n = s.size();
  z = z_function(s);
  sum.init(27);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    pre[i] = pre[i-1];
    if (cnt[s[i]-'a'] ^= 1) ++pre[i];
    else --pre[i];
  }
  memset(cnt, 0, sizeof cnt);
  suf[n] = 0;
  for (int i = n-1; i >= 0; --i) {
    suf[i] = suf[i+1];
    if (cnt[s[i]-'a'] ^= 1) ++suf[i];
    else --suf[i];
  }
  ll res = 0;
  sum.add(pre[0]+1, 1);
  for (int i = 2; i < n; ++i) {
    // AB^k [0, i)
    int k = min(z[i], n-i-1)/i+1;
    int lc = n-k*i;
    int fc1 = suf[n-lc], fc2 = suf[n-lc-i];
    int tc1 = (k+1)/2, tc2 = k/2;
    res += tc1*sum.query(fc1+1);
    res += tc2*sum.query(fc2+1);
    sum.add(pre[i-1]+1, 1);
  }
  cout << res << '\n';
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