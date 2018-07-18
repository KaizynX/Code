#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 2e5 + 7;

int M, D, t;
int s[2][Maxn], top, cnt;
// s[0][] store the number
// s[1][] store the value

template <typename T> inline void read(T &);
inline void add(int);
inline int query(int);

int main()
{
	char op; long long tmp;
	read(M); read(D);
	while(M--)
	{
		while((op=getchar()) != 'A' && op != 'Q');
		read(tmp);
		if(op == 'A') add(static_cast<int>((tmp+t) % D));
		else printf("%d\n", tmp == 0 ? 0 : query(cnt-static_cast<int>(tmp)+1));
	}
	return 0;
}

inline void add(int k)
{
	while(k > s[1][top] && top) --top; // s[1][top] >= k
	s[0][++top] = ++cnt; // push it
	s[1][top] = k;
}

inline int query(int k) // k refer to the start pos of query
{
	int l = 1, r = top;
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(s[0][mid] < k) l = mid + 1;
		else r = mid;
	}
	return t = s[1][r];
}

template <typename T> inline void read(T &res)
{
	char c; int tag = 1;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
	res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	res *= tag;
}
