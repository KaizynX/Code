#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<int> ans[2];

int main()
{
	int w_11 = 0, w_21 = 0, l_11 = 0, l_21 = 0;
	char c;
	while( cin >> c && c != 'E')
	{
		if(c == 'W') { ++w_11; ++w_21; }
		else if(c == 'L') { ++l_11; ++l_21; }
		else continue;

		//if(  (w_11 >= 11 && w_11 - l_11 >= 2) 
		//   ||(l_11 >= 11 && l_11 - w_ll >= 2))
		if( (w_11 >= 11 || l_11 >= 11) && abs(w_11 - l_11) >= 2 )
		{
			printf("%d:%d\n", w_11, l_11);
			w_11 = l_11 = 0;
		}
		if( (w_21 >= 21 || l_21 >= 21) && abs(w_21 - l_21) >= 2)
		{
			ans[0].push_back(w_21);
			ans[1].push_back(l_21);
			w_21 = l_21 = 0;
		}
	}
	printf("%d:%d\n\n", w_11, l_11);
	for(unsigned i = 0; i < ans[0].size(); ++i)
		printf("%d:%d\n", ans[0][i], ans[1][i]);
	printf("%d:%d\n", w_21, l_21);
	return 0;
}
