#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e2+7;

int q;
int cnt[3][30];
string str[3];

inline bool my_fit(const string &a, const string &b)
{
    int i = 0, j = 0;
    while(i < a.length() && j < b.length())
    {
        if(a[i] == b[j])
        {
            i++;
            j++;
        }
        else j++;
    }
    return i == a.length();
}

int main()
{
    cin >> q;
    while(q--)
    {
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < 3; ++i)
        {
            cin >> str[i];
            for(int j = 0; j < str[i].length(); ++j)
                cnt[i][str[i][j]-'a']++;
        }
        if(!my_fit(str[0], str[1]))
        {
            cout << "NO" << endl;
            continue;
        }
        int flag = 1;
        for(int i = 0; i < 26; ++i)
        {
            if(cnt[0][i]+cnt[2][i] < cnt[1][i])
            {
                flag = 0;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
