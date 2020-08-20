#include <bits/stdc++.h>

using namespace std;

int t;
string str;

int main()
{
    cin >> t;
    while (t--) {
        int cnt = 0, flag = 1;
        cin >> str;
        for (int i = 0; i < (int)str.length(); ++i) {
            if (str[i] == '(') {
                ++cnt;
            } else if (str[i] == ')') {
                --cnt;
                if (cnt < 0) {
                    flag = 0;
                    break;
                }
            }
        }
        if (cnt != 0) flag = 0;
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
