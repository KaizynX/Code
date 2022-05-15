/*
 * @Author: Kaizyn
 * @Date: 2022-05-15 19:59:08
 * @LastEditTime: 2022-05-15 20:32:50
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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e5 + 7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { this->n = n; tr = vector<T>(n+1, 0); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n;
int l[N], r[N];
char s[N];
BinaryIndexedTree<int> tree;

inline void solve() {
  cin >> n >> (s + 1);
  tree.init(n);
  for (int i = 1; i <= n; ++i) {
    l[i] = i - 1;
    r[i] = i + 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; ) {
    int id = i - tree.query(1, i);
    int j = r[i], k = r[j];
    if (j > n || k > n) break;
    if (s[i] == 'A' && s[j] == 'R' && s[k] == 'C') {
      ++ans;
      if (id & 1) {
        s[j] = 'C';
        // del k
        r[j] = r[k];
        l[r[k]] = j;
        tree.add(k, 1);
        i = r[k];
      } else {
        s[i] = 'R';
        // del j,k
        r[i] = r[k];
        l[r[k]] = i;
        tree.add(j, 1);
        tree.add(k, 1);
        if (l[i]) i = l[i];
      }
    } else {
      i = r[i];
    }
  }
  cout << ans << '\n';
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