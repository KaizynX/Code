#include <iostream>
using namespace std;
int n;
//不包括10进制及以上 
string fan(string num)
{
	string res;
	int len=num.length();
	for(int i=len-1;i>=0;i--)
		res+=num[i];
	return res;
}

bool judge(string num)
{
	string num1=fan(num);
	if(num1==num)return 1;
	else return 0;
}

string jia(string num)
{
	int len=num.length(),now,ans[100]={0},flag=0;
	string res,num1=fan(num);
	for(int i=len-1;i>=0;i--)
	{
		now=(num[i]-'0')+(num1[i]-'0');
		while(now>=n)
		{
			now-=n;
			ans[flag+1]++;
		}
		ans[flag]+=now;
		while(ans[flag]>=n)
		{
			ans[flag]-=n;
			ans[flag+1]++;
		}
		flag++;
	}
	for(int i=flag;i>=0;i--)
	{
		if(i==flag&&ans[flag]==0)continue;
		res+=ans[i]+'0';
	}
	return res;
}

int main()
{
	int step=1;
	string m,cur;
	cin>>n>>m;
	cur=jia(m);
	while(!judge(cur))
	{
		cur=jia(cur);
		step++;
		if(step>30)break;
	}
	if(step<=30)cout<<"STEP="<<step<<endl;
	else cout<<"Impossible!"<<endl;
}

