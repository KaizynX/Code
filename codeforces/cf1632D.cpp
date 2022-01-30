/*
 * @Author: Kaizyn
 * @Date: 2022-01-30 22:47:33
 * @LastEditTime: 2022-01-30 23:10:25
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
const int N = 2e5 + 7;

template <typename T, typename U = std::greater<T>>
struct ST {
  static const int NN = 31-__builtin_clz(N)+3;
  static const T INF = 1e9;
  int lg2[N];
  U cmp = U();
  T rmq[N][NN];
  ST() {
    fill(rmq[0], rmq[0]+N*NN, cmp(-INF, +INF) ? INF : -INF);
    for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
  }
  T& operator [] (const int &i) { return rmq[i][0]; }
  void init(const T &val = 0) { fill(rmq[0], rmq[0]+N*NN, val); }
  T mv(const T &x, const T &y) { return cmp(x, y); }
  /*
  // rmq[i][j] ==> [i, i+2^j-1]
  void build(T a[], const int &n) {
    for (int i = n; i; --i) {
      rmq[i][0] = a[i];
      for (int j = 1; j <= lg2[n-i+1]; ++j)
        rmq[i][j] =  mv(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
    }
  }
  T query(const int &l, const int &r) {
    if (l > r) return query(r, l);
    int k = lg2[r-l+1];
    return mv(rmq[l][k], rmq[r-(1<<k)+1][k]);
  }
  */
  // rmq[i][j] ==> [i-2^j+1, i]
  void insert(int i, T v) {
    rmq[i][0] = v;
    for (int j = 1; j <= lg2[i]; ++j)
      rmq[i][j] =  mv(rmq[i][j-1], rmq[i-(1<<(j-1))][j-1]);
  }
  void build(T a[], const int &n) {
    for (int i = 1; i <= n; ++i) {
      insert(i, a[i]);
    }
  }
  T query(const int &l, const int &r) {
    if (l < 1) return 0;
    int k = lg2[r-l+1];
    return mv(rmq[r][k], rmq[l+(1<<k)-1][k]);
  }
};

template <typename T>
struct GCD {
  T operator () (const T &x, const T &y) {
    return __gcd(x, y);
  }
};

int n;
int a[N];
ST<int, GCD<int>> stg;
// ST<int, ADD<int>> sta;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    stg.insert(i, a[i]);
    if (a[i] == 1) {
      ++ans;
    } else {
      int lastv = a[i], lastp = i, flag = 0;
      while (lastv > 0 && lastp > 0) {
        int l = 0, r = lastp - 1, mid;
        while (l < r) {
          mid = (l + r + 1) / 2;
          if (stg.query(mid, i) != lastv) {
            l = mid;
          } else {
            r = mid - 1;
          }
        }
        // (l, lastp] = lastv 
        if (i - lastp + 1 <= lastv && lastv <= i - l) {
          flag = 1;
          break;
        }
        lastv = stg.query(l, i);
        lastp = l;
      }
      if (flag) {
        stg.insert(i, 1);
        ++ans;
      }
    }
    cout << ans << " \n"[i == n];
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}