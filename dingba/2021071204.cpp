/*
 * @Author: Kaizyn
 * @Date: 2021-07-12 13:38:37
 * @LastEditTime: 2021-07-13 13:17:06
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
const int N = 1e6+7;

int n;
int l[N], r[N];
struct Heap{
	priority_queue<int> a,b;  // heap=a-b
	void push(int x){a.push(x);}
	void erase(int x){b.push(x);}
	int top(){
		while(!b.empty() && a.top()==b.top())
			a.pop(),b.pop();
		return a.top();
	}
	void pop(){
		while(!b.empty() && a.top()==b.top())
			a.pop(),b.pop();
		a.pop();
	}
	int top2(){ // 次大值
		int t=top(); pop();
		int ans=top(); push(t);
		return ans;
	}
	int size(){return a.size()-b.size();}
} st;

inline void solve() {
  cin >> n;
  int res = 0;
  for (int i = 1, j = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
    st.push(l[i]);
    while (st.top() > r[i]) {
      st.erase(l[j++]);
    }
    res = max(res, i-j+1);
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}