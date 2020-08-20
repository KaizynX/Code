/*
 * @Author: Kaizyn
 * @Date: 2020-08-15 11:19:25
 * @LastEditTime: 2020-08-15 11:27:20
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n;
int sum[2][N];
string s;
vector<int> vl[N];
multiset<int> st;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> s;
  sum[0][n] = sum[1][n] = 0;
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == '?') {
      sum[0][i] = sum[0][i+1]+1;
      sum[1][i] = sum[1][i+1]+1;
    } else if (s[i] == '1') {
      sum[0][i] = 0;
      sum[1][i] = sum[1][i+1]+1;
    } else if (s[i] == '0') {
      sum[0][i] = sum[0][i+1]+1;
      sum[1][i] = 0;
    }
    vl[sum[1][i]].emplace_back(i);
    vl[sum[0][i]].emplace_back(i);
    st.insert(i);
    st.insert(i);
  }
  for (int len = 1; len <= n; ++len) {
    int res = 0, i = 0;
    for (const int &p : vl[len-1]) st.erase(st.find(p));
    multiset<int>::iterator it;
    while ((it = st.lower_bound(i)) != st.end()) {
      i = *it+len;
      ++res;
    }
    cout << res << " \n"[len==n];
  }
  return 0;
}