/*
 * @Author: Kaizyn
 * @Date: 2021-08-24 15:08:41
 * @LastEditTime: 2021-08-24 15:34:04
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
const int N = 3e4+7;

struct TireTree {
  static const int NN = 3e5+7;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], cnt;
  int ed[NN], pre[26][26], vis[26];
  TireTree(char _beg = 'a') : beg(_beg) { clear(); }
  void clear() {
    memset(nex, 0, sizeof nex);
    cnt = 0;
  }
  void insert(const string &s, int id) {
    int len = s.size(), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    ed[p] = id;
  }
  bool query(const string &s, int id) {
    int len = s.size(), p = 0;
    memset(pre, 0, sizeof pre);
    memset(vis, 0, sizeof vis);
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (vis[c]) {
        for (int j = 0; j < 26; ++j) if (j != c && nex[p][j]) {
          if (pre[c][j]) return false;
        }
      } else {
        for (int j = 0; j < 26; ++j) if (nex[p][j] && j != c) {
          pre[j][c] = 1;
        }
        vis[c] = 1;
      }
      p = nex[p][c];
      if (ed[p]) {
        if (ed[p] != id) return false;
        break;
      }
    }
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) if (pre[i][j]) {
        ++vis[j];
      }
    }
    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
      if (vis[i] == 0) q.push(i);
    }
    while (q.size()) {
      int u = q.front();
      q.pop();
      ++cnt;
      for (int v = 0; v < 26; ++v) if (pre[u][v]) {
        if (--vis[v] == 0) q.push(v);
      }
    }
    return cnt == 26;
  }
};

int n;
int check[N];
string s[N];
TireTree tree;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    tree.insert(s[i], i);
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    check[i] = tree.query(s[i], i);
    cnt += check[i];
  }
  cout << cnt << '\n';
  for (int i = 1; i <= n; ++i) if (check[i]) {
    cout << s[i] << '\n';
  }
  return 0;
}