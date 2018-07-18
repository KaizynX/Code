#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int Maxn = 100;

int n, sum, need, cur;
int a[Maxn], s[Maxn];
bool used[Maxn];

bool dfs(int div, int cot, int last)
{
	if(!div)
	{
		printf("%d\n", need);
		exit(0);
	}
	if(cot == need) return dfs(div-1, 0, 0);
	if(cot + s[last+1] < need) return false;

	for(int i = last+1, faild = 0; i <= cur; ++i)
	{
		if(used[i]) continue;
		if(cot + a[i] > need) continue;
		if(a[i] == faild) continue; // same length
		used[i] = true;
		if( dfs(div, cot+a[i], i) ) return true;
		used[i] = false;
		faild = a[i];
		if(cot == 0 || cot + a[i] == need) return false;
	}
	return false;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a[++cur]);
		if(a[cur] > 50) --cur;
		else sum += a[cur];
	}
	for(int i = cur; i; --i)
		s[i] = s[i+1] + a[i];
	sort(a+1, a+cur+1); reverse(a+1, a+cur+1);
	for(need = a[1]; need <= sum/2; ++need)
	{
		if(sum % need) continue;
		memset(used, 0, sizeof used);
		dfs(sum/need, 0, 0);
	}
	printf("%d\n", sum);
	return 0;
}
