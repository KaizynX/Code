/*
 * @Author: Kaizyn
 * @Date: 2021-12-11 16:35:40
 * @LastEditTime: 2021-12-11 16:53:57
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
const int N = 1e5;
const int K = 4e4;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

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

struct Euler {
  vector<int> prime, check;
  int& operator [](const int &i) { return check[i]; }
  void init(int n) {
    prime.clear();
    check = vector<int>(n+1);
    for (int i = 2; i <= n; ++i) {
      if (!check[i]) prime.emplace_back(i), check[i] = i;
      for (const int &j : prime) {
        if (i*j > n) break;
        check[i*j] = j;
        if (i%j == 0) break;
      }
    }
  }
} E;

map<pii, int> mp;

/*
59682 60050 (12576,22261)
50604 62762 (12349,14095)
85210 87504 (26744,25039)
*/
 
inline void solve() {
  int k1 = 33503, k2 = 25799, p1, flag;
  pii pr;
  while (true) {
    mp.clear();
    // k2 = E.prime[rnd()%E.prime.size()];
    k2 = 32749;
    flag = 1;
    for (int i = 1; i <= N; ++i) {
      pr = make_pair(qpow(i, i, k1), qpow(i, i, k2));
      if (mp.count(pr)) {
        p1 = pr.first;
        cout << mp[pr] << ' ' << i << ' ' << pr << '\n';
        if (p1 == 12576 || p1 == 12349 || p1 == 26744) {
          flag = 0;
          break;
        }
      }
      mp[pr] = i;
    }
    if (flag) {
      cout << k2 << '\n';
      break;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  E.init(K);
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}