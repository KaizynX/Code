#include <bits/stdc++.h>
using namespace std;
typedef long long ll; // typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=300010;
const int inf=1e9;
const int mod=1000000007;
#define int ll
int a[N],n,ans=0;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,0,n)
		cin>>a[i];
	ll maxnull=0;
	repeat_back(i,0,n){
		if((a[i]-maxnull)%2==0){
			ans+=(a[i]-maxnull)/2;
			if(i>0)ans+=maxnull/2;
			maxnull--;
		}
		else{
			ans+=(a[i]-maxnull)/2;
			if(i>0)ans+=maxnull/2+1;
			maxnull++;
		}
		maxnull<0?maxnull=0:0;
	}
	cout<<ans<<endl;
	return 0;
}
