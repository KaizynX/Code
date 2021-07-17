/*
 * @Author: Kaizyn
 * @Date: 2021-07-18 00:08:06
 * @LastEditTime: 2021-07-18 00:28:26
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

void print(int x) {
  if (cnt[x]) {
    cout << char('a'+x);
    --cnt[x];
  }
}

void print_all(int x) {
  while (cnt[x]) {
    cout << char('a'+x);
    --cnt[x];
  }
}

void print_all() {
  for (int i = 0; i < 26; ++i) {
    print_all(i);
  }
}

inline void solve() {
  cin >> s;
  int n = s.size();
  int c1 = -1, c2 = -1, c3 = -1, spj = -1;
  memset(cnt, 0, sizeof cnt);
  for (char &ch : s) ++cnt[ch-'a'];
  for (int i = 0; i < 26; ++i) {
    if (!cnt[i]) continue;
    if (spj == -1 && cnt[i] == 1) spj = i;
    if (c1 == -1) c1 = i;
    else if (c2 == -1) c2 = i;
    else if (c3 == -1) c3 = i;
  }
  #ifdef DEBUG
  printf("c1:%d c2:%d c3:%d spj:%d\n", c1, c2, c3, spj);
  #endif
  if (~spj) { // fmin = 0
    print(spj);
    print_all();
  } else if (c2 == -1 && c3 == -1) { // only one char
    print_all(c1);
  } // below fmin = 1
  else if (n-cnt[c1] >= cnt[c1]-2) { // begin with c1c1c*c1c*c1...
    print(c1);
    print(c1);
    for (int i = c2; i < 26; ++i) {
      while (cnt[i]) {
        print(i);
        print(c1);
      }
    }
  } else if (c3 == -1) {
    print(c1);
    print_all(c2);
    print_all();
  } else {
    print(c1);
    print(c2);
    print_all(c1);
    print(c3);
    print_all();
  }
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