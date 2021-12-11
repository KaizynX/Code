/*
 * @Author: Kaizyn
 * @Date: 2021-12-11 17:19:07
 * @LastEditTime: 2021-12-11 18:16:15
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n;
int cnt[26], len[5], tmp[26];
string s, ans;

void update(const string &str) {
  #ifdef DEBUG
  cout << "update:" << str << '\n';
  #endif
  if (str.size() < ans.size()) return;
  if (str.size() > ans.size()) ans = str;
  else ans = min(ans, str);
}

string giao1() {
  string str, rev;
  for (int i = 0; i < 26; ++i) {
    str += string(cnt[i] / 4, 'a' + i);
  }
  rev = str;
  reverse(rev.begin(), rev.end());
  str += rev;
  str += str;
  return str;
}

/*
string giao2() {
  string str, rev;
  int flag = -1;
  for (int i = 0; i < 26; ++i) {
    if (flag == -1 && cnt[i] % 4 >= 2) {
      flag = i;
      str += string((cnt[i] - 2) / 4, 'a' + i);
    } else {
      str += string(cnt[i] / 4, 'a' + i);
    }
  }
  if (flag == -1) {
    if (str.empty()) return "";
    flag = str.back() - 'a';
    str.pop_back();
  }
  rev = str;
  str += 'a' + flag;
  reverse(rev.begin(), rev.end());
  str += rev;
  str += str;
  return str;
}
*/

string giao2() {
  string str, rev;
  int flag = -1;
  for (int i = 0; i < 26; ++i) {
    if (flag == -1 && cnt[i] % 4 >= 2) flag = i;
    str += string(cnt[i] / 4, 'a' + i);
  }
  if (flag == -1) {
    if (str.empty()) return "";
    flag = str.back() - 'a';
    str.pop_back();
  }
  rev = str;
  str += 'a' + flag;
  reverse(rev.begin(), rev.end());
  str += rev;
  str += str;
  return str;
}

string wuwu(const string &str, int x) {
  #ifdef DEBUG
  cout << "wuwu:" << str << ' ' << char('a' + x) << '\n';
  #endif
  int n = str.size();
  for (int i = 1; i < n; ++i) {
    if (str[i-1] == 'a' + x && str[i-1] > str[i]) {
      return str.substr(0, i - 1) + str.substr(i);
    }
  }
  for (int i = n-1; i >= 0; --i) {
    if (str[i] == 'a' + x) {
      return str.substr(0, i) + str.substr(i + 1);
    }
  }
  return "";
}

inline void solve() {
  cin >> s;
  n = s.size();
  for (char c : s) ++cnt[c - 'a'];
  // n even, n/2 even
  // ans = giao1();
  update(giao1());
  // n even, n/2 odd
  update(giao2());
  // n odd, n/2 even
  for (int i = 0; i < 26; ++i) if (cnt[i] % 4 == 3) {
    ++cnt[i];
    update(wuwu(giao1(), i));
    --cnt[i];
  }
  // n odd, n/2 odd
  for (int i = 0; i < 26; ++i) if (cnt[i] % 4 % 2 == 1) {
    ++cnt[i];
    update(wuwu(giao2(), i));
    --cnt[i];
  }
  cout << ans << '\n';
}

signed main() {
// #ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// #endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}