#include <iostream>

using namespace std;

const int Maxn = 52 * 52 + 7;

int n;
string p[Maxn];
int cnt[128];
int e[128][128];

void dfs(int cur)
{
	cout << (char) cur;
	// search from small to big, so it must be the smallest sort
	for(int i = 'A'; i <= 'z'; ++i)
	{
		if(i == 'Z' + 1) i = 'a';
		if(e[cur][i])
		{
			e[cur][i] --;
			e[i][cur] --;
			dfs(i);
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> p[i];
		cnt[ (int)p[i][0] ]++;
		cnt[ (int)p[i][1] ]++;
		e[ (int)p[i][0] ][ (int)p[i][1] ] ++;
		e[ (int)p[i][1] ][ (int)p[i][0] ] ++;
	}

	// if it is OuLaHuiLu
	int single_i = 0, single_n = 0;
	for(int i = 'A'; i <= 'z'; ++i)
	{
		if(i == 'Z' + 1) i = 'a';
		if(cnt[i] & 1) // cnt % 2 == 1
		{
			single_n++;
			if(!single_i) single_i = i;
		}
	}
	if(single_n != 0 && single_n != 2)
	{
		cout << "No Solution" << endl;
		return 0;
	}

	// start from the single_i
	// if it is OuLaHuiLu then there must be a way
	if(!single_i) // there is no single_i, search it
	{
		for(int i = 'A'; i <= 'z'; ++i)
		{
			if(i == 'Z' + 1) i = 'a';
			if(cnt[i])
			{
				single_i = i;
				break;
			}
		}
	}
	dfs(single_i);
	return 0;
}
