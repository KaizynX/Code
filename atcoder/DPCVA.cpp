#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e2+7;

int n, a[Maxn], sum;
double res, dd;

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    double ave = (double)sum/n;
    dd = abs(ave-a[0]);
    for(int i = 1; i < n; ++i)
    {
        if(abs(ave-a[i]) < dd)
        {
            dd = abs(ave-a[i]);
            res = i;
        }
    }
    cout << res << endl;
    return 0;
}
