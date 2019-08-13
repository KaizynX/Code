#include <bits/stdc++.h>

using namespace std;

int T;
string str;

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> str;
        // pre0 开头0的个数
        int pre0 = -1, now0 = 0, st = 0;
        for(int i = 0; i < str.length(); ++i)
        {
            if(str[i] == '1')
            {
                if(pre0 == -1) pre0 = now0; 
                now0 = 0;
                continue;
            }
            ++now0;
            // 还在开头
            if(pre0 == -1) continue;
            // 开头是 1111
            if(now0 > pre0)
            // || (now0 == pre0 && (i+1 < str.length() && str[i+1] == '0')))
            {
                cout << str.substr(st, i-st) << " ";
                pre0 = -1;
                st = i;
            }
            else if(now0 == pre0)
            {
                // cut
                if(i+1 < str.length() && str[i+1] == '0')
                {
                    cout << str.substr(st, i-now0+1-st) << " ";
                    st = i-now0+1;
                    i = i+now0;
                    pre0 = -1;
                }
                else
                {
                    int k = st+now0, j = i+1, flag = 1;
                    while(j < str.length() && k < i-now0+1)
                    {
                        if(str[k] == str[j])
                        {
                            ++k, ++j;
                            continue;
                        }
                        if(str[k] > str[j]) flag = 0;
                        break;
                    }
                    if(!flag)
                    {
                        // str[k] == 1 > str[j] == 0
                        while(str[j] == '0') j--;
                        cout << str.substr(st, j-st+1) << " ";
                        st = j+1;
                        pre0 = -1;
                        i = j;
                    }
                    else if(k == i-now0+1)
                    {
                        now0 = 0;
                        i = j-1;
                    }
                }
            }
        }
        if(st < str.length())
        {
            int pp = str.length();
            while(pp-1 >= st && str[pp-1] == '0') pp--;
            if(pp <= st || pp == str.length()) cout << str.substr(st);
            else cout << str.substr(st, pp-st) << " " << str.substr(pp);
        }
        cout << endl;
    }
    return 0;
}
