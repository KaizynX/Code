#include <bits/stdc++.h>

using namespace std;

const int kN = 1e1+7;

string str, last, now;
int res;

int main()
{
    cin >> str;
    res = 1;
    last = str[0];
    for (int i = 1; i < str.length(); ++i) {
        now += str[i];
        if (now == last) continue;
        else {
            last = now;
            now = "";
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}
