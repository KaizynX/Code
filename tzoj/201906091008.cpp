#include <bits/stdc++.h>

using namespace std;

int T;
long long b;

long long f(long long x)
{
    long long cnt = 0;
    for(long long i = 1; i*i <= x; ++i)
    {
        if(x%i == 0)
        {
            ++cnt;
            if(x/i != i) ++cnt;
        }
    }
    return cnt;
}

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> b;
        cout << f(b) << endl;
    }
    return 0;
}
