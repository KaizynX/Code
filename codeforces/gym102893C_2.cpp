/*
 * @Author: Kaizyn
 * @Date: 2022-04-04 14:11:47
 * @LastEditTime: 2022-04-04 14:39:53
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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e5 + 7;

int sss(int &a, int &b) {
    int t = min(a, b);
    a -= t;
    b -= t;
    return t;
}
int sss(int &a, int &b, int &c) {
    int t = min({a, b, c});
    a -= t;
    b -= t;
    c -= t;
    return t;
}
struct AA {
    int a, b, k;
    friend AA operator+(AA x, AA y) {
        int kk = sss(x.a, y.b) +
            sss(x.b, y.a) +
            sss(x.a, x.b, y.k) +
            sss(y.a, y.b, x.k);
        return {x.a + y.a, x.b + y.b, x.k + y.k + kk};
    }
};

int n;
int aa[N], bb[N];

struct seg{
	#define U(a,b) (a+b) //查询操作
	AA a0 = AA{0, 0, 0}; //查询操作的零元
	int n; AA a[1024*1024*4*2]; //内存等于2^k且大于等于两倍inn
	void init(int inn){ //建树
		for(n=1;n<inn;n<<=1);
		repeat(i,0,inn)a[n+i]=AA{aa[i], bb[i], 0};
		repeat(i,inn,n)a[n+i]=a0;
		repeat_back(i,1,n)up(i);
	}
	void up(int x){
		a[x]=U(a[x<<1],a[(x<<1)^1]);
	}
  /*
	void update(int x,ll k){ //位置x加上k
		a[x+=n]+=k; //也可以赋值等操作
		while(x>>=1)up(x);
	}
  */
	AA query(int l,int r){ //区间查询
    if (l > r) return a0;
		AA ans=a0;
		for(l+=n-1,r+=n+1;l^r^1;l>>=1,r>>=1){
			if(~l & 1)ans=U(ans,a[l^1]); //l^1其实是l+1
			if(r & 1)ans=U(ans,a[r^1]); //r^1其实是r-1
		}
		return ans;
	}
}tr;


inline bool solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> aa[i];
  for (int i = 1; i <= n; ++i) cin >> bb[i];
  tr.init(n + 1);
  for (int i = 1; i <= n; ++i) {
    AA q = AA{aa[i], 0, 0} + tr.query(1, i - 1) + tr.query(i + 1, n);
    #ifdef DEBUG
    cout << q.a << ' ' << q.b << ' ' << q.k << '\n';
    #endif
    if (q.b == 0) return true;
  }
  return false;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}