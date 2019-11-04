#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 500010
#define mod 2147483647
#define int ll
string s;
int a[N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s;
	int cnt,ans=0;
	cnt=0;
	repeat(i,0,s.length())a[i]=-1;
	repeat(i,0,s.length()+1){
		if(i!=s.length() && s[i]=='<'){
			a[i]=max(a[i],cnt);
			cnt++;
		}
		else{
			a[i]=max(a[i],cnt);
			cnt=0;
		}
	}
	cnt=0;
	repeat_back(i,-1,s.length()){
		if(i!=-1 && s[i]=='>'){
			a[i+1]=max(a[i+1],cnt);
			cnt++;
		}
		else{
			a[i+1]=max(a[i+1],cnt);
			cnt=0;
		}
	}
	
	repeat(i,0,s.length()+1){
		//cout<<a[i];
		//if(i!=s.length())cout<<s[i];
		ans+=a[i];
	}
	//cout<<endl;
	cout<<ans<<endl;
	return 0;
}
