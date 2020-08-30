/*
 * @Author: Kaizyn
 * @Date: 2020-08-29 15:07:54
 * @LastEditTime: 2020-08-29 15:29:10
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

int n;
int a[N], cnt[N];
set<int> mex, dif;
vector<int> res;

inline void init(int n) {
  mex.clear();
  res.clear();
  dif.clear();
  for (int i = 0; i <= n; ++i) {
    cnt[i] = 0;
    mex.insert(i);
  }
}

inline void insert(int x) {
  if (++cnt[x] == 1) mex.erase(x);
}

inline void erase(int x) {
  if (--cnt[x] == 0) mex.insert(x);
}

inline int query() {
  return *mex.begin();
}

inline bool check() {
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i-1]) return false;
  }
  return true;
}

#ifdef DEBUG
void print() {
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " \n"[i==n-1];
  }
  cout.flush();
}
#endif

inline void solve() {
  cin >> n;
  init(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    insert(a[i]);
    if (a[i] != i) dif.insert(i);
  }
  while (!check()) {
    int m = query(), p = m == n ? *dif.begin() : m;
    res.emplace_back(p+1);
    erase(a[p]);
    if (a[p] != p) dif.erase(p);
    a[p] = m;
    if (a[p] != p) dif.insert(p);
    insert(m);
    #ifdef DEBUG
    cout << p+1 << endl;
    print();
    #endif
  }
  cout << res.size() << endl;
  for (int &i : res) cout << i << " ";
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