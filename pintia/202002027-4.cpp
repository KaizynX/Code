#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

bool is_prime(long long x)
{
    if (x < 2) return false;
    for (long long i = 2; i*i <= x; ++i)
        if (x%i == 0) return false;
    return true;
}

int main()
{
    long long n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        cout << (is_prime(x) ? "Yes" : "No") << endl;
    }
    return 0;
}

