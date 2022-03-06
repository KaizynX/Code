/*
 * @Author: Kaizyn
 * @Date: 2022-02-26 19:58:57
 * @LastEditTime: 2022-02-26 20:09:32
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
#define int ll

multiset<int> st;

int op2(int x, int k) {
  auto it = st.upper_bound(x);
  for (int i = 0; i < k; ++i) {
    if (it == st.begin()) return -1;
    --it;
  }
  return *it;
}

int op3(int x, int k) {
  auto it = st.lower_bound(x);
  for (int i = 1; i < k; ++i) {
    if (it == st.end()) return -1;
    ++it;
  }
  return it == st.end() ? -1 : *it;
}

inline void solve() {
  int n;
  cin >> n;
  for (int i = 1, op, x, k; i <= n; ++i) {
    cin >> op >> x;
    if (op == 1) {
      st.insert(x);
    } else {
      cin >> k;
      if (op == 2) {
        cout << op2(x, k) << '\n';
      } else {
        cout << op3(x, k) << '\n';
      }
    }
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