#include <iostream>

using namespace std;

int a, b, c;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

int main()
{
    cin >> a >> b >> c;
    int mind = min(a, min(b, c)), maxd = max(a, max(b, c));
    int tmp = gcd(maxd, mind);
    cout << mind/tmp << "/" << maxd/tmp << endl;
}
