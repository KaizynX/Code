#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1e4;

int ans = INF;
int arr[INF], res[INF];

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

struct Node
{
	int a, b;

	Node(){}
	Node(int a, int b = 1) : a(a), b(b) {}

	bool operator < (const Node &nex) const
	{
		return a*nex.b < nex.a*b;
	}
	
	bool operator == (const Node &nex) const
	{
		return a == nex.a && b == nex.b;
	}

	bool operator <= (const Node &nex) const
	{
		return *this < nex || *this == nex;
	}

	Node operator - (const Node &nex) const
	{
		Node res(a*nex.b - nex.a*b, b*nex.b);
		bool flag = res.a < 0 || res.b < 0 ? true : false;
		if(res.a < 0) res.a *= -1;
		if(res.b < 0) res.b *= -1;
		int tmp = gcd(res.a, res.b);
		res.a /= tmp; res.b /= tmp;
		if(flag) res.a *= -1;
		return res;
	}

	Node operator * (int num) const
	{
		Node res(a*num, b);
		int tmp = gcd((res.a < 0 ? -a : a), res.b);
		res.a /= tmp; res.b /= tmp;
		return res;
	}
} n;

void dfs(int dep, int last, Node rest)
{
	if(dep > ans) return;

	for(int i = last+1; rest <= Node(1, i)*(ans-dep+1); ++i)
	{
		Node tmp = rest - Node(1, i);
		if(tmp < 0) continue;
		arr[dep] = i;
		if(tmp.a == 0) 
		{
			if(dep < ans || (dep == ans && arr[dep] < res[ans]))
			{
				ans = dep;
				memcpy(res, arr, sizeof(int)*(ans+1));
			}
			return;
		}
		dfs(dep+1, max((tmp.b%tmp.a ? tmp.b/tmp.a : tmp.b/tmp.a-1), i), tmp);
	}
}

int main()
{
	scanf("%d%d", &n.a, &n.b);
	dfs(1, (n.b%n.a == 0 ? n.b/n.a-1 : n.b/n.a), n);
	printf("%d", res[1]);
	for(int i = 2; i <= ans; ++i)
		printf(" %d", res[i]);
	return 0;
}
