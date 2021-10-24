/*
 * @Author: Kaizyn
 * @Date: 2021-10-23 12:51:00
 * @LastEditTime: 2021-10-23 13:41:07
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
const int N = 2e4+7;

int n, m;
int a[N];
unsigned k, v;
string s;

int magic(char c) {
  if (isdigit(c)) return c-'0';
  else return c-'A'+10;
}

template <typename T>
void print(T &val, int n) {
  for (int i = n-1; i >= 0; --i) {
    cout << (val>>i)%2;
  }
  cout << '\n';
}

inline void solve() {
  cin >> s;
  // while (s.front() == '0') s = s.substr(1);
  m = s.size();
  k = 0;
  for (char c : s) k = (k<<1)|(c-'0');
  cin >> s;
  n = s.size()*4;
  for (int i = 0; i < n; ++i) {
    a[i] = (magic(s[i/4])>>(3-i%4))&1;
  }
  for (int i = n; i < n+m; ++i) a[i] = 0;
  #ifdef DEBUG
  orzarr(a, n);
  #endif
  v = 0;
  for (int i = 0; i < n+m-1; ++i) {
    v = (v<<1)|a[i];
    #ifdef DEBUG
    cout << bitset<9>(v) << '\n';
    #endif
    if ((v>>(m-1))&1) v ^= k;
  }
  print(v, m-1);
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