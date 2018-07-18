#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int Maxn = 2500 + 7;

struct Cow
{
	int minSPF, maxSPF;
	bool operator < (const Cow &nex) const
	{
		return minSPF > nex.minSPF;
	}
} a[Maxn];

struct SPF
{
	int v, num;
	bool operator < (const SPF &nex) const
	{
		return v < nex.v;
	}
}tmp;

int C, L, ans;
vector <SPF> b;

int main()
{
	b.resize(Maxn);
	scanf("%d%d",&C,&L);
	for(int i = 0; i < C; ++i) scanf("%d%d",&a[i].minSPF, &a[i].maxSPF);
	for(int i = 0; i < L; ++i) scanf("%d%d",&b[i].v, &b[i].num);
	sort(a,a+C); sort(b.begin(),b.begin()+L);
	for(int i = 0, l, r, mid; L && i < C ; ++i)
	{
		l = 0; r = L;
		while(l < r - 1) // [l, r)
		{
			mid = (l + r) >> 1;
			// if(a[i].maxSPF == b[mid].v) { l = r = mid; break; }
			if(a[i].maxSPF < b[mid].v) r = mid;
			else l = mid ;
		}
		if(a[i].maxSPF >= b[l].v && a[i].minSPF <= b[l].v)
		{
			++ans;
			if(--b[l].num == 0)
			{
				b.erase(b.begin()+l);
				--L;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
