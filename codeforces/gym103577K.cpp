/*
 * @Author: Kaizyn
 * @Date: 2022-03-05 14:30:51
 * @LastEditTime: 2022-03-05 16:52:09
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

#define int ll
typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5 + 7;

struct Node {
  int x, y, id;
  bool operator < (const Node &rhs) const {
    return x < rhs.x;
  }
  void trans() { // 切比雪夫
    x += y;
    y = x - y - y;
  }
};

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (fa[x] = y, true);
  }
};

int n, m;
Node fd[N], le[N];
int ans[N], delta_y[N];
vector<int> stk;
DSU dsu;

void update(int &x, int y) {
  if (x == -1 || y < x) x = y;
}

template <typename T>
void work(T cmp) {
  dsu.init(m);
  stk.clear();
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j <= m && cmp(fd[j].x, le[i].x)) {
      delta_y[j] = abs(fd[j].y - le[i].y);
      while (stk.size() && delta_y[stk.back()] >= delta_y[j]) {
        dsu.merge(stk.back(), j);
        stk.pop_back();
      }
      stk.push_back(j);
      ++j;
    }
    int l = 1, r = j - 1, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (abs(le[i].x - fd[mid].x) <= delta_y[dsu[mid]]) r = mid;
      else l = mid + 1;
    }
    for (int k = max(1ll, l - 3); k <= min(j - 1, l + 3); ++k) {
      update(ans[le[i].id], max(abs(le[i].x - fd[k].x), abs(le[i].y - fd[k].y)));
    }
  }
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> le[i].x >> le[i].y;
    le[i].id = i;
    le[i].trans();
    ans[i] = -1;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> fd[i].x >> fd[i].y;
    fd[i].id = i;
    fd[i].trans();
  }
  sort(le + 1, le + n + 1);
  sort(fd + 1, fd + m + 1);
  work([](int x, int y) { return x <= y; });
  #ifdef DEBUG
  orzarr(ans + 1, n);
  #endif
  reverse(le + 1, le + n + 1);
  reverse(fd + 1, fd + m + 1);
  work([](int x, int y) { return x >= y; });
  #ifdef DEBUG
  orzarr(ans + 1, n);
  #endif
  ll sum = accumulate(ans + 1, ans + n + 1, 0ll);
  cout << sum << '\n';
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