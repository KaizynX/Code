#include <bits/stdc++.h>

using namespace std;

string s, t;
const string vowels = "aeiou";

int main()
{
    cin >> s >> t;
    if(s.length() != t.length())
    {
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < s.length(); ++i)
    {
        bool flag1 = vowels.find(s[i]) == vowels.npos;
        bool flag2 = vowels.find(t[i]) == vowels.npos;
        if(flag1 != flag2)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    //system("pause");
    return 0;
}