/*
 * @Author: Kaizyn
 * @Date: 2021-11-23 22:34:10
 * @LastEditTime: 2021-11-23 23:10:40
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
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n, m;
int a[N];
vector<int> p[N];
BinaryIndexedTree<int> tree;

bool check(int x) {
  if (p[x].empty()) return false;
  auto l = p[x].begin(), r = --p[x].end();
  while (l <= r) {
    if (tree.query(1, *l) != tree.query(*r, n)) return false;
    ++l; --r;
  }
  return true;
}

void my_insert(int x) {
  for (int i : p[x]) tree.add(i, 1);
}

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]].emplace_back(i);
  }
  m = 0;
  for (int i = 1; i <= n; ++i) m += !p[i].empty();
  tree.init(n);
  my_insert(a[1]);
  int cnt = 1;
  for (int i = 1; i <= n; ++i) if (i != a[1]) {
    if (check(i)) {
      my_insert(i);
      ++cnt;
    }
  }
  if (cnt >= m-1) return true;
  tree.init(n);
  cnt = 0;
  for (int i = 1; i <= n; ++i) if (i != a[1]) {
    if (check(i)) {
      my_insert(i);
      ++cnt;
    }
  }
  if (cnt >= m-1) return true;
  return false;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << '\n';
    for (int i = 1; i <= n; ++i) p[i].clear();
  }
  return 0;
}