#include <iostream>

using namespace std;
string s[21];
int n,f[22][21],l[21],use[21],ans;
//f[21][i]为solve第一步初始化 
void panduan(int a,int b)
{
	int maxl=min(l[a],l[b]),flag;
	string sa=s[a],sb=s[b];
	for(int i=1;i<maxl;++i)//length
	{
		flag=1;
		for(int j=0;j<i;++j)
		{
			if(sa[l[a]-i+j]!=sb[j])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			f[a][b]=i;
			return;
		}
	}
	//f[a][b]=0;
	return;
}

void solve(int last,int sum)
{
	ans=max(ans,sum);
	for(int i=0;i<n;++i)
	{
		if(f[last][i]&&use[i]<2)
		{
			use[i]++;
			solve(i,sum+l[i]-f[last][i]);
			use[i]--;
		}
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>s[i];
		l[i]=s[i].length();
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			panduan(i,j);
	string test;
	char head;//s[21]
	cin>>head;
	for(int i=0;i<n;++i)
	{
		test=s[i];
		if(test[0]==head)
			f[21][i]=1;
		//else f[21][i]=0;
	}
	solve(21,1);
	cout<<ans<<endl;
	return 0;
}
