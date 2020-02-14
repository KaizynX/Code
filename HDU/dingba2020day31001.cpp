#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int T, n;
string s;

inline bool check(int p)
{
    int flag = 1;
    if (p-1 >= 0 && isalpha(s[p-1])) flag = 0;
    if (p+4 < n && isalpha(s[p+4])) flag = 0;
    return flag && s[p] == 'b' && s[p+1] == 'e' && s[p+2] == 'l' && s[p+3] == 't';
}

int main()
{
    cin >> T;
    getchar();
    while (T--) {
        getline(cin, s);
        n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a'-'A';
        }
        int flag = 0;
        for (int i = 0; i+3 < n; ++i) {
            if (check(i)) {
                flag = 1;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}
