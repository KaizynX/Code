#include <iostream>

using namespace std;

long long x, n, ans = 1;

int main()
{
    cin >> x >> n;
    while(n--)
        ans += ans*x;
    cout << ans << endl;
    return 0;
}
