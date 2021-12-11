/*
 * @Author: Kaizyn
 * @Date: 2021-12-11 16:40:16
 * @LastEditTime: 2021-12-11 16:55:23
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


/*
59682 60050 (12576,22261)
50604 62762 (12349,14095)
85210 87504 (26744,25039)
*/
const int k1 = 33503, k2 = 25799, k3 = 32749;
map<pii, int> mp[2];

void init() {
  for (int i = 1, v1, v2, v3; i <= N; ++i) {
    v1 = qpow(i, i, k1);
    v2 = qpow(i, i, k2);
    v3 = qpow(i, i, k3);
    mp[0][{v1, v2}] = i;
    mp[1][{v1, v3}] = i;
  }
}
 
inline void solve() {
  int v1, v2, v3, ans;
  cout << "? " << k1 << endl;
  cin >> v1;
  if (v1 != 12576 && v1 != 12349 && v1 != 26744) {
    cout << "? " << k2 << endl;
    cin >> v2;
    ans = mp[0][{v1, v2}];
  } else {
    cout << "? " << k3 << endl;
    cin >> v3;
    ans = mp[1][{v1, v3}];
  }
  cout << "! " << ans << endl;
  cin >> ans;
  if (ans == -1) return;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  // E.init(K);
  init();
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}