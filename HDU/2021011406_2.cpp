/*
 * @Author: Kaizyn
 * @Date: 2021-01-14 10:29:46
 * @LastEditTime: 2021-01-14 10:45:16
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
const int N = 1e2+7;

int n;
vector<int> vec[N];

struct Node {
  int v;
  Node *l, *r;
  Node(){}
  Node(int v) : v(v) { l = r = nullptr; }
} *root;

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

void dfs(Node *rt, int dep) {
  if (!rt) return;
  vec[dep].emplace_back(rt->v);
  dfs(rt->l, dep+1);
  dfs(rt->r, dep+1);
}

inline void solve() {
  clear(root);
  for (int i = 0; i < 100; ++i) {
    vec[i].clear();
  }
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    add(root, a);
  }
  dfs(root, 0);
  for (int i = 0; i < 100; ++i) {
    for (int &j : vec[i]) cout << j << " ";
  }
  cout << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  while (cin >> n) solve();
  return 0;
}