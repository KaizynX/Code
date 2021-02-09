/*
 * @Author: Kaizyn
 * @Date: 2021-01-14 10:29:46
 * @LastEditTime: 2021-01-14 10:42:19
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
// const int N = ;

int n;

struct Node {
  int v;
  Node *l, *r;
  Node(){}
  Node(int v) : v(v) { l = r = nullptr; }
} *root;

struct P {
  int x, y, v;
  bool operator <(const P &b) const {
    if (x != b.x) return x < b.x;
    return y < b.y;
  }
};

vector<P> vec;

void add(Node *&rt, int val) {
  if (!rt) return rt = new Node(val), void();
  if (val < rt->v) add(rt->l, val);
  else add(rt->r, val);
}

void clear(Node *&rt) {
  if (!rt) return;
  clear(rt->l);
  clear(rt->r);
  delete rt;
  rt = nullptr;
}

void dfs(Node *rt, int x, int y) {
  if (!rt) return;
  vec.emplace_back(P{x, y, rt->v});
  dfs(rt->l, x+1, y-1);
  dfs(rt->r, x+1, y+1);
}

inline void solve() {
  clear(root);
  vec.clear();
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    add(root, a);
  }
  // cout << "OK" << endl;
  dfs(root, 0, 0);
  sort(vec.begin(), vec.end());
  for (auto &p : vec) cout << p.v << " ";
  cout << endl;
  /*
  for (int i = 0; i < (int)vec.size(); ++i) {
    cout << vec[i].v << " \n"[i+1 == (int)vec.size()];
  }
  */
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  while (cin >> n) solve();
  return 0;
}