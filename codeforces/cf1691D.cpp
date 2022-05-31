/*
 * @Author: Kaizyn
 * @Date: 2022-05-31 22:58:42
 * @LastEditTime: 2022-05-31 23:14:22
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

using ll = long long;
using uint = unsigned;
using pii = pair<int, int>;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e5 + 7;

/*
unordered_map<int, vector<int>> mp;
        st.build(strength);
        for (int i = 0; i < n; ++i) {
            mp[a[i]].emplace_back(i);
        }
        struct Node {
            ll lss, rss, sss, n, s;
            Node(){
                lss = rss = sss = n = s = 0;
            }
            Node(int a) {
                lss = rss = sss = s = a;
                n = 1;
            }
            Node operator + (const Node& rhs) const {
                Node res;
                res.n = n + rhs.n;
                res.s = (s + rhs.s) % mod;
                res.lss = (lss + rhs.lss + rhs.n * s) % mod;
                res.rss = (rhs.rss + rss + n * rhs.s) % mod;
                res.sss = (sss + rhs.sss + rss * rhs.n + rhs.lss * n) % mod;
                return res;
            }
        };
        function<Node(int, int)> f = [&](int l, int r) {
            if (l >= r) return Node();
            ll sum = 0;
            int mn = st.query(l + 1, r);
            int last = l - 1;
            auto &v = mp[mn];
            Node cur;
            for (auto it = lower_bound(v.begin(), v.end(), l); it != v.end() && *it < r; ++it) {
                Node tmp = f(last + 1, *it);
                sum = (sum - tmp.sss) % mod;
                cur = cur + tmp + Node(mn);
                last = *it;
            }
            Node tmp = f(last + 1, r);
            sum = (sum - tmp.sss) % mod;
            cur = cur + tmp;
            sum = (sum + cur.sss) % mod;
            ans = (ans + sum * mn) % mod;
            //cout << l << ' ' << r << '-' << sum << ' ' << cur << ' ' << mn << '\n'; /////////////
            return cur;
        };
*/

template <typename T, typename U = std::greater<T>>
struct ST {
  static const int NN = (int)log2(N)+3;
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
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y; }
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
};

int n;
int a[N];
ST<int, greater<int>> st;
unordered_map<int, vector<int>> mp;

struct Node {
  ll sum, mls, mrs;
  Node(ll val = 0) : sum(val), mls(val), mrs(val) {}
  friend Node operator + (const Node &lhs, const Node &rhs) {
    Node res;
    res.sum = lhs.sum + rhs.sum;
    res.mls = max(rhs.mls, rhs.sum + lhs.mls);
    res.mrs = max(lhs.mrs, lhs.sum + rhs.mrs);
    return res;
  }
};

Node f(int l, int r) {
  if (l > r) return Node();
  if (l == r) return Node(a[l]);
  int mx = st.query(l, r);
  auto &vec = mp[mx];
  Node cur;
  int last = l - 1;
  for (auto it = lower_bound(vec.begin(), vec.end(), l); it != v.end() && *it <= r; ++it) {
    cur = cur + f(last + 1, *it) + Node(mx);
    last = *it;
  }
  cur = cur + f(last + 1, r);
  return cur;
}

inline void solve() {
  mp.clear();
  cin >> n;
  st.build(a, n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mp[a[i]].emplace_back(i);
  }
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