/*
 * @Author: Kaizyn
 * @Date: 2021-03-08 11:38:52
 * @LastEditTime: 2021-03-08 13:07:27
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
const int N = 1e5+7;

int n, k;
int cnt[26];
string s;

inline bool check(int mid) { // keep[1, mid]
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= mid; i++) {
    ++cnt[s[i]-'a'];
  }
  int num = 0;
  for (int i = 0; i < 26; ++i) {
    cnt[i] %= k;
    if (cnt[i]) cnt[i] = k-cnt[i];
    num += cnt[i];
  }
  num = n-mid-num;
  if (num < 0 || num%k) return false;
  cnt[25] += num;
  string tmp;
  for (int i = 25; i >= 0; --i) {
    tmp += string(cnt[i], 'a'+i);
  }
  return tmp >= s.substr(mid+1);
}

string fuck(int mid) {
  if (mid == n) return s.substr(1);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= mid; i++) {
    ++cnt[s[i]-'a'];
  }
  int num = 0;
  for (int i = 0; i < 26; ++i) {
    cnt[i] %= k;
    if (cnt[i]) cnt[i] = k-cnt[i];
    num += cnt[i];
  }
  num = n-mid-num;
  string res = s.substr(1, mid);
  for (int i = s[mid+1]+1-'a'; i < 26; ++i) {
    if (cnt[i]) {
      res += 'a'+i;
      --cnt[i];
      break;
    } else if (num) {
      res += 'a'+i;
      cnt[i] += k-1;
      num -= k;
      break;
    }
  }
  cnt[0] += num;
  for (int i = 0; i < 26; ++i) {
    res += string(cnt[i], 'a'+i);
  }
  return res;
}

inline void solve() {
  cin >> n >> k >> s;
  if (n%k || !check(0)) return cout << -1 << '\n', void();
  s = "#"+s;
  int l = 0, r = n, mid;
  while (l < r) {
    mid = (l+r+1)>>1;
    if (check(mid)) l = mid;
    else r = mid-1;
  }
  cout << fuck(l) << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
16 8
cadjfdsljfdkljds
*/