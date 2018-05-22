#include <cstdio>
#include <iostream>

using namespace std;

bool solve(int &w)
{
	int lw, rw, ld, rd;
	bool l = true, r = true;
	scanf("%d%d%d%d",&lw,&ld,&rw,&rd);
	if(!lw) l = solve(lw);
	if(!rw) r = solve(rw);
	w = lw + rw;
	return l && r && (lw * ld == rw * rd);
}

int main()
{
	int n,w;
	scanf("%d",&n);
	while(n--)
	{
		if(solve(w)) puts("YES");
		else puts("NO");
		if(n) putchar('\n');
	}
	return 0;
}
