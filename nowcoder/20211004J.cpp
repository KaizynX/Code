/*
 * @Author: Kaizyn
 * @Date: 2021-10-04 12:05:00
 * @LastEditTime: 2021-10-04 12:22:10
 */
#include <bits/stdc++.h>

#define DEBUG

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
const int N = 2e5+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { this->n = n; tr = vector<T>(n+1, 0); }
  void add(const int &x, const T &v) { for (int i = x+1; i <= n; i += i&-i) tr[i] += v; }
  // void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x+1; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n, m;
int a[N], vis[N];
vector<int> ans;
BinaryIndexedTree<int> tree;

inline bool check(int x) {
  if (a[x] == -1 || vis[x]) return false;
  int s = a[x]%n, t = x;
  if (s <= t) {
    return tree.query(s, t) == t-s;
  } else {
    return tree.query(s, n-1)+tree.query(t) == n-s+t;
  }
}

inline void solve() {
  ans.clear();
  priority_queue<pii, vector<pii>, greater<pii>> q;
  m = 0;
  cin >> n;
  tree.init(n);
  for (int i = 0; i < n; ++i) {
    vis[i] = 0;
    cin >> a[i];
    if (a[i] == -1) continue;
    ++m;
    if (a[i]%n == i) {
      q.push(pii{a[i], i});
      vis[i] = 1;
    }
  }
  while (q.size()) {
    int u = q.top().second;
    q.pop();
    tree.add(u, 1);
    ans.emplace_back(a[u]);
    int v = (u+1)%n;
    if (check(v)) {
      q.push(pii{a[v], v});
      vis[v] = 1;
    }
  }
  if ((int)ans.size() != m) return cout << "-1\n", void();
  for (int i : ans) cout << i << ' ';
  cout << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}