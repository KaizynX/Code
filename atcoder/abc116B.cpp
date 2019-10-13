#include <bits/stdc++.h>

using namespace std;

const int N = 1e2;

map<int, int> mp;

inline int solve(int s)
{
    mp.clear();
    int i = 1;
    while (true) {
        if (mp.count(s)) return i;
        mp.insert({s, 1});
        s = s&1 ? s*3+1 : s/2;
        ++i;
    }
}

int main()
{
    int s;
    cin >> s;
    cout << solve(s) << endl;
    /*
    for (int i = 1; i <= N; ++i) {
        cout << i << " " << solve(i) << endl;
    }
    */
    return 0;
}
