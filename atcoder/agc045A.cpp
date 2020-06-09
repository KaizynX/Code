/*
 * @Author: Kaizyn
 * @Date: 2020-06-07 19:52:31
 * @LastEditTime: 2020-06-07 20:19:59
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e2+7;

template <typename T>
struct LinearBase {
  int sz = sizeof(T)*8, zero;
  T tot;
  vector<T> b, rb, p;
  LinearBase(){ init(); }
  void init() {
    tot = zero = 0;;
    vector<T>(sz, 0).swap(b);
    vector<T>().swap(rb);
    vector<T>().swap(p);
  }
  template <typename TT>
  void build(TT a[], const int &n) {
    init();
    for (int i = 1; i <= n; ++i) insert(a[i]);
  }
  void merge(const LinearBase xj) {
    for (int i : xj.b) if (i) insert(i);
  }
  void insert(T x) {
    for (int i = sz-1; i >= 0; --i) if ((x>>i)&1) {
      if (!b[i]) { b[i] = x; return; }
      x ^= b[i];
    }
    zero = 1;
  }
  bool find(T x) {
    for (int i = sz-1; i >= 0; --i) if ((x>>i)&1) {
      if (!b[i]) { return false; }
      x ^= b[i];
    }
    return true;
  }
  T max_xor() {
    T res = 0;
    for (int i = sz-1; i >= 0; --i)
      if (~(res>>i)&1) res ^= b[i];
      // res = max(res, res^b[i]);
    return res;
  }
  T min_xor() {
    if (zero) return 0;
    for (int i = 0; i < sz; ++i)
      if (b[i]) return b[i];
  }
  void rebuild() {
    rb = b;
    vector<T>().swap(p);
    for (int i = sz-1; i >= 0; --i)
      for (int j = i-1; j >= 0; --j)
        if ((rb[i]>>j)&1) rb[i] ^= rb[j];
    for (int i = 0; i < sz; ++i)
      if (rb[i]) p.emplace_back(rb[i]);
    tot = ((T)1<<p.size())+zero;
  }
  T kth_min(T k) {
    if (k >= tot || k < 1) return -1;
    if (zero && k == 1) return 0;
    if (zero) --k;
    T res = 0;
    for (int i = (int)p.size()-1; i >= 0; --i)
      if ((k>>i)&1) res ^= p[i];
    return res;
  }
  T kth_max(const T &k) {
    return kth_min(tot-k);
  }
};

int n;
long long a[N];
string s;
LinearBase<long long> lb;

inline void solve() {
  lb.init();
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cin >> s;
  int res = 0;
  for (int i = n; i; --i) {
    if (s[i-1] == '1') {
      res |= !lb.find(a[i]);
    } else {
      lb.insert(a[i]);
    }
  }
  cout << res << endl;
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