/*
 * @Author: Kaizyn
 * @Date: 2020-10-02 23:31:30
 * @LastEditTime: 2020-10-03 10:11:05
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

struct Node {
  int l, r, y, id;
};

int n;
int vis[N];
Node a[N];

struct Fuck {
  set<pii> t;
  int ha, hd;
  vector<Node> add, del;
  void clear() {
    t.clear();
    add.clear();
    del.clear();
    ha = hd = 0;
  }
  void init(int op = 0) {
    for (int i = 1, l, r, y; i <= n; ++i) {
      if (!op) l = a[i].y-a[i].r, r = a[i].y-a[i].l, y = a[i].y;
      else     l = a[i].y+a[i].l, r = a[i].y+a[i].r, y = -a[i].y;
      add.push_back(Node{l, r, y, a[i].id});
      del.push_back(Node{l, r, y, a[i].id});
    }
    sort(add.begin(), add.end(), [&](Node &n1, Node &n2) {
      return op ? n1.l < n2.l : n1.r > n2.r;
    });
    sort(del.begin(), del.end(), [&](Node &n1, Node &n2) {
      return op ? n1.r < n2.r : n1.l > n2.l;
    });
  }
  int query(int x, int y, int op = 0) {
    int k = !op ? x-y : x+y;
    while (ha < n && (op ? add[ha].l <= k : add[ha].r >= k)) {
      if (!vis[add[ha].id]) t.insert({add[ha].y, add[ha].id});
      ++ha;
    }
    while (hd < n && (op ? del[hd].r < k : del[hd].l > k)) {
      pii tmp = {del[hd].y, del[hd].id};
      if (t.find(tmp) != t.end()) t.erase(tmp);
      ++hd;
    }
    auto it = t.lower_bound({(!op ? 1 : -1)*y, 0});
    if (it == t.end()) return 0;
    else return it->second;
  }
  void erase(pii p) {
    if (t.find(p) != t.end()) t.erase(p);
  }
} fuck[2];

inline void solve() {
  fuck[0].clear(); fuck[1].clear();
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].l >> a[i].r >> a[i].y;
    a[i].id = i;
    vis[i] = 0;
  }
  fuck[0].init(0); fuck[1].init(1);
  int x = 0, y = 0, u = 0, cnt = 0, id;
  while ((id = fuck[u].query(x, y, u))) {
    fuck[0].erase({a[id].y, id});
    fuck[1].erase({-a[id].y, id});
    vis[id] = 1;
    x += abs(y-a[id].y);
    y = a[id].y;
    u ^= 1;
    ++cnt;
  }
  cout << cnt << endl;
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