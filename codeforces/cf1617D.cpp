/*
 * @Author: Kaizyn
 * @Date: 2021-12-16 21:32:56
 * @LastEditTime: 2021-12-16 21:56:39
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
const int N = 1e4+7;

int n;
int a[N];
int ans[N];

int query(int a, int b, int c) {
  cout << "? " << a << ' ' << b << ' ' << c << endl;
  cin >> a;
  return a;
}

void answer() {
  int k = 0;
  for (int i = 1; i <= n; ++i) k += ans[i] == 0;
  cout << "! " << k;
  for (int i = 1; i <= n; ++i) if (ans[i] == 0) {
    cout << ' ' << i;
  }
  cout << endl;
}

inline void solve() {
  cin >> n;
  memset(ans + 1, -1, sizeof(int) * n);
  for (int i = 1; i + 2 <= n; ++i) {
    a[i] = query(i, i + 1, i + 2);
  }
  int p = 0;
  for (int i = 2; i + 2 <= n; ++i) {
    if (a[i] != a[i - 1]) {
      p = i;
      ans[i + 2] = a[i];
      ans[i - 1] = a[i - 1];
      break;
    }
  }
  for (int i = 1; i <= n; ++i) if (i != p - 1 && i != p + 2) {
    ans[i] = query(p - 1, p + 2, i);
  }
  answer();
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