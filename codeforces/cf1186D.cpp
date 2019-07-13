#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n;
double a[Maxn];
int b[Maxn];

int main()
{
    cin >> n;
    long long sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = int(floor(a[i]));
        sum += b[i];
    }
    for(int i = 1, cnt = 0; cnt < -sum; ++i)
    {
        if(abs(b[i]+1-a[i]) < 1)
        {
            b[i]++;
            cnt++;
        }
    }
    for(int i = 1; i <= n; ++i) cout << b[i] << endl;
    return 0;
}
