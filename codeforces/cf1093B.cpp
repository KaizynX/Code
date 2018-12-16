#include <bits/stdc++.h>

using namespace std;

int t;
string s;
int cnt[30];

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> s;
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < s.length(); ++i)
            cnt[s[i]-'a']++;
        int num = 0;
        for(int i = 0; i < 26; ++i)
            if(cnt[i]) num++;
        if(num == 1) cout << "-1" << endl;
        else
        {
            int i = 0, j = 25;
            while(cnt[i] == 0) i++;
            while(cnt[j] == 0) j--;
            cnt[i]--;
            cnt[j]--;
            cout << char('a'+i);
            for(int k = 0; k < 26; ++k)
                while(cnt[k])
                {
                    cout << char('a'+k);
                    cnt[k]--;
                }
            cout << char('a'+j) << endl;
        }
    }
    return 0;
}
