#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int ans;
string str;

inline int calc(int x)
{
    int res = 0;
    while (x) {
        res += x&1;
        x >>= 1;
    }
    return res;
}

inline void rev(int p, string &ss)
{
    for (int i = p-1; i <= p+1; ++i) {
        if (i >= 0 && i < (int)ss.length())
            ss[i] = ((ss[i]-'0')^1)+'0';
    }
}

inline void f(int x)
{
    string ss = str;
    for (int i = 0; i < (int)str.length(); ++i)
        if ((x>>i)&1) rev(i, ss);
    for (int i = 0; i < (int)str.length(); ++i)
        if (ss[i] == '1') return;
    ans = min(ans, calc(x));
}

int main()
{
    while (cin >> str) {
        ans = str.length()+1;
        for (int i = 0; i < 1<<(int)str.length(); ++i)
            f(i);
        if (ans > (int)str.length()) cout << "NO" << endl;
        else cout << ans << endl;
    }
    return 0;
}
