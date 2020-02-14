#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dep(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
typedef long long ll;
const int maxn=(int)2e5+100;
const int mod=(int)1e9+7;
int n,x,res,ok;
char s[maxn];
ll cnt[maxn],now;
void solve(){
	scanf("%d%d%s",&n,&x,s+1);
	rep(i,1,n) cnt[i]=cnt[i-1]+(s[i]=='0'?1:-1);
	res=ok=0;
	now=cnt[n];
	rep(i,1,n){
		if(now*(x-cnt[i])<0) continue;
		if(now==0){
			if(x==cnt[i]) ok=1;continue;
		}
		if((x-cnt[i])%now==0) res++;
	}
	if(x==0) res++;
	if(ok) puts("-1");
	else printf("%d\n",res);
}
int main(){
	int T;cin>>T;
	while(T--) solve();
}
