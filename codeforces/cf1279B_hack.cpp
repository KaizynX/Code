#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dep(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
typedef long long ll;
const int maxn=(int)2e5+100;
const int mod=(int)1e9+7;
int n,s,a[maxn],sum[maxn],maxx[maxn];
void solve(){
	scanf("%d%d",&n,&s);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) sum[i]=sum[i-1]+a[i],maxx[i]=max(maxx[i-1],a[i]);
	if(sum[n]<=s) return (void)puts("0");
	int ans=0,pos=0;
	int l=1,r=n,mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if(sum[mid]-maxx[mid]>s) r=mid-1;
        else l=mid;
    }
    rep(i,1,n) if(a[i]==maxx[l]) return (void)printf("%d\n",i);
}
int main(){
	int T;cin>>T;
	while(T--) solve();
}
