/*
 * @Author: Kaizyn
 * @Date: 2021-07-17 23:27:35
 * @LastEditTime: 2021-07-17 23:53:46
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

string s;
int cnt[26];
int pi[N];

vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

string check() {
  memset(cnt, 0, sizeof cnt);
  for (char &ch : s) ++cnt[ch-'a'];
  string res;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i]) {
      res += 'a'+i;
      --cnt[i];
      break;
    }
  }
  return res;
}

inline void solve() {
  cin >> s;
  /*
  int l = 0, r = n, mid;
  while (l < r) {
    mid = (l+r)>>1;
    if (check(mid).size()) r = mid;
    else l = mid+1;
  }
  cout << check(l) << '\n';
  */
  auto z = prefix_function(s);
  for (int i : z) cout << i << ' ';
  cout << '\n';
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
baaaaa
abaaaaab
aabbaaaa
baaaaaab
abbaaaaa
baaaaaaaabb
*/