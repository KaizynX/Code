#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //pedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=200010;
const int inf=1e9;
const int mod=1000000007;
#define int ll
#define lb(x) (x&(-x))
struct BIT{
	ll t[N]; //一倍内存吧
	void init(){
		mst(t,0);
	}
	void add(ll x,ll k){ //位置x加上k
		//x++;
		for(;x<N;x+=lb(x))
			t[x]+=k;
	}
	ll sum(ll x){ //求[1,x]的和 //[0,x]
		//x++;
		ll ans=0;
		for(;x!=0;x-=lb(x))
			ans+=t[x];
		return ans;
	}
}bit;
priority_queue<int> q1;
priority_queue<int,vector<int>,greater<int>> q2;
int n,a[N];
void adjust(){
	if((int)q1.size()-1>q2.size()){
		q2.push(q1.top());
		q1.pop();
	}
	if(q2.size()>q1.size()){
		q1.push(q2.top());
		q2.pop();
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ni=0; int x;
	cin>>n;
	repeat(i,1,n+1)
		cin>>x,a[x]=i;
	int mid=0,rmid,dis=0,p;
	repeat(i,1,n+1){
		p=i-1-bit.sum(a[i]);
		ni+=p;
		dis+=abs(a[i]-mid);
		
		if(q1.empty() || a[i]<=q1.top())q1.push(a[i]);
		else q2.push(a[i]);
		adjust();
		// cout<<q1.size()<<' '<<q2.size()<<endl;
		
		p=bit.sum(mid);
		bit.add(a[i],1);
		
		rmid=q1.top();
		dis+=(2*p-i)*(rmid-mid);
		mid=rmid;
		// cout<<mid<<' '<<dis<<' '<<ni<<endl;
		
		int k;
		if(i%2==1)
			k=(i/2+1)*(i/2);
		else k=(i/2+1)*(i/2)/2+(i/2-1)*(i/2)/2;
		cout<<dis+ni-k<<" ";
	}
	return 0;
}
