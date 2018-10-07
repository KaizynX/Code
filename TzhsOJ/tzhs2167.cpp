#include <iostream>
#include <cstdio>

using namespace std;

int n;
unsigned long long ans, cur = 1;

int main()
{
    cin >> n;
    for(int i = n; i >= 1; --i)
    {
        cur *= i;
        ans += cur;
    }
    cout << ans-1 << endl;
    return 0;
}
