/*
 * @Author: Kaizyn
 * @Date: 2020-08-01 13:30:59
 * @LastEditTime: 2020-08-01 13:56:09
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e2+7;
using Node = bitset<26>;

int n;
Node var[26];
map<string, Node> fld[26];
string opl[N], opr[N];

/*
Node& fuck(const string &str) {
  char ch = str[0];
  if (str.size() == 1) {
    if (ch >= 'a' && ch <= 'z') return obj[ch-'a'];
    else return var[ch-'A'];
  }
  string name = str.substr(2);
  return fld[ch-'A'][name];
}
*/

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> opl[i] >> opr[i] >> opr[i];
  }
  for (int t = 1; t <= n; ++t) {
    for (int i = 1; i <= n; ++i) {
      static string str;
      int lhs = opl[i][0]-'A';
      int rhs = opr[i][0]-'A';
      if (opl[i].size() > 1) {
        str = opl[i].substr(2);
        for (int j = 0; j < 26; ++j) if (var[lhs][j]) {
          fld[j][str] |= var[rhs];
        }
      } else if (opr[i].size() > 1) {
        str = opr[i].substr(2);
        for (int j = 0; j < 26; ++j) if (var[rhs][j]) {
          var[lhs] |= fld[j][str];
        }
      } else {
        if (opr[i][0] >= 'a' && opr[i][0] <= 'z') var[lhs][opr[i][0]-'a'] = 1;
        else var[lhs] |= var[rhs];
      }
    }
  }
  for (int i = 0; i < 26; ++i) {
    cout << char('A'+i) << ": ";
    for (int j = 0; j < 26; ++j) {
      if (var[i][j]) cout << char('a'+j);
    }
    cout << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // for (int i = 0; i < 26; ++i) obj[i][i] = 1;
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}