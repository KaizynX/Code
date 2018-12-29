#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
ll a[200005],b[200005],aa[200005];
ll ans[200005];
ll aans[200005];
int main(){
	scanf("%d",&n);
	repn(i,n){
		scanf("%lld",&a[i]);
	}
	stack<int>S;
	//Sには無限に0が入っているものとする
	b[1] = a[1];
	for(int i=2;i<=n;i++){
		ans[i] = ans[i-1];
		b[i] = a[i];
		if(b[i-1] >= b[i]){
			ll f = b[i-1]/b[i];
			while(f >= 4){
				f /= 4;
				S.push(i-1);
			}
		}
		else{
			while(b[i-1] < b[i]){
			    //cout<<b[i-1]<<" "<<b[i]<<endl;
				int x = 0;
				if(S.size()){
					x = S.top();
					S.pop();
				}
				b[i-1]*=4LL;
				ans[i] += i-1-x;
			}
		}
	}
	repn(i,n) aa[i] = a[n+1-i];
	stack<int>SS;
	b[1] = aa[1];
	//SSには無限に0が入っているものとする
	for(int i=2;i<=n;i++){
		aans[i] = aans[i-1];
		b[i] = aa[i];
		if(b[i-1] >= b[i]){
			ll f = b[i-1]/b[i];
			while(f >= 4){
				f /= 4;
				SS.push(i-1);
			}
		}
		else{
			while(b[i-1] < b[i]){
				int x = 0;
				if(SS.size()){
					x = SS.top();
					SS.pop();
				}
				b[i-1]*=4LL;
				aans[i] += i-1-x;
			}
		}
	}
	ll anss = 1e18;
	for(int i=0;i<=n;i++){
		anss = min(anss,2LL*(ans[i]+aans[n-i])+1LL*i);
	}
	cout<<anss<<endl;
}
