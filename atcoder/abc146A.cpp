#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;
string s[10] = { "SUN", "MON", "TUE", "WED", "THU", "FRI",  "SAT" };

int main()
{
    string ss;
    cin >> ss;
    for (int i = 0; i < 7; ++i) {
        if (ss == s[i]) {
            cout << 7-i << endl;
            return 0;
        }
    }
    return 0;
}
