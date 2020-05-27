/*
 * @Author: Kaizyn
 * @Date: 2020-05-23 14:38:25
 * @LastEditTime: 2020-05-23 16:41:31
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
typedef unsigned long long ull;

template <typename T, typename U = greater<T>>
struct SegmentTree
{
    U cmp = U();
    int n;
    T tr[N<<2], init_val = cmp(0, 1) ? INF : -INF;
    SegmentTree(){}
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
    void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
    void modify(const int &x, const T &k = 0) { _modify(x, k, 1, n); }
    void update(const int &x, const T &k = 0) { _update(x, k, 1, n); }
    T query(const int &x) { return _query(x, x, 1, n); }
    T query(const int &l, const int &r) { return _query(l, r, 1, n); }
private :
    void push_up(const int &i) { tr[i] = mv(tr[i<<1], tr[i<<1|1]); }
    void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
        if (l == r) { tr[i] = k; return; }
        int mid = (l+r)>>1;
        _build(l, mid, k, i<<1);
        _build(mid+1, r, k, i<<1|1);
        push_up(i);
    }
    void _modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl == x && trr == x) return tr[i] = k, void();
        int mid = (trl+trr)>>1;
        if (x <= mid) _modify(x, k, trl, mid, i<<1);
        else _modify(x, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    void _update(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl == x && trr == x) return tr[i] = mv(tr[i], k), void();
        int mid = (trl+trr)>>1;
        if (x <= mid) _update(x, k, trl, mid, i<<1);
        else _update(x, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) return tr[i];
        int mid = (trl+trr)>>1;
        T res = init_val;
        if (l <= mid) res = mv(res, _query(l, r, trl, mid, i<<1));
        if (r >  mid) res = mv(res, _query(l, r, mid+1, trr, i<<1|1));
        return res;
    }
};

unsigned long long k1, k2;
unsigned long long CoronavirusBeats() {
  unsigned long long k3 = k1, k4 = k2;
  k1 = k4;
  k3 ^= k3 << 23;
  k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
  return k2 + k4;
}

int n;
ull x[N], y[N], z[N];
int dp[N], id[N], tmp[N];
SegmentTree<int, greater<int>> st;

inline void discrete(ull *a) {
  static ull d[N];
  memcpy(d+1, a+1, sizeof(ull)*n);
  sort(d+1, d+n+1);
  int m = unique(d+1, d+n+1)-d;
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(d+1, d+m, a[i])-d;
  }
}

void cdq(const int &l, const int &r) {
  if (l == r) return dp[id[l]] = max(dp[id[l]], 1), void();
  int mid = (l+r)>>1, i = l, j = mid+1;
  cdq(l, mid);
  for (int i = l; i <= r; ++i) tmp[i] = id[i];
  sort(tmp+mid+1, tmp+r+1, [](int a, int b) { return y[a] < y[b]; });
  while (i <= mid && j <= r) {
    if (y[tmp[i]] < y[tmp[j]]) {
      st.update(z[tmp[i]], dp[tmp[i]]);
      ++i;
    } else {
      if (z[tmp[j]] > 1) dp[tmp[j]] = max(dp[tmp[j]], st.query(1, z[tmp[j]]-1)+1);
      ++j;
    }
  }
  while (j <= r) {
    if (z[tmp[j]] > 1) dp[tmp[j]] = max(dp[tmp[j]], st.query(1, z[tmp[j]]-1)+1);
    ++j;
  }
  for (int i = l; i <= mid; ++i) st.modify(z[tmp[i]], 0);
  cdq(mid+1, r);
  sort(id+l, id+r+1, [](int a, int b) { return y[a] < y[b]; });
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> k1 >> k2;
  for (int i = 1; i <= n; ++i) {
    x[i] = CoronavirusBeats();
    y[i] = CoronavirusBeats();
    z[i] = CoronavirusBeats();
    id[i] = i;
  }
  discrete(x);
  discrete(y);
  discrete(z);
  #ifdef DEBUG
  cout << "****" << endl;
  for (int i = 1; i <= n; ++i) {
    cout << x[i] << " " << y[i] << " " << z[i] << endl;
  }
  cout << "****" << endl;
  #endif
  sort(id+1, id+n+1, [](const int &a, const int &b) {
      if (x[a] != x[b]) return x[a] < x[b];
      if (y[a] != y[b]) return y[a] < y[b];
      return z[a] < z[b];
  });
  st.build(n, 0);
  cdq(1, n);
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    res = max(res, dp[i]);
  }
  cout << res << endl;
  for (int i = 1; i <= n; ++i) {
    cout << dp[i]-1 << " \n"[i==n];
  }
  return 0;
}