/*
 * @Author: Kaizyn
 * @Date: 2021-09-18 15:14:33
 * @LastEditTime: 2021-09-18 15:33:10
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
const int N = 5e2+7;

int n, m, k;
int a[N][N], l[N], r[N];

struct Node {
  int x, y;
  bool operator <(const Node &b) const {
    return a[x][y] < a[b.x][b.y];
  }
};

inline void solve() {
  priority_queue<Node> q;
  priority_queue<int, vector<int>, greater<int>> qv;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
    sort(a[i]+1, a[i]+m+1);
  }
  int sl = 0, sr = 0;
  ll cur = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
    sl += l[i];
    sr += r[i];
    for (int j = 0; j < l[i]; ++j) {
      cur += 2*a[i][m-j];
      qv.push(a[i][m-j]);
      if ((int)qv.size() > k) cur -= qv.top(), qv.pop();
    }
    q.push(Node{i, m-l[i]});
  }
  ans = cur;
  #ifdef DEBUG
  cout << cur << ' ';
  #endif
  for (int i = sl+1, x, y; i <= sr; ++i) {
    x = q.top().x;
    y = q.top().y;
    q.pop();
    cur += 2*a[x][y];
    qv.push(a[x][y]);
    if ((int)qv.size() > k) cur -= qv.top(), qv.pop();
    #ifdef DEBUG
    cout << cur << " \n"[i == sr];
    #endif
    ans ^= cur;
    if (--y <= m-r[x]) continue;
    q.push(Node{x, y});
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
  }
  return 0;
}