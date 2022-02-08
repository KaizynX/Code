/*
 * @Author: Kaizyn
 * @Date: 2022-02-06 22:54:42
 * @LastEditTime: 2022-02-06 23:59:49
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
const int N = 1e3 + 7;

inline int query(int i, int j, int k) {
  cout << "? " << i << " " << j << " " << k << endl;
  cin >> i;
  return i;
}

inline void solve() {
  int n, a = -1, b = -1, c = -1, q[5];
  cin >> n;
  for (int i = 1; i <= 4; ++i) {
    q[i] = query(1 + (i <= 1), 2 + (i <= 2), 3 + (i <= 3));
  }
  int mx = *max_element(q + 1, q + 5);
  for (int i = 1; i <= 4 && a == -1; ++i) {
    for (int j = i + 1; j <= 4 && a == -1; ++j) {
      int val = INF;
      for (int k = 1; k <= 4; ++k) {
        if (k == i || k == j) continue;
        val = min(val, q[k]);
        c = k;
      }
      if (val == mx) {
        a = i;
        b = j;
      }
    }
  }
  for (int i = 5, val, cka, ckb, flag = 2; i <= n; ++i) {
    val = query(a, b, i);
    if (val <= mx) continue;
    mx = val;
    ckb = query(a, c, i);
    if (flag) {
      --flag;
      cka = query(c, b, i);
      if (ckb < mx) c = a, a = i;
      else if (cka < mx) c = b, b = i;
      else {
        swap(a, c);
        b = i;
      }
    } else {
      if (ckb < mx) c = a, a = i;
      else c = b, b = i;
    }
  }
  cout << "! " << a << " " << b << endl;
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
/*
2 1 3 4 0
1 1 1 1 0 2
1 0 1 1
1 1 0 1
1 3 3 3 0
0 1 1 1 2
1 1 1 1 0 2
1 1 1 1 2 0
*/