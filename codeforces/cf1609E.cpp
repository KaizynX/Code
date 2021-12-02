/*
 * @Author: Kaizyn
 * @Date: 2021-11-29 00:36:51
 * @LastEditTime: 2021-11-29 01:02:14
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { this->n = n; tr = vector<T>(n+1, 0); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n, q;
string s;
BinaryIndexedTree<int> tree[3];
set<int> st[3];

void modify(int p, char c) {
  int cc = s[p-1]-'a';
  if (cc == c) return;
  s[p-1] = c;
  st[cc].erase(p);
  st[c-'a'].insert(p);
  tree[cc].add(p, -1);
  tree[c-'a'].add(p, 1);
}

int f(int p, int x, int y) {
  return tree[x].query(1, p)+tree[y].query(p+1, n);
}

int fuck(int x, int y) {
  int l = 1, r = n-1, mid;
  while (l < r) {
    mid = (l+r)>>1;
    if (f(mid, x, y) < f(mid+1, x, y)) r = mid;
    else l = mid+1;
  }
  return f(l, x, y);
}

int check() {
  for (int i : {0, 1, 2}) if (st[i].empty()) return 0;
  int ans = n;
  set<int>::iterator it, l, r;
  // check a
  it = --st[2].end();
  it = st[1].upper_bound(*it);
  if (it == st[1].begin()) return 0;
  it = st[0].upper_bound(*--it);
  if (it == st[0].begin()) return 0;
  ans = min(ans, tree[0].query(1, *--it));
  #ifdef DEBUG
  cout << tree[0].query(1, *--it) << "=a\n";
  #endif
  // check b
  l = st[0].begin();
  r = --st[2].end();
  ans = min(ans, tree[1].query(*l, *r));
  #ifdef DEBUG
  cout << tree[1].query(*l, *r) << "=b\n";
  #endif
  // check c
  it = st[0].begin();
  it = st[1].lower_bound(*it);
  if (it == st[1].end()) return 0;
  it = st[2].lower_bound(*it);
  if (it == st[2].end()) return 0;
  ans = min(ans, tree[2].query(*it, n));
  #ifdef DEBUG
  cout << tree[2].query(*it, n) << "=c\n";
  #endif
  // check ab
  ans = min(ans, fuck(0, 1));
  // check ac
  ans = min(ans, fuck(0, 2));
  // check bc
  ans = min(ans, fuck(1, 2));
  return ans;
}

inline void solve() {
  cin >> n >> q >> s;
  for (int i : {0, 1, 2}) tree[i].init(n);
  for (int i = 1; i <= n; ++i) {
    int c = s[i-1]-'a';
    tree[c].add(i, 1);
    st[c].insert(i);
  }
  for (int i = 1, p; i <= q; ++i) {
    char c;
    cin >> p >> c;
    modify(p, c);
    cout << check() << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}