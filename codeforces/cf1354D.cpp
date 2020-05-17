/*
 * @Author: Kaizyn
 * @Date: 2020-05-17 16:44:00
 * @LastEditTime: 2020-05-17 18:04:58
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

template <typename T>
struct BinaryIndexedTree
{
    int n;
    T tr[N<<1];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    void init(const int &_n) { n = _n; clear(); }
    void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    void add(const int &x, const T &v) { for (int i = x ; i <= n; i += i&-i) tr[i] += v; }
    void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
    T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
    T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n, q;
BinaryIndexedTree<int> bit;
int t[N];

inline void solve() {
  // cin >> n >> q;
  scanf("%d %d", &n, &q);
  bit.init(n);
  for (int i = 1, a; i <= n; ++i) {
    // cin >> a;
    scanf("%d", &a);
    bit.add(a, 1);
  }
  for (int i = 1, k, l, r, mid; i <= q; ++i) {
    // cin >> k;
    scanf("%d", &k);
    if (k > 0) {
      bit.add(k, 1);
    } else {
      k = -k;
      l = 1; r = n;
      while (l < r) {
        mid = (l+r)>>1;
        if (bit.query(mid) >= k) r = mid;
        else l = mid+1;
      }
      bit.add(l, -1);
    }
  }
  // if (bit.query(n) == 0) return void(cout << 0 << endl);
  if (bit.query(n) == 0) return void(puts("0"));
  for (int i = 1; i <= n; ++i) {
    if (bit.query(i) > 0) {
      printf("%d\n", i);
      return;
    }
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}