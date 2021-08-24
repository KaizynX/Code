/*
 * @Author: Kaizyn
 * @Date: 2021-08-24 14:51:06
 * @LastEditTime: 2021-08-24 14:59:03
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
const int N = 3e5+7;

struct TireTree {
  static const int NN = N;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], cnt;
  int ed[NN], has[NN];
  TireTree(char _beg = 'a') : beg(_beg) { clear(); }
  void clear() {
    memset(nex, 0, sizeof nex);
    cnt = 0;
  }
  void insert(const string &s, int id) {
    int len = s.size(), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) {
        nex[p][c] = ++cnt;
        has[p] |= 1<<c;
      }
      p = nex[p][c];
    }
    ed[p] = id;
  }
  bool query(const string &s, int id) {
    static int pre[26];
    int len = s.size(), p = 0, vis = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if ((vis>>c)&1) {
        if (has[p]&pre[c]) return false;
      } else {
        for ()
        pre[c] = vis;
        vis |= 1<<c;
      }
      p = nex[p][c];
      if (ed[p]) return ed[p] == id;
    }
    return true;
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