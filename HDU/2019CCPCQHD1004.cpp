#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int T, n;

inline bool check(int x)
{
    map<pair<int, int>, int> mp;
    int y = 1;
    pair<int, int> cur;
    while (y) {
        y *= 10;
        cur = { y/x, y%x };
        if (mp.count(cur)) return true;
        mp.insert({ cur, 1 });
        y %= x;
    }
    return false;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        cout << (check(n) ? "Yes" : "No") << endl;
    }
    return 0;
}
