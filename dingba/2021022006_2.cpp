/*
 * @Author: Kaizyn
 * @Date: 2021-02-20 20:43:32
 * @LastEditTime: 2021-02-20 20:52:05
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+9;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e7+1;

int m[N];
int x[N];
set<int> st;
map<int, int> mp;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  m[0] = 0; m[1] = 1;
  for (int i = 2; i < N; ++i) {
    m[i] = m[i-1]+m[i-2];
    if (m[i] >= MOD) m[i] -= MOD;
  }
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> x[t];
    st.insert(x[t]);
  }
  for (int i = 0; i < N; ++i) {
    if (st.count(m[i]) && !mp.count(m[i])) mp[m[i]] = i;
  }
  for (int t = 1; t <= T; ++t) {
    cout << mp[x[t]] << '\n';
  }
  return 0;
}