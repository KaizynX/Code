#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 18+5;

int n,ans;
int a[Maxn][Maxn];

int dfs(int next_num,int in_stack)
{
	if(next_num>n)
	{
		a[next_num][in_stack]=1;
		return 1;
	}

	if(a[next_num][in_stack])
		return a[next_num][in_stack];

	a[next_num][in_stack]+=dfs(next_num+1,in_stack+1);
	a[next_num][in_stack]+=(in_stack>0 ? dfs(next_num,in_stack-1):0);
	return a[next_num][in_stack];
}

int main()
{
	cin>>n;
	cout<<dfs(1,0)<<endl;
	return 0;
}
