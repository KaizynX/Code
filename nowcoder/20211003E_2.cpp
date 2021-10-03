/*
 * @Author: Kaizyn
 * @Date: 2021-10-03 13:05:25
 * @LastEditTime: 2021-10-03 14:06:50
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
const int N = 1e6+7;

template<typename string>
struct Hash{
    template<int b,int mod,int x=101>
    struct hs{
        vector<int> a,p;
        hs(const string &s=""){
            a={0},p={1};
            for(auto c:s){
                a.push_back((1ll*a.back()*b+(c^x))%mod);
                p.push_back(1ll*p.back()*b%mod);
            }
        }
        ll q(int l,int r){
            return (a[r+1]-1ll*a[l]*p[r-l+1]%mod+mod)%mod;
        }
        ll q2(int l,int r){ // 循环字符串
            // if(l<=r)return q(l,r); 
            return (a[r+1]+q(l,a.size()-2)*p[r+1])%mod;
        }
    };
    hs<257,1000000021> h1;
    hs<233,2147483647> h2;
    Hash(const string &s):h1(s),h2(s){}
    // Hash(const string &s):h1(s){}
    ll query(int l,int r){
        // return {h1.q(l,r),h2.q(l,r)};
        return (h1.q(l,r)<<32)+h2.q(l,r);
        // return h1.q(l,r);
    }
    ll query2(int l,int r){ // 循环字符串
        // return {h1.q2(l,r),h2.q2(l,r)};
        return (h1.q2(l,r)<<32)+h2.q2(l,r);
        // return h1.q2(l,r);
    }
};

int n;
string s;
vector<int> res[N];

template<typename A,typename B>
struct unmap{
    struct node{
        A u; B v; int nxt;
    };
    static const unsigned uN=20000003;
    vector<node> e;
    int head[uN];
    unmap(){clear();}
    void clear(){memset(head,-1,sizeof head); e.clear();}
    bool count(A u){
        int h=u%uN;
        for(int i=head[h];~i;i=e[i].nxt)
            if(e[i].u==u)return 1;
        return 0;
    }
    B &operator[](A u){
        int h=u%uN;
        for(int i=head[h];~i;i=e[i].nxt)
            if(e[i].u==u)return e[i].v;
        e.push_back({u,B(),head[h]}); head[h]=e.size()-1;
        return e.back().v;
    }
};
unmap<ll, int> mp;

inline void solve() {
  cin >> s;
  Hash<string> hh(s);
  n = s.size();
  int cnt = 0;
  mp[hh.query(0, n-1)] = 0;
  res[0].emplace_back(0); ++cnt;
  for (int i = 1; i < n; ++i) {
    ll tmp = hh.query2(i, i-1);
    if (!mp.count(tmp)) mp[tmp] = i, ++cnt;
    res[mp[tmp]].emplace_back(i);
  }
  printf("%d\n", cnt);
  for (int i = 0; i < n; ++i) if (res[i].size()) {
    printf("%d", (int)res[i].size());
    for (int j : res[i]) printf(" %d", j);
    puts("");
  }
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