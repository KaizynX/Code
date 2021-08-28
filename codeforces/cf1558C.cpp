/*
 * @Author: Kaizyn
 * @Date: 2021-08-24 23:57:10
 * @LastEditTime: 2021-08-25 00:07:14
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
const int N = 2e3+30;

int n;
int a[N];
vector<int> ans;

bool check() {
  for (int i = 1; i <= n; ++i) {
    if (a[i]%2 != i%2) return false;
  }
  return true;
}

int my_find(int x) {
  for (int i = 1; i <= n; ++i) {
    if (a[i] == x) return i;
  }
  return 0;
}

void rev(int x) {
  if (x == 1) return;
  reverse(a+1, a+x+1);
  ans.emplace_back(x);
  #ifdef DEBUG
  orzarr(a+1, n);
  #endif
}

void print() {
  cout << ans.size() << '\n';
  for (int i : ans) cout << i << ' ';
  cout << '\n';
}

inline void solve() {
  cin >> n;
  ans.clear();
  for (int i = 1; i <= n; ++i) cin >> a[i];
  if (!check()) return cout << "-1\n", void();
  for (int i = n, p; i > 1; i -= 2) {
    p = my_find(i);
    #ifdef DEBUG
    orz(1);
    #endif
    rev(p);
    p = my_find(i-1);
    #ifdef DEBUG
    orz(2);
    #endif
    rev(p-1);
    #ifdef DEBUG
    orz(3);
    #endif
    rev(p+1);
    #ifdef DEBUG
    orz(4);
    #endif
    rev(3);
    #ifdef DEBUG
    orz(5);
    #endif
    rev(i);
  }
  print();
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