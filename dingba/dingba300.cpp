#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

string s;

int main()
{
    int cnt = 0;
    cin >> s;
    for (int i = 1; i < (int)s.length()-1; ++i) {
        if (s[i] == '0' && s[i-1] == '1' && s[i+1] == '1') {
            ++cnt;
            s[i+1] = '2';
        }
    }
    cout << cnt << endl;
    return 0;
}
