#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 5e5;

int T, n;

inline int f(int x)
{
    if (x <= 1) return 0;
    int res = 1;
    for (int i = 2; i*i <= x; ++i) {
        if (x%i) continue;
        res += x/i;
        if (x/i != i) res += i;
    }
    return res;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        int m = f(n), k = f(m);
#ifdef DEBUG
        cout << m << " " << k << endl;
#endif
        if (n == m || m > N || m < 1) cout << "注定单身" << endl;
        else if (n == k) cout << "缘分已定" << endl;
        else cout << "缘分未到" << endl;
        /*
        if (n == m || m > N || m < 1) cout << "注定单身";
        else if (n == k) cout << "缘分已定";
        else cout << "缘分未到";
        if (T) cout << endl;
        */
    }
    return 0;
}
