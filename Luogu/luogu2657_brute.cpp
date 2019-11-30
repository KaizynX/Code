#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

long long a, b;

inline bool check(long long x) {
    vector<int> v;
    do {
        v.push_back(static_cast<int>(x%10));
        x /= 10;
    } while (x);
    for (int i = 0; i < (int)v.size()-1; ++i) {
        if (abs(v[i]-v[i+1]) < 2) return false;
    }
    return true;
}

int main()
{
    cin >> a >> b;
    long long res = 0;
    for (long long i = a; i <= b; ++i) {
        res += check(i);
    }
    cout << res << endl;
    return 0;
}
