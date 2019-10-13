#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;

string s;

int main()
{
    cin >> s;
    cout << "Mike" << endl;
    for (int i = 1, last = s[0]; i < s.length(); ++i) {
        cout << (last < (int)s[i] ? "Ann" : "Mike") << endl;
        last = min(last, (int)s[i]);
    }
    return 0;
}
