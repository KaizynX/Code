/*
 * @Author: Kaizyn
 * @Date: 2020-09-03 19:45:05
 * @LastEditTime: 2020-09-03 20:25:28
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  T tr[N<<2];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { memset(tr+1, 0, sizeof(T)*n); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

/* assume i > j
 * i*D+A[i]-j*D+A[i] > K ? 1 : 2
 * i*D+A[i]-K > j*D-A[j]
 * assume i < j
 * -i*D+A[i]+j*D+A[i] > K ? 1 : 2
 * -i*D+A[i]-K > -j*D-A[j]
 */
int n, m, D, K;
int a[N];
vector<long long> dis;
BinaryIndexedTree<int> lt, rt;

void discrete() {
  dis.reserve(4*n);
  for (long long i = 0; i < n; ++i) {
    dis.emplace_back(i*D+a[i]-K);
    dis.emplace_back(i*D-a[i]);
    dis.emplace_back(-i*D+a[i]-K);
    dis.emplace_back(-i*D-a[i]);
  }
  sort(dis.begin(), dis.end());
  dis.erase(unique(dis.begin(), dis.end()), dis.end());
  m = dis.size();
}

int mp(const long long &x) {
  return lower_bound(dis.begin(), dis.end(), x)-dis.begin()+1;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> D >> K;
  for (int i = 0; i < n; ++i) cin >> a[i];

  if (n < 3) return cout << 0 << endl, 0;
  discrete();
  lt.init(m);
  rt.init(m);
  long long res = 0;
  for (long long i = 0; i < n; ++i) rt.add(mp(-i*D-a[i]), 1);
  for (long long i = 0, cnt1, cnt2, cnt; i < n; ++i) {
    rt.add(mp(-i*D-a[i]), -1);
    cnt = lt.query(mp(i*D+a[i]-K)-1);
    cnt1 = cnt;
    cnt2 = i-cnt;
    cnt = rt.query(mp(-i*D+a[i]-K)-1);
    cnt1 += cnt;
    cnt2 += n-i-1-cnt;
    res -= cnt1*cnt2;
    lt.add(mp(i*D-a[i]), 1);
    #ifdef DEBUG
    cout << i << " " << cnt1 << " " << cnt2 << endl;
    #endif
  }
  res /= 2;
  res += n*(n-1ll)*(n-2)/6;
  cout << res << endl;
  return 0;
}