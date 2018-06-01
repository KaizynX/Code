#include <iostream>
using namespace std;
int n;

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

int ctoi(char num)
{
    if(num>='0'&&num<='9')return num-'0';
    if(num=='A')return 10;
    if(num=='B')return 11;
    if(num=='C')return 12;
    if(num=='D')return 13;
    if(num=='E')return 14;
    if(num=='F')return 15;
}

char itoc(int num)
{
    if(num>=0&&num<=9)return num+'0';
    if(num==10)return 'A';
    if(num==11)return 'B';
    if(num==12)return 'C';
    if(num==13)return 'D';
    if(num==14)return 'E';
    if(num==15)return 'F';
}

string jia(string num)
{
	int len=num.length(),now,ans[100]={0},flag=0;
	string res,num1=fan(num);
	for(int i=len-1;i>=0;i--)
	{
		now=ctoi(num[i])+ctoi(num1[i]);
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
		res+=itoc(ans[i]);
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
