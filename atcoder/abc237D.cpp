/*
 * @Author: Kaizyn
 * @Date: 2022-01-30 19:55:51
 * @LastEditTime: 2022-01-30 20:11:37
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
const int N = 5e5 + 7;

int n;
string s;
int L[N], R[N];

void my_insert(int p, int x) {
  int q = R[p];
  R[p] = x;
  L[x] = p;
  L[q] = x;
  R[x] = q;
}

inline void solve() {
  cin >> n >> s;
  /*
  for (int i = 0; i <= n; ++i) {
    L[i] = R[i] = n + 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == 'L') {
      my_insert(L[i - 1], i);
    } else {
      my_insert(i - 1, i);
    }
  }
  for (int ) {
    ;
  }
  */
  list<int> l;
  l.push_back(0);
  auto it = l.begin();
  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == 'L') {
      it = l.insert(it, i);
    } else {
      it = l.insert(++it, i);
    }
  }
  for (int x : l) cout << x << ' ';
  /*
  it = ++l.begin();
  while (it != l.end()) {
    cout << *it << ' ';
    ++it;
  }
  */
  cout << '\n';
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