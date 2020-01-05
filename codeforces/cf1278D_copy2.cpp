#include <bits/stdc++.h>
using namespace std;
typedef long long ll; // typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=1000010;
const int inf=1e9;
const int mod=1000000007;
//#define int ll
#define l first
#define r second
pii a[N];
vector<pii> stk;
vector<int> w;
inline bool cross(pii a,pii b){
	return b.l<a.l && a.l<b.r || b.l<a.r && a.r<b.r;
}
int n;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,0,n){
		cin>>a[i].l>>a[i].r;
	}
	sort(a,a+n,[](pii a,pii b){return a.l<b.l;});
	ll sum=0;
	repeat(i,0,n){
		sum+=a[i].r-a[i].l-1;
		if(!stk.empty() && a[i].l>stk.back().r)
			cout<<"NO"<<endl,exit(0);
		int m=-1;
		int cnt=0;
		while(!stk.empty() && cross(stk.back(),a[i])){
			m=max(m,stk.back().r);
			if(a[i].l<w.back())cout<<"NO"<<endl,exit(0);
			cnt+=a[i].l<w.back();
			stk.pop_back();
			w.pop_back();
		}
		if(cnt>=2)cout<<"NO"<<endl,exit(0);
		if(!stk.empty() && a[i].l<w.back() && a[i].r>w.back()){
			m=max(m,w.back());
			w.back()=a[i].r;
		}
		stk.push_back(a[i]);
		w.push_back(m);
	}
	if(stk.size()>1)cout<<"NO"<<endl,exit(0);
	cout<<"YES"<<endl;
	return 0;
}
