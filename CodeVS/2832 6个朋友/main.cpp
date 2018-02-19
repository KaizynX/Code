#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=10000+5;

int n,m,f[N],sum[N],pd;

bool cmp(int a,int b)
{
	return a>b;
}

inline void init()
{
	for(int i=1;i<=n;++i)
		f[i]=i;
}

int ff(int s)
{
	if(f[s]!=s)
		f[s]=ff(f[s]);
	return f[s];
}

inline void connect(int x,int y)
{
	int fx=ff(x),fy=ff(y);
	if(fx!=fy)
		f[fx]=fy;
}

int main()
{
	int i,x,y;
	scanf("%d%d",&n,&m);
	init();
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		connect(x,y);
	}
	for(i=1;i<=n;++i)
        ff(i);
	for(i=1;i<=n;++i)
	{
		if(sum[f[i]]==0)
			pd++;
		sum[f[i]]++;
	}
	if(pd<=6)
	{
		printf("^_^\n");
		return 0;
	}
	else
	{
		int ans=0;
		sort(sum+1,sum+1+n,cmp);
		for(i=1;i<=6;++i)
			ans+=sum[i];
		printf("T_T\n%d\n",ans);
	}
	return 0;
}
/**
100 100
11 50
61 57
84 4
63 3
49 10
88 51
92 63
52 95
42 96
37 95
61 29
10 15
11 85
39 98
69 45
86 91
33 54
51 45
81 52
43 80
21 33
67 76
10 11
93 48
62 93
87 79
38 40
97 74
23 26
46 95
1 54
33 58
16 55
10 34
38 28
14 47
26 42
33 8
97 63
83 73
3 19
75 72
13 74
56 95
16 26
85 77
35 84
43 68
65 61
42 41
30 28
17 13
68 51
67 29
42 83
54 2
91 21
87 42
8 91
34 63
62 86
70 25
53 11
5 82
28 58
16 85
26 77
4 36
90 53
18 20
20 64
51 22
93 22
75 59
37 77
93 13
76 90
82 24
27 44
22 12
90 9
66 89
83 24
48 30
79 18
97 67
1 27
37 73
17 26
56 99
3 49
12 37
13 97
67 60
22 18
16 24
80 55
92 77
49 35
63 58

ans=92
**/
