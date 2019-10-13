#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

string s;
int k;

inline int solve(string str)
{
    int res = 0, cnt = 1;
    for (int i = 1; i < (int)str.length(); ++i) {
        if (str[i] == str[i-1]) {
            ++cnt;
        } else {
            res += cnt/2;
            cnt = 1;
        }
    }
    return res+cnt/2;
}

int main()
{
    cin >> s >> k;
    int flag = 1;
    for (char c : s) if (c != s[0]) flag = 0;
    if (flag) {
        cout << (long long)s.length()*k/2 << endl;
        return 0;
    }
    int num = solve(s);
    if (s.front() != s.back()) {
        cout << 1ll*num*k << endl;
        return 0;
    }
    int a = 1, b = 1;
    for (int i = 1; i < (int)s.length(); ++i) {
        if (s[i] != s[0]) break;
        ++a;
    }
    for (int j = s.length()-2; j >= 0; --j) {
        if (s[j] != s[0]) break;
        ++b;
    }
    cout << 1ll*(num-a/2-b/2)*k+1ll*(a+b)/2*(k-1)+a/2+b/2 << endl;
    return 0;
}
