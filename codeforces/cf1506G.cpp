/*
 * @Author: Kaizyn
 * @Date: 2021-03-25 22:30:54
 * @LastEditTime: 2021-03-25 22:55:55
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n;
string s;
int suf[N];
vector<int> pos[26];

inline void solve() {
  cin >> s;
  n = s.size();
  suf[n] = 0;
  for (int i = 0; i < 26; ++i) pos[i].clear();
  for (int i = n-1, c; i >= 0; --i) {
    c = s[i]-'a';
    suf[i] = suf[i+1]|(1<<c);
    pos[c].emplace_back(i);
  }
  int all = suf[0], m = __builtin_popcount(all);
  string res;
  for (int p = 0; m; --m) {
    for (int i = 25; i >= 0; --i) if ((all>>i)&1) {
      while (pos[i].size() && pos[i].back() < p) pos[i].pop_back();
      if (pos[i].size() && __builtin_popcount(suf[pos[i].back()]&all) == m) {
        res += 'a'+i;
        p = pos[i].back()+1;
        all ^= 1<<i;
        break;
      }
    }
  }
  cout << res << '\n';
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
6
codeforces
aezakmi
abacaba
convexhull
swflldjgpaxs
myneeocktxpqjpz

odfrces
ezakmi
cba
convexhul
wfldjgpaxs
myneocktxqjpz
*/