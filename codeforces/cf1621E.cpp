/*
 * @Author: Kaizyn
 * @Date: 2022-01-03 23:48:28
 * @LastEditTime: 2022-01-04 00:13:19
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
int a[N], ave[N], dis[N];
ll s[N];
vector<int> b[N];
BinaryIndexedTree<int> cnt, c_1, c0;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; ++i) a[i] = a[i + n - m];
  for (int i = 1, k; i <= m; ++i) {
    cin >> k;
    b[i].resize(k);
    s[i] = 0;
    for (int j = 0; j < k; ++j) {
      cin >> b[i][j];
      s[i] += b[i][j];
    }
    ave[i] = (s[i] + k - 1) / k;
    cnt.add(ave[i], 1);
  }
  int ans = 1, cnt_1 = 0;
  for (int i = 1; i <= m; ++i) {
    dis[i] = cnt.query(a[i]) - i;
    ans &= dis[i] >= 0;
    if (dis[i] == -1) c_1.add(a[i], 1), ++cnt_1;
    if (dis[i] == 0) c0.add(a[i], 1);
    if (dis[i] < -1) cnt_1 = n + m;
  }
  for (int i = 1, k; i <= m; ++i) {
    k = b[i].size() - 1;
    for (int j : b[i]) {
      int new_ave = (s[i] - j + k - 1) / k, cur_ans = ans;
      if (new_ave < ave[i]) {
        // add [new_ave, ave)
        if (c_1.query(new_ave, ave[i] - 1) == cnt_1) cur_ans = 1;
      } else if (new_ave > ave[i]) {
        // minus [ave, new_ave)
        if (c0.query(ave[i], new_ave - 1) > 0) cur_ans = 0;
      }
      cout << cur_ans;
    }
  }
  cout << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cnt.init(N - 1);
  c_1.init(N - 1);
  c0.init(N - 1);
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= m; ++i) {
      cnt.add(ave[i], -1);
      if (dis[i] == -1) c_1.add(a[i], -1);
      if (dis[i] == 0) c0.add(a[i], -1);
    }
  }
  return 0;
}