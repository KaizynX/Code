/*
 * @Author: Kaizyn
 * @Date: 2022-03-05 13:31:19
 * @LastEditTime: 2022-03-05 14:00:21
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

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e3 + 7;

int n, q, beg;
int a[N * N + N];
int col[N], row[N];
string str;

#ifdef DEBUG
void print() {
  cout << "***********\n";
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      cout << a[beg + i * n + j];
    }
    cout << '\n';
  }
  cout << "***********\n";
}
#endif

int query() {
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += (row[i] == n) + (col[i] == n);
  }
  return ans;
}

void update(int p, int b) {
  row[(p - beg) / n] += b - a[p];
  col[p % n] += b - a[p];
  a[p] = b;
}

inline void solve() {
  cin >> n >> q;
  for (int i = 0, p = n * n - 1; i < n; ++i) {
    cin >> str;
    for (int j = 0; j < n; ++j, --p) {
      a[p] = str[j] - '0';
      row[p / n] += a[p];
      col[p % n] += a[p];
    }
  }
  for (int _ = q, op, x, y, b; _; --_) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> b;
      x = n - x;
      y = n - y;
      update(x * n + y + beg, b);
    } else {
      cin >> b;
      col[beg % n] += b - a[beg];
      a[beg + n * n] = b;
      for (int i = 0; i < n; ++i) {
        row[i] += a[beg + i * n + n] - a[beg + i * n];
      }
      ++beg;
    }
    #ifdef DEBUG
    print();
    #endif
    cout << query() << '\n';
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