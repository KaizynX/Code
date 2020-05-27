/*
 * @Author: Kaizyn
 * @Date: 2020-05-24 21:40:45
 * @LastEditTime: 2020-05-24 22:02:02
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

int n, m;
string s;
long long a[N];

inline void print(long long x) {
  for (int i = m-1; i >= 0; --i) {
    cout << char('0'+(x/(1ll<<i)%2));
  }
  cout << endl;
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    a[i] = 0;
    for (int j = 0; j < (int)s.size(); ++j) {
      a[i] = a[i]*2+s[j]-'0';
    }
  }
  long long k = (1ll<<m)-n;
  sort(a+1, a+n+1);
  a[n+1] = 1ll<<m;
  a[0] = -1;
  long long l, r;
  long long ll = (k-1)/2, rr = k-ll-1;
  for (int i = 0; i <= n; ++i) {
    if (a[i]+1 == a[i+1]) continue;
    l = a[i]-i+1;
    r = (1ll<<m)-a[i+1]-(n-i);
    if (l > ll || r > rr) continue;
    // choose one from (a[i], a[i+1])
    print(a[i]+ll-l+1);
    break;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}