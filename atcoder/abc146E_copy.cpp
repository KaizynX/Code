#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 200010
//#define mod 1000000007
#define int ll
#define inf mod
tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> t;//ºìºÚÊ÷
int a[N];
int n,mod,ans=0;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>mod;
	repeat(i,1,n+1)cin>>a[i],a[i]--;
	int flag=false;
	t.insert({0,0});
	repeat(i,1,n+1){
		a[i]+=a[i-1]; a[i]%=mod;
		ans+=abs(
		t.order_of_key({a[i]+1,-1})
		-t.order_of_key({a[i],i-mod+1})
		);
		t.insert({a[i],i});
	}
	cout<<ans<<endl;
	return 0;
}
