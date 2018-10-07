#include <iostream>
#include <cstdio>
#include <cstring>

// #define DEBUG

using namespace std;

const int Maxn = 30;

int n, top;
long long ans;

struct Node
{
	int x, y;

	Node(){}
	Node(int _x,int _y) : x(_x),y(_y) {}

	Node operator * (const Node & b) const
	{
		ans += x * y * b.y;
		return Node(x,b.y);
	}

} a[Maxn], s[1000], tmp_a, tmp_b;

int main()
{
	char c;
	string str;
	bool flag;

	cin >> n;
	for(int i = 0, x, y; i < n; ++i)
	{
		cin >> c >> x >> y;
		a[c-'A'].x = x; a[c-'A'].y = y;
	}
	while(cin >> str)
	{
		ans = 0;
		top = 0;
		flag = true;

		for(unsigned i = 0; i < str.length(); ++i)
		{
			if(str[i] == '(') continue;
			else if(str[i] == ')')
			{
				tmp_b = s[top--];
				tmp_a = s[top--];
#ifdef DEBUG
				printf("%d %d %d %d\n",tmp_a.x,tmp_a.y,tmp_b.x,tmp_b.y);
#endif
				if(tmp_a.y != tmp_b.x)
				{
					puts("error");
					flag = false;
					break;
				}
				s[++top] = tmp_a * tmp_b;
			}
			else
			{
				s[++top] = a[str[i]-'A'];
			}
		}
		if(flag) printf("%lld\n",ans);
	}
	return 0;
}
