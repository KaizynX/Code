/*
 * @Author: Kaizyn
 * @Date: 2020-07-14 11:06:59
 * @LastEditTime: 2020-07-14 11:49:29
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

typedef pair<int, int> pii;
const int MOD = 998244353;
const int N = 1e5+7;
const int L = 1e6+7;
const int P[2] = {29, 31};
const int M[2] = {25165843, 50331653};

int n;
int nex[L], cnt[L], hash_base[2][L];
string s[N];
map<pii, int> hash_cnt;

inline void get_next(const string &s, int nex[]) {
  nex[0] = nex[1] = 0;
  for (int i = 1, j = 0; i < (int)s.size(); ++i) {
    while (j && s[i] != s[j]) j = nex[j];
    nex[i+1] = s[i] == s[j] ? ++j : 0;
  }
  /*
  #ifdef DEBUG
  cout << s << " : ";
  for (int i = 1; i <= (int)s.size(); ++i) cout << nex[i] << " \n"[i==(int)s.size()];
  #endif
  */
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> s[i];

  int hash_val[2];
  for (int i = 1, sz, ch; i <= n; ++i) {
    hash_val[0] = hash_val[1] = 0;
    sz = s[i].size();
    for (int j = sz; j; --j) {
      ch = s[i][j-1]-'a'+1;
      for (int k = 0; k < 2; ++k) {
        (hash_val[k] += ch*hash_base[k][sz-j]%M[k]) %= M[k];
      }
      #ifdef DEBUG
      // cout << i << " " << j << " " << hash_val[0] << " " << hash_val[1] << endl;
      #endif
      pii hash_key = {hash_val[0], hash_val[1]};
      ++hash_cnt[hash_key];
    }
  }
  long long res = 0;
  for (int i = 1, sz, ch; i <= n; ++i) {
    hash_val[0] = hash_val[1] = 0;
    sz = s[i].size();
    get_next(s[i], nex);
    for (int j = 1; j <= sz; ++j) {
      ch = s[i][j-1]-'a'+1;
      for (int k = 0; k < 2; ++k) {
        hash_val[k] = (hash_val[k]*P[k]+ch)%M[k];
      }
      #ifdef DEBUG
      // cout << i << " " << j << " " << hash_val[0] << " " << hash_val[1] << endl;
      #endif
      pii hash_key = {hash_val[0], hash_val[1]};
      cnt[j] = hash_cnt.count(hash_key) ? hash_cnt[hash_key] : 0;
      cnt[nex[j]] -= cnt[j];
    }
    for (int j = 1; j <= sz; ++j) {
      (res += 1ll*j*j%MOD*cnt[j]) %= MOD;
    }
    #ifdef DEBUG
    for (int j = 1; j <= sz; ++j) cout << cnt[j] << " \n"[j==sz];
    #endif
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  hash_base[0][0] = hash_base[1][0] = 1;
  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j < L; ++j) {
      hash_base[i][j] = hash_base[i][j-1]*P[i]%M[i];
    }
  }
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}