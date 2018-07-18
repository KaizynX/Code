#include <iostream>

using namespace std;
const int maxc=50;

string itos(int a)//AC
{
	string res,out;
	while(a>0)
	{
		res+=(a%10)+'0';
		a/=10;
	}
	int l=res.length();
	for(int i=l-1;i>=0;i--)
		out+=res[i];
	return out;
}

string maxs(string a,string b)
{
	int la=a.length(),lb=b.length();
	if(la>lb)return a;
	else if(la<lb)return b;
	else
	{
		for(int i=0;i<la;++i)
		{
			if(a[i]>b[i])return a;
			else if(a[i]<b[i])return b;
		}
		return a;
	}
}

string itofs(int num[],int len)//AC
{
	string res;
	bool flag=0;
	for(int i=len-1;i>=0;--i)
	{
		if(num[i]!=0)
		{
			flag=1;
			res+=num[i]+'0';
		}
		else 
			if(flag)res+='0';
	}
	return res;
}

string hx(string a)//AC
{
	int l=a.length(),flag=0;
	int res[maxc]={0};
	for(int i=l-1;i>=0;--i)
	{
		res[flag]+=(a[i]-'0')*2;
		if(res[flag]>=10)
		{
			res[flag]%=10;
			res[flag+1]++;
		}
		flag++;
	}
	return itofs(res,flag);
}

string hplus(string a,string b)//AC
{
	int la=a.length(),lb=b.length();
	int maxl,minl,flag;
	if(la>lb)
	{
		flag=1;
		maxl=la;
		minl=lb;
	}
	else
	{
		flag=0;
		maxl=lb;
		minl=la;
	}
	int res[maxc]={0};
	for(int i=1;i<=minl;++i)
	{
		res[i-1]+=(a[la-i]-'0')+(b[lb-i]-'0');
		if(res[i-1]>=10)
		{
			res[i-1]%=10;
			res[i]++;
		}
	}
	for(int i=minl+1;i<=maxl;++i)
		if(flag)
		{
			res[i-1]+=(a[la-i]-'0');
			if(res[i-1]>=10)
			{
				res[i-1]%=10;
				res[i]++;
			}
		}
		else 
		{
			res[i-1]+=(b[lb-i]-'0');
			if(res[i-1]>=10)
			{
				res[i-1]%=10;
				res[i]++;
			}
		}
	return itofs(res,maxl+1);
}

int main()
{
	string ans="0",f[81][81],l,r;
	int n,m,a[81];
	cin>>n>>m;
	for(int in=0;in<n;++in)
	{
		for(int im=1;im<=m;++im)
		{
			cin>>a[im];
			f[im][im]=itos(a[im]*2);
		}			
		for(int len=2;len<=m;len++)
			for(int i=1;i<=m-len+1;++i)
			{
				int j=i+len-1;
				//f[i][j]=max(a[i]+f[i+1][j],a[j]+f[i][j-1])*2;
				l=hplus(itos(a[i]*2),hx(f[i+1][j]));
				r=hplus(itos(a[j]*2),hx(f[i][j-1]));
				f[i][j]=maxs(l,r);
			}
		//ans+=f[1][m];
		ans=hplus(ans,f[1][m]);
	}
	cout<<ans<<endl;
	return 0;
}
/* No highstanderd version
#include <iostream>

using namespace std;

int main()
{
	long long ans=0,f[81][81];
	int n,m,a[81];
	cin>>n>>m;
	for(int in=0;in<n;++in)
	{
		for(int im=1;im<=m;++im)
		{
			cin>>a[im];
			f[im][im]=a[im]*2;
		}			
		for(int len=2;len<=m;len++)
			for(int i=1;i<=m-len+1;++i)
			{
				int j=i+len-1;
				f[i][j]=max(a[i]+f[i+1][j],a[j]+f[i][j-1])*2;
			}
		ans+=f[1][m];
	}
	for(int in=0;in<n;++in)
	{
		for(int im=1;im<=m;++im)
			cout<<f[in][im]<<" ";
		cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
*/
