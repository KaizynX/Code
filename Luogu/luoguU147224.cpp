/*
 * @Author: Kaizyn
 * @Date: 2020-12-26 21:32:03
 * @LastEditTime: 2020-12-29 00:14:27
 */
/* 有n个物品在t秒出现在x处,你从任意位置开始每秒最多走k格,问最多能拿到几个物品
 * std:物品(x,t) 每次转移可以走当前点以及向上两条斜率1/k直线夹角内点
 * 按每个物品的两条线求二维偏序
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { tr = vector<T>(this->n = n+1, 0); }
  void update(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] = max(tr[i], v); }
  void modify(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] = v; }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res = max(res, tr[i]); return res; }
};

int n, k;
int x[N], t[N], id[N], buf[N], dp[N];
ll vl[N], vr[N];
BinaryIndexedTree<int> tree;

#ifdef DEBUG
void print(int l = 1, int r = n) {
  for (int i = l; i <= r; ++i) printf("dp[%d]=%d\n", i, dp[i]);
}
#endif

template <typename T>
void discrete(T v[]) {
  vector<T> d(n);
  for (int i = 1; i <= n; ++i) d[i-1] = v[i];
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  for (int i = 1; i <= n; ++i) {
    v[i] = lower_bound(d.begin(), d.end(), v[i])-d.begin()+1;
  }
}

void cdq(int l, int r) {
  if (l == r) return;
  int mid = (l+r)>>1;
  cdq(l, mid);
  memcpy(buf+mid+1, id+mid+1, sizeof(int)*(r-mid));
  sort(id+mid+1, id+r+1, [](int l, int r) {
    return vl[l] == vl[r] ? vr[l] < vr[r] : vl[l] > vl[r];
  });
  vector<int> vec;
  int i = l, j = mid+1;
  while (i <= mid || j <= r) {
    if (j > r || (i <= mid && vl[id[i]] >= vl[id[j]])) {
      tree.update(vr[id[i]], dp[id[i]]);
      vec.emplace_back(id[i++]);
    } else {
      dp[id[j]] = max(dp[id[j]], tree.query(vr[id[j]])+1);
      vec.emplace_back(id[j++]);
    }
  }
  for (i = l; i <= mid; ++i) tree.modify(vr[id[i]], 0);
  memcpy(id+mid+1, buf+mid+1, sizeof(int)*(r-mid));
  cdq(mid+1, r);
  for (int i = l; i <= r; ++i) id[i] = vec[i-l];
#ifdef DEBUG
  printf("cdq(%d,%d)\n", l, r);
  print(l, r);
#endif
}

signed main() {
  // freopen("data.in", "r", stdin);
  // freopen("my.out", "w", stdout);
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> t[i];
    vl[i] = x[i]-1ll*k*t[i];
    vr[i] = x[i]+1ll*k*t[i];
  }
  iota(id+1, id+n+1, 1);
  fill(dp+1, dp+n+1, 1);
  sort(id+1, id+n+1, [](int l, int r) {
    if (t[l] != t[r]) return t[l] < t[r];
    return vl[l] == vl[r] ? vr[l] < vr[r] : vl[l] > vl[r];
  });
  discrete(vl);
  discrete(vr);
  tree.init(n);
#ifdef DEBUG
  for (int i, j = 1; j <= n; ++j) {
    i = id[j];
    printf("%d %d %lld %lld\n", t[i], x[i], vl[i], vr[i]);
  }
#endif
  cdq(1, n);
  int res = 0;
  for (int i = 1; i <= n; ++i) res = max(res, dp[i]);
  cout << res << endl;
#ifdef DEBUG
  print();
#endif
  return 0;
}
/*
14 4
273 14
163 16
215 17
249 28
249 32
106 66
66 73
258 80
51 80
179 81
205 87
83 95
117 96
100 96

5
*/