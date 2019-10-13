/**
 *    author:  MySakure
 *    created: 29.09.2019 22:36:44       
**/
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mk make_pair
#define ll long long

const int maxn=1e5+10;
set<pair<int,int>>s;
int ans[maxn];
int l[3*maxn],r[3*maxn];
int id;
ll cnt[10];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int x,y;
	if(m){
		cin>>x>>y;
		l[++id]=x;
		r[id]=y;
		s.insert(mk(x,y));
		s.insert(mk(y,x));
	}
	rep(i,2,m){
		int a,b;
		cin>>a>>b;
		l[++id]=a;
		r[id]=b;
		s.insert(mk(a,b));
		s.insert(mk(b,a));
	}
	if(m==0){
		cout<<-1<<endl;
		return 0;
	}
	ans[x]=1,ans[y]=2;
	for(int i=1;i<=n;++i){
		if(ans[i])continue;
		bool flag1=s.count(mk(x,i));
		bool flag2=s.count(mk(y,i));
		if(flag1&&flag2)ans[i]=3;
		else if(flag1)ans[i]=2;
		else ans[i]=1;
	}
	for(int i=1;i<=m;++i){
		if(ans[l[i]]==ans[r[i]]){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;++i)cnt[ans[i]]++;
	if(cnt[1]*cnt[2]+cnt[1]*cnt[3]+cnt[2]*cnt[3]!=m){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
