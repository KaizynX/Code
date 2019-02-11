#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int b, k;
int a;

int main()
{
    cin >> b >> k;
    b &= 1;
    int sum = 0;
    for(int i = 1; i <= k; ++i)
    {
        cin >> a;
        if(i == k) sum += a;
        else sum += (a&1)*b;
    }
    cout << (sum&1 ? "odd" : "even") << endl;
    return 0;
}