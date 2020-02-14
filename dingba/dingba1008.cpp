#include <bits/stdc++.h>

using namespace std;

string str;

int main()
{
    while (cin >> str) {
        for (int i = (int)str.length()-1; i; --i)
            str[i] = ((str[i]-'0')^(str[i-1]-'0'))+'0';
        cout << str << endl;
    }
    return 0;
}
