#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e3 + 7;

int n;
int s[Maxn], top, num;
bool flag;

inline int getint();
inline bool judge(int cur)
{
	// s[0] = 0
	// i < j ==> s[i] < s[j]
	if(!top && cur < num) return false;
	while(cur > s[top] && num < n)
	{
		s[++top] = num++;
	}
	if(num == cur) { num++; return true; }
	if(s[top] == cur) { --top; return true; }
	return false;
}

int main()
{
	int cur;
	while( (n = getint()) )
	{
		while( (cur = getint()))
		{
			flag = true;
			num = 1;

			// even it had been impossible , we should read all data
			// if had been judge == false, we don't need judge more
			if(flag) flag = judge(cur);
			for(int i = 1; i < n; ++i)
			{
				cur = getint();
				if(flag) flag = judge(cur);
			}
			puts(flag == true ? "Yes" : "No");
		}
	}
	return 0;
}

inline int getint()
{
	char c;
	while((c=getchar()) < '0' || c > '9') ;
	int res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	return res;
}
