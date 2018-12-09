#include <bits/stdc++.h>

using namespace std;

int n;
int p, maxp, sum;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> p;
        maxp = max(maxp, p);
        sum += p;
    }
    cout << sum-maxp/2 << endl;
    return 0;
}
