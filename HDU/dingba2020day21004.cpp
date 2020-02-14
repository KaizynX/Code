#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

string str;

inline void f(int p)
{
    for (int i = p-1; i <= p+1; ++i)
        str[i] = ((str[i]-'0')^1)+'0';
}

int main()
{
    while (cin >> str) {
        int k = 0;
        for (int i = 0; i < (int)str.length()-1; ++i) {
            if (str[i] == '1') {
                f(i+1);
                ++k;
            }
        }
        if (str.back() == '1') cout << "NO" << endl;
        else cout << k << endl;
    }
    return 0;
}
