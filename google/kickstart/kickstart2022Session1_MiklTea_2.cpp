/*
 * @Author: Kaizyn
 * @Date: 2022-02-16 22:53:02
 * @LastEditTime: 2022-02-16 23:04:06
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

int n, m, p;

struct Node {
  int v;
  string b;
  bool operator < (const Node &rhs) const {
    if (v != rhs.v) return v < rhs.v;
    return b < rhs.b;
  }
};

int cnt[N], dis[N];
string str;
set<pair<int, string>> st;
set<string> sb;

string my_xor(const string &x, const string &y) {
  string z(x.size(), '0');
  for (int i = 0; i < (int)z.size(); ++i) {
    if (x[i] != y[i]) z[i] = '1';
  }
  return z;
}

inline void solve() {
  st.clear();
  sb.clear();
  cin >> n >> m >> p;
  memset(cnt, 0, sizeof(int) * p);
  for (int i = 1; i <= n; ++i) {
    cin >> str;
    for (int j = 0; j < p; ++j) {
      cnt[j] += str[j] - '0';
    }
  }
  int basev = 0;
  string baseb(p, '0');
  for (int i = 0; i < p; ++i) {
    dis[i] = abs(n - 2 * cnt[i]);
    if (cnt[i] > n - cnt[i]) {
      baseb[i] = '1';
      basev += n - cnt[i];
    } else {
      baseb[i] = '0';
      basev += cnt[i];
    }
  }
  for (int i = 1; i <= m; ++i) {
    cin >> str;
    sb.insert(my_xor(baseb, str));
  }
  #ifdef DEBUG
  orz(basev);
  orz(baseb);
  orzeach(sb);
  #endif
  st.insert({0, string(p, '0')});
  while (st.size()) {
    string b = st.begin()->second;
    int v = st.begin()->first;
    st.erase(st.begin());
    #ifdef DEBUG
    orz(b);
    orz(v);
    #endif
    if (sb.count(b) == 0) {
      cout << v + basev << '\n';
      return;
    }
    for (int i = 0; i < p; ++i) if (b[i] == '0') {
      b[i] = '1';
      st.insert({v + dis[i], b});
      b[i] = '0';
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