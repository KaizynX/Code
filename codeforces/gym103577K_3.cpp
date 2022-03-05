/*
 * @Author: Kaizyn
 * @Date: 2022-03-05 14:30:51
 * @LastEditTime: 2022-03-05 17:19:41
 */
#include <bits/stdc++.h>

// #define DEBUG

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

#define int ll
typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 4e5 + 7;

struct Node {
  int x, y, id;
  bool operator < (const Node &rhs) const {
    return x < rhs.x;
  }
};

struct zkw {
    ll U(ll x, ll y) { return x < y ? x : y; }
    const ll a0 = INF;
    int n; ll a[N * 4];
    void init(int inn, ll in[] = nullptr) { // A[x] = a0 or in[x]
        n = 1; while (n < inn) n <<= 1;
        fill(a + n, a + n * 2, a0);
        if (in) repeat (i, 0, inn) a[n + i] = in[i];
        repeat_back (i, 1, n) up(i);
    }
    void up(int x) { // private
        a[x] = U(a[x * 2], a[x * 2 + 1]);
    }
    void assign(int x, ll k) { // A[x] = k
        a[x += n] = k;
        while (x >>= 1) up(x);
    }
    void add(int x, ll k) { // A[x] += k
        x += n;
        a[x] = min(a[x], k);
        while (x >>= 1) up(x);
    }
    ll query(int l, int r) { // U(A[l, r])
        ll ans = a0; l += n - 1, r += n + 1;
        while (l + 1 < r){
            if (~l & 1) ans = U(ans, a[l + 1]);
            if ( r & 1) ans = U(ans, a[r - 1]);
            l >>= 1, r >>= 1;
        }
        return ans;
    }
} tree_a, tree_m;

int n, m;
Node fd[N], le[N];
int ans[N];
vector<int> set_y;

void update(int &x, int y) {
  if (x == -1 || y < x) x = y;
}

template <typename T>
void work(int k, T cmp) {
  int A = set_y.size();
  tree_a.init(A + 1);
  tree_m.init(A + 1);
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j <= m && cmp(fd[j].x, le[i].x)) {
      tree_a.add(fd[j].y, -k * fd[j].x + set_y[fd[j].y - 1]);
      tree_m.add(fd[j].y, -k * fd[j].x - set_y[fd[j].y - 1]);
      ++j;
    }
    update(ans[le[i].id], k * le[i].x - set_y[le[i].y - 1] + tree_a.query(le[i].y, A));
    update(ans[le[i].id], k * le[i].x + set_y[le[i].y - 1] + tree_m.query(1, le[i].y));
  }
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> le[i].x >> le[i].y;
    le[i].id = i;
    ans[i] = -1;
    set_y.emplace_back(le[i].y);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> fd[i].x >> fd[i].y;
    fd[i].id = i;
    set_y.emplace_back(fd[i].y);
  }
  sort(set_y.begin(), set_y.end());
  set_y.erase(unique(set_y.begin(), set_y.end()), set_y.end());
  for (int i = 1; i <= n; ++i) {
    le[i].y = lower_bound(set_y.begin(), set_y.end(), le[i].y) - set_y.begin() + 1;
  }
  for (int i = 1; i <= m; ++i) {
    fd[i].y = lower_bound(set_y.begin(), set_y.end(), fd[i].y) - set_y.begin() + 1;
  }
  sort(le + 1, le + n + 1);
  sort(fd + 1, fd + m + 1);
  work(1, [](int x, int y) { return x <= y; });
  #ifdef DEBUG
  orzarr(ans + 1, n);
  #endif
  reverse(le + 1, le + n + 1);
  reverse(fd + 1, fd + m + 1);
  work(-1, [](int x, int y) { return x >= y; });
  #ifdef DEBUG
  orzarr(ans + 1, n);
  #endif
  ll sum = accumulate(ans + 1, ans + n + 1, 0ll);
  cout << sum << '\n';
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