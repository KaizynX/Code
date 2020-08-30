/*
 * @Author: Kaizyn
 * @Date: 2020-08-27 18:34:19
 * @LastEditTime: 2020-08-27 20:00:27
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;
const int P = 31;
const int M = 50331653;

int n;
string s[N];
int cnt[N][26], hash_val[N];
map<int, int> mp[26];

void add(const int &x) {
  for (int i = 0; i < 26; ++i) if (cnt[x][i]) ++mp[i][hash_val[x]];
}

void del(const int &x) {
  for (int i = 0; i < 26; ++i) if (cnt[x][i]) --mp[i][hash_val[x]];
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  sort(s+1, s+n+1, [](const string &s1, const string &s2) {
    return s1.size() < s2.size();
  });
  for (int i = 1; i <= n; ++i) {
    for (const char &c : s[i]) ++cnt[i][c-'a'];
    add(i);
  }
  long long res = 0;
  for (int i = 1, l = 0; i <= n; ++i) {
    int nl = s[i].size()-1;
    if (l < nl) for (int j = i; j <= n; ++j) {
      del(j);
      for (int k = l+1; k <= nl; ++k) {
        hash_val[j] = (hash_val[j]*P+s[j][s[j].size()-k]-'a')%M;
        --cnt[j][s[j][s[j].size()-k]-'a'];
      }
      add(j);
    }
    l = nl;
    del(i);
    res += mp[s[i][0]-'a'][hash_val[i]];
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}