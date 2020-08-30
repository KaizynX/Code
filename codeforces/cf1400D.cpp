/*
 * @Author: Kaizyn
 * @Date: 2020-08-25 23:03:29
 * @LastEditTime: 2020-08-25 23:56:27
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e3+7;

int n;
int a[N], cnt[N], cnt2[N];
long long presum[N];

long long C(int p, int q) {
  if (p < q) return 0;
  long long res = 1;
  for (int i = 0; i < q; ++i) res *= p-i;
  for (int i = 2; i <= q; ++i) res /= i;
  return res;
}

inline void solve() {
  cin >> n;
  memset(cnt+1, 0, sizeof(int)*n);
  memset(cnt2+1, 0, sizeof(int)*n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    presum[i] = presum[i-1]-C(cnt[a[i]], 2);
    ++cnt[a[i]];
    presum[i] += C(cnt[a[i]], 2);
    // cut between i,i+1
    #ifdef DEBUG
    cout << presum[i] << " \n"[i==n];
    #endif
  }
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    res += C(cnt[i], 4);
    for (int j = i+1; j <= n; ++j) {
      res += C(cnt[i], 2)*C(cnt[j], 2);
    }
  }
  for (int i = n; i; --i) {
    // cut between i-1,i
    /*
    sufsum -= C(cnt2[a[i]], 2);
    samesum -= C(cnt2[a[i]], 2)*C(cnt[a[i]], 2);
    ++cnt2[a[i]]; --cnt[a[i]];
    sufsum += C(cnt[a[i]], 2);
    samesum += C(cnt2[a[i]], 2)*C(cnt[a[i]], 2);
    res += samesum-presum[i-1]*sufsum;
    */
    ++cnt2[a[i]]; --cnt[a[i]];
    long long d = C(cnt2[a[i]], 2)*C(cnt[a[i]], 2)-C(cnt2[a[i]], 2)*presum[i-1];
    res += d;
    #ifdef DEBUG
    cout << d << " \n"[i==1];
    #endif
  }
  cout << res << endl;
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