/*
 * @Author: Kaizyn
 * @Date: 2022-02-15 23:28:14
 * @LastEditTime: 2022-02-15 23:46:21
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
const int N = 1e2 + 7;

typedef bitset<100> bt;

int n, m, p;

struct Node {
  int v;
  bt b;
  bool operator < (const Node &rhs) const {
    return v > rhs.v;
  }
};

int cnt[N], dis[N];
string str;
set<bt> sb, vis;

inline void solve() {
  priority_queue<Node> q;
  sb.clear();
  vis.clear();
  cin >> n >> m >> p;
  for (int i = 1; i <= n; ++i) {
    cin >> str;
    for (int j = 0; j < p; ++j) {
      cnt[j] += str[p - j] - '0';
    }
  }
  int basev = 0;
  bt baseb;
  for (int i = 0; i < p; ++i) {
    dis[i] = abs(n - 2 * cnt[i]);
    if (cnt[i] > n - cnt[i]) {
      baseb[i] = 0;
      basev += n - cnt[i];
    } else {
      baseb[i] = 1;
      basev += cnt[i];
    }
  }
  for (int i = 1; i <= m; ++i) {
    cin >> str;
    sb.insert(bt(str) ^ baseb);
  }
  q.push({0, baseb});
  vis.insert(baseb);
  while (true) {
    bt b = q.top().b;
    int v = q.top().v;
    q.pop();
    if (sb.count(b) == 0) {
      cout << v + basev << '\n';
      return;
    }
    for (int i = 0; i < p; ++i) if (b[i] == 0) {
      b[i] = 1;
      if (vis.count(b) == 0) {
        q.push({v + dis[i], b});
        vis.insert(b);
      }
      b[i] = 0;
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}