#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int Maxn = 100003;

string str;
unsigned str_cur;
bool tr[Maxn];

inline bool judge(int cur)
{
	return !(tr[cur*2] ^ tr[cur*2+1]);
}

int main()
{
	memset(tr,0,sizeof tr);
	cin >> str;
	for(unsigned i = 0; i < str.length(); ++ i)
	{
		if(str[i] == '#') tr[i+1] = false;
		else tr[i+1] = true;
	}
	for(unsigned i = 1; i <= str.length(); ++ i)
	{
		if(!judge(i))
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}
