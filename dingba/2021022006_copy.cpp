/*
 * @Author: Kaizyn
 * @Date: 2021-02-21 16:37:03
 * @LastEditTime: 2021-02-21 16:38:44
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,C,P,s5,U,V;
int add(int x,int y)  {return (ll)x+y>=P?(ll)x+y-P:x+y;}
int dec(int x,int y)  {return (ll)x-y< 0?(ll)x-y+P:x-y;}
int mul(int x,int y)  {return (ll)x*y>=P?(ll)x*y%P:x*y;}
int power(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=mul(a,a))  if(b&1)  ans=mul(ans,a);
	return ans;
}
int Inv(int x)  {return power(x,P-2);}
void Max(int &x,int y)  {if(x<y)x=y;}
void Min(int &x,int y)  {if(x>y)x=y;}
namespace Cipolla{
	int I,val;
	struct num{
		int x,y;
		num(int x=0,int y=0):x(x),y(y){}
		friend num operator*(const num &a,const num &b){
			return num(add(mul(a.x,b.x),mul(val,mul(a.y,b.y))),add(mul(a.y,b.x),mul(a.x,b.y)));
		}
		friend num operator^(num a,int b){
			num ans(1,0);
			for(;b;b>>=1,a=a*a)  if(b&1)  ans=ans*a;
			return ans;
		}
	};
	int Sqrt(int n){
		if(!n)  return 0;
		if(power(n,(P-1)>>1)==P-1)  return -1;
		while(1){
			I=rand(),val=dec(mul(I,I),n);
			if(power(val,(P-1)>>1)==P-1)  break;
		}
		return (num(I,1)^((P+1)>>1)).x;
	}
}
using Cipolla::Sqrt;
unordered_map<int,int>Hash;
int BSGS(int a,int b,int type){
	Hash.clear();
	int now=b,t=ceil(sqrt(P));
	for(int i=0;i<t;++i)  Hash[now]=i,now=mul(now,a);
	now=1,a=power(a,t);
	if(!a)  return b?P+1:1;
	for(int i=0,pos;i<=t;++i){
		pos=(Hash.find(now)==Hash.end())?-1:Hash[now],now=mul(now,a);
		if(pos>=0&&i*t-pos>=0&&((i*t-pos)&1)==type)  return i*t-pos;
	}
	return P+1;
}
int main(){
  P = 1e9+9;
	scanf("%d",&T);
	while(T--){
		// scanf("%d%d",&C,&P);
		scanf("%d",&C);
		s5=Sqrt(5),U=mul(add(1,s5),Inv(2)),V=mul(C,s5);
		int d1=add(mul(V,V),4),d2=dec(mul(V,V),4),ans=P+1;
		if(!d1||power(d1,(P-1)>>1)==1){
			int tmp=Sqrt(d1),val;
			val=mul(add(V,tmp),Inv(2)),Min(ans,BSGS(U,val,0));
			val=mul(dec(V,tmp),Inv(2)),Min(ans,BSGS(U,val,0));
		}
		if(!d2||power(d2,(P-1)>>1)==1){
			int tmp=Sqrt(d2),val;
			val=mul(add(V,tmp),Inv(2)),Min(ans,BSGS(U,val,1));
			val=mul(dec(V,tmp),Inv(2)),Min(ans,BSGS(U,val,1));
		}
		printf("%d\n",ans==P+1?-1:ans);
    // cout << s5 << endl;
	}
	return 0;
}