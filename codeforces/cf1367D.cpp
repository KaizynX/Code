/*
 * @Author: Kaizyn
 * @Date: 2020-06-16 23:21:22
 * @LastEditTime: 2020-06-16 23:55:34
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 60;

template <typename T>
struct BinaryIndexedTree {
  int n;
  T tr[N];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
  void add(const int &x, const T &v) { for (int i = x ; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

string s;
int n, m;
int a[N], b[N], cnt[26];
char ch[N];
BinaryIndexedTree<int> num, sum;

inline int calc(const int &x) {
  #ifdef DEBUG
  // cout << num.query(x) << " " << sum.query(x) << endl;
  // cout << num.query(x, m) << " " << sum.query(x, m) << endl;
  #endif
  return num.query(x)*x-sum.query(x)+
      sum.query(x, m)-num.query(x, m)*x;
}

inline void solve() {
  cin >> s >> m;
  n = s.size();
  num.init(m);
  sum.init(m);
  int k = 0;
  memset(a+1, -1, sizeof(int)*m);
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    if (b[i] == 0) {
      k = 1;
      ++cnt[0];
      a[i] = 0;
      num.add(i, 1);
      sum.add(i, i);
    }
  }
  for (int kk = 1; kk < 26; ++kk) {
    for (int i = 1; i <= m; ++i) {
      if (a[i] != -1) continue;
      #ifdef DEBUG
      // cout << i << " " << calc(i) << endl;
      #endif
      if (calc(i) == b[i]) a[i] = kk;
    }
    for (int i = 1; i <= m; ++i) {
      if (a[i] == kk) {
        k = max(k, kk);
        ++cnt[kk];
        num.add(i, 1);
        sum.add(i, i);
      }
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= m; ++i) {
    cout << a[i] << " \n"[i==m];
  }
  #endif
  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());
  for (int i = 0, j = 0, cur = 0; i < n && j <= k; ++i) {
    if (!i || s[i] != s[i-1]) {
      cur = 1;
    } else {
      ++cur;
    }
    if (cur >= cnt[j]) {
      ch[j] = s[i];
      cur = -INF;
      ++j;
    }
  }
  for (int i = 1; i <= m; ++i) {
    cout << ch[a[i]];
  }
  cout << endl;
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