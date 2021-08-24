/*
 * @Author: Kaizyn
 * @Date: 2021-08-24 16:52:36
 * @LastEditTime: 2021-08-24 16:55:15
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
const int N = 1e5+7;
const int M = 51e4+7;

struct TireTree {
  static const int NN = M;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], cnt;
  int exist[NN];
  TireTree(char _beg = 'a') : beg(_beg) {}
  void clear() { cnt = 0; }
  void insert(const string &s, int id) {
    int len = s.size(), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    exist[p] = id;
  }
  int query(const string &s, int id) {
    int len = s.size(), p = 0, last = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      p = nex[p][c];
      if (exist[p] && exist[p] != id) last = exist[p];
    }
    return last;
  }
} tree;

int n;
int num[N];
string s[N];
vector<int> e[N];

ll dfs(int u) {
  ll sum = 0, cur = 1;
  num[u] = 1;
  for (int v : e[u]) {
    sum += dfs(v);
    num[u] += num[v];
  }
  sort(e[u].begin(), e[u].end(), [&](int x, int y) {
    return num[x] < num[y];
  });
  for (int v : e[u]) {
    sum += cur;
    cur += num[v];
  }
  return sum;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    reverse(s[i].begin(), s[i].end());
    tree.insert(s[i], i);
  }
  for (int i = 1; i <= n; ++i) {
    e[tree.query(s[i], i)].emplace_back(i);
  }
  printf("%lld\n", dfs(0));
  return 0;
}