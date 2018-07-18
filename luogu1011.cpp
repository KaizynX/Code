#include <iostream>

using namespace std;

const int Maxn = 22;

int a, n, m, x;
int up_a[Maxn], up_b[Maxn], stay_a[Maxn], stay_b[Maxn];

int main()
{
	cin >> a >> n >> m >> x;
	up_a[1] = 1; stay_a[1] = 1;
	up_b[2] = 1; stay_a[2] = 1;
	for(int i = 3; i < n; ++i)
	{
		up_a[i] = up_a[i-2] + up_a[i-1];
		up_b[i] = up_b[i-2] + up_b[i-1];
		// stay_a[i] = stay_a[i-1] + up_a[i] - up_a[i-1];
		stay_a[i] = stay_a[i-1] + up_a[i-2];
		stay_b[i] = stay_b[i-1] + up_b[i-2];
	}
	// stay_a[n-1] * a + stay_b[n-1] * b = m;
	int b = (m - stay_a[n-1]*a) / stay_b[n-1];
	cout << (stay_a[x]*a + stay_b[x]*b) << endl;
	return 0;
}
