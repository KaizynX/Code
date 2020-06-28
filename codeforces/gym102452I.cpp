/*
 * @Author: Kaizyn
 * @Date: 2020-06-24 21:55:28
 * @LastEditTime: 2020-06-24 23:09:36
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n, m;
int r[N], k[N], q[N][5];
long long old_base[N][5], st_base[N];
set<pli> st[N];
vector<int> res, tmp;

inline void add(const int &id) {
  long long rr = (r[id]+k[id]-1)/k[id];
  for (int i = 1, j; i <= k[id]; ++i) {
    j = q[id][i];
    old_base[id][i] = st_base[j];
    st[j].insert({st_base[j]+rr, id});
  }
}

inline void erase(const int &id) {
  long long rr = (r[id]+k[id]-1)/k[id];
  for (int i = 1, j; i <= k[id]; ++i) {
    j = q[id][i];
    st[j].erase(st[j].find({old_base[id][i]+rr, id}));
  }
}

inline void update(const int &id) {
  for (int i = 1, j; i <= k[id]; ++i) {
    j = q[id][i];
    r[id] -= st_base[j]-old_base[id][i];
  }
}

inline void print() {
  sort(res.begin(), res.end());
  cout << res.size();
  for (const int &i : res) cout << " " << i;
  cout << endl;
}

inline void solve() {
  cin >> n >> m;
  int last = 0, p = 0;
  for (int t = 1, op, x, y; t <= m; ++t) {
    cin >> op;
    if (op == 1) {
      ++p;
      cin >> r[p] >> k[p];
      r[p] ^= last;
      for (int i = 1; i <= k[p]; ++i) {
        cin >> q[p][i];
        q[p][i] ^= last;
      }
      add(p);
    } else {
      cin >> x >> y;
      x ^= last; y ^= last;
      res.clear(); tmp.clear();
      st_base[x] += y;
      auto ed = st[x].lower_bound({st_base[x]+1, 0}); // >= y
      for (auto it = st[x].begin(); it != ed; ++it) {
        tmp.emplace_back(it->second);
      }
      for (const int &id : tmp) {
        erase(id);
        update(id);
        if (r[id] <= 0) res.emplace_back(id);
        else add(id);
      }
      last = res.size();
      print();
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}