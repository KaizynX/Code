#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 100010
#define mod 998244353
#define int ll
struct node{
	int x,p;
	bool operator<(node B)const{return x<B.x;}
};
node a[N],b[N];
int pa[N],pb[N];
int n;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,0,n)cin>>a[i].x,a[i].p=i;
	repeat(i,0,n)cin>>b[i].x,b[i].p=i;
	sort(a,a+n);
	sort(b,b+n);
	repeat(i,0,n)pa[a[i].p]=pb[b[i].p]=i;
	repeat(i,0,n)
	if(a[i].x>b[i].x){
		cout<<"No"<<endl;
		return 0;
	}
	repeat(i,0,n-1){
		if(a[i].x==a[i+1].x || b[i].x==b[i+1].x
		|| a[i+1].x<=b[i].x){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	int x=0,t;
	for(t=1;;t++){
		x=b[pa[x]].p;
		if(x==0)break;
	}
	if(t!=n)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}
