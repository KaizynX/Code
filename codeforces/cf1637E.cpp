/*
 * @Author: Kaizyn
 * @Date: 2022-02-12 23:47:24
 * @LastEditTime: 2022-02-13 00:25:25
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
const int N = 3e5 + 7;

int n, m, sqr;
int a[N];
ll ans;
unordered_map<int, int> cnt;
unordered_map<int, unordered_set<int>> bad;
vector<int> light[N], heavy;

void update(int x, int y) {
  ans = max(ans, 1ll * (cnt[x] + cnt[y]) * (x + y));
  #ifdef DEBUG
  printf("udpate(%d, %d)=%lld\n", x, y, 1ll * (cnt[x] + cnt[y]) * (x + y));
  #endif
}

inline void solve() {
  cin >> n >> m;
  sqr = sqrt(n) + 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
    // bad[a[i]].emplace_back(a[i]);
    bad[a[i]].insert(a[i]);
  }
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    // bad[x].emplace_back(y);
    // bad[y].emplace_back(x);
    bad[x].insert(y);
    bad[y].insert(x);
  }
  sort(a + 1, a + n + 1);
  n = unique(a + 1, a + n + 1) - a - 1;
  for (int i = 1; i <= n; ++i) {
    /*
    auto &vec = bad[a[i]];
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    */
    if (cnt[a[i]] > sqr) {
      heavy.emplace_back(a[i]);
    } else {
      light[cnt[a[i]]].emplace_back(a[i]);
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= sqr; ++i) {
    orzeach(light[i]);
  }
  orzeach(heavy);
  #endif
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x = a[i];
    auto &bads = bad[x];
    for (int cnty = 1; cnty <= sqr; ++cnty) {
      auto it = light[cnty].rbegin();
      while (it != light[cnty].rend() && bads.count(*it)) ++it;
          // && binary_search(bad[x].begin(), bad[x].end(), *it)) ++it;
      if (it != light[cnty].rend()) {
        update(x, *it);
      }
    }
    for (auto y : heavy) {
      // if (binary_search(bad[x].begin(), bad[x].end(), y)) continue;
      if (bads.count(y)) continue;
      update(x, y);
    }
  }
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    bad.clear();
    cnt.clear();
    heavy.clear();
    for (int i = 1; i <= n; ++i) {
      light[i].clear();
    }
  }
  return 0;
}