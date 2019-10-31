#include <bits/stdc++.h>
#define DEBUG

using namespace std;

long long n, p;
int a, b;

int exgcd(int a, int b, int &x, int &y)
{
    if(!b) { x = 1; y = 0; return a; }
    int res = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return res;
}

int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}

int main()
{
    cin >> n >> p >> a >> b;
    int g = gcd(a, b);
    for (int y = 0; y < a/g; ++y) {
        if ((p-1ll*y*b)%a == 0) {
            long long x = (p-1ll*y*b)/a;
            if (x < 0 || x+y > n) continue;
            cout << x << " " << y << " "<< n-x-y << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
