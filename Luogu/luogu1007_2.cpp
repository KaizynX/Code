#include <iostream>

using namespace std;

int N, L, minv, maxv;

int main()
{
	cin >> L >> N;
	for(int i = 0, tmp; i < N; ++i)
	{
		cin >> tmp;
		// this one can turn left or right ==> (tmp, L+1-tmp)
		// max ==> must wait for last one goes 
		minv = max(minv, min(tmp, L+1-tmp));
		maxv = max(maxv, max(tmp, L+1-tmp));
	}
	cout << minv << " " << maxv << endl;
	return 0;
}
