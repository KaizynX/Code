#include <cstdio>
#include <iostream>

using namespace std;

long long A, B, ans;

int main()
{
	cin >> A >> B;
	for(long long j = 1, tag, a, b; j <= B; ++j)
	{
		if(j > A) A = j;
		tag = j&1 ? -1 : 1;
		a = A/j, b = B/j;
		if(a == b) ans += tag*(B-A+1)*a;
		else
		{
			ans += tag*( ((a+1)*j-A)*a + (B-b*j+1)*b );
			if(a+1 < b) ans += tag*j*(a+b)*(b-a-1)/2;
		}
	}
	cout << ans << endl;
	return 0;
}
