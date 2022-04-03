/*
 * @Author: Kaizyn
 * @Date: 2022-03-30 13:48:40
 * @LastEditTime: 2022-03-30 13:53:32
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
const int N = 1e5 + 7;

int L, n;
int has[N];
string str;
vector<int> pos[26][N];

bool check(vector<int> &vec, int beg) {
  if (vec.size() <= 1u) return true;
  int all = (1 << 26) - 1;
  for (int i : vec) all &= has[i];
  map<vector<int>, vector<int>> mp;
  for (int i = beg; i < 26; ++i) {
  }
}

inline void solve() {
  cin >> L >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> str;
    for (int j = 0; j < L; ++j) {
      int c = str[j] - 'a';
      has[i] |= 1 << c;
      pos[c][i].emplace_back(j);
    }
  }
  vector<int> tmp(n);
  iota(tmp.begin(), tmp.end(), 1);
  cout << (check(tmp, 0) ? "YES" : "NO") << '\n';
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