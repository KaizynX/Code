/*
 * @Author: Kaizyn
 * @Date: 2022-03-05 12:55:17
 * @LastEditTime: 2022-03-05 13:16:12
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
const int N = 1e5 + 7;

int n;
string s;
int arr1[233], arr2[233];
int *a = arr1 + 111, *ans = arr2 + 111;

int read_int(int &i) {
  int tag = 0, val = 0;
  if (s[i] == '+') {
    ++i;
  } else if (s[i] == '-') {
    tag = 1;
    ++i;
  }
  while (isdigit(s[i])) {
    val = val * 10 + s[i] - '0';
    ++i;
  }
  if (val == 0) val = 1;
  if (tag) val = -val;
  return val;
}

int read_x(int &i) {
  if (s[i] != 'x') return 0;
  ++i;
  if (s[i] != '^') return 1;
  ++i;
  return read_int(i);
}

inline void solve() {
  cin >> s;
  n = s.size();
  s += '$';
  for (int i = 0; i < n; ) {
    int k = read_int(i);
    a[read_x(i)] += k;
  }
  for (int i = -100; i <= 100; ++i) {
    ans[i - 1] = a[i] * i;
  }
  int fir = 1;
  for (int i = -101; i < 100; ++i) {
    if (ans[i] == 0) continue;
    if (ans[i] < 0) cout << '-', ans[i] = -ans[i];
    else if (!fir) cout << '+';
    fir = 0;
    if (ans[i] != 1 || i == 0) cout << ans[i];
    if (i == 0) continue;
    cout << 'x';
    if (i == 1) continue;
    cout << '^' << i;
  }
  if (fir) cout << '0';
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