#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;
const int Mo = 998244353;

int n;
unsigned long long res = 0;

int main()
{
    cin >> n;
    for(int i = 0, a; i < n; ++i)
    {
        vector<int> v;
        unsigned long long val = 0;
        cin >> a;
        while(a)
        {
            v.push_back(a%10);
            a /= 10;
        }
        reverse(v.begin(), v.end());
        for(int j = 0; j < v.size(); ++j)
            val = (val*10+v[j])*10;
        res += (val%Mo)*n%Mo + (val/10%Mo)*n%Mo;
        res %= Mo;
    }
    cout << res << endl;
    return 0;
}
