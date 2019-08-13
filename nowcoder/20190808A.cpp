#include <bits/stdc++.h>

using namespace std;

const int Maxn = 207;

int T;
string str;
vector<string> res;

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> str;
        int pre0 = 0, st = 0, ed;
        res.clear();
        // pre 1's
        while(st < str.length() && str[st] == '1') st++;
        if(st) res.push_back(str.substr(0, st));
        while(st < str.length())
        {
            pre0 = 0;
            for(int i = st; i < str.length(); ++i)
            {
                if(str[i] == '1') break;
                else ++pre0;
            }
            for(ed = str.length(); ed > st; --ed)
            {
                if(str[ed] == '1' && str[ed-1] == '1') continue;
                if(ed <= st+pre0)
                {
                    res.push_back(str.substr(st, ed));
                    st = ed;
                    break;
                }
                if(str[ed-1] == '0') continue;
                int max0 = 0, cnt = 0;
                for(int i = st, now0 = 0; i < ed; ++i)
                {
                    if(str[i] == '0') now0++;
                    if(str[i] == '1' || i == str.length()-1)
                    {
                        if(now0 == max0) cnt++;
                        else if(now0 > max0)
                        {
                            cnt = 1;
                            max0 = now0;
                        }
                        now0 = 0;
                    }
                }
                if(max0 > pre0) continue;
                if(max0 == pre0 && cnt == 1)
                {
                    res.push_back(str.substr(st, ed-st));
                    st = ed;
                    break;
                }
                string mins = str.substr(st, ed-st);
                int flag = 0;
                for(int i = st+max0+1, now0 = 0; i < ed; ++i)
                {
                    if(str[i] == '0')
                    {
                        if(++now0 == max0)
                        {
                            string tmp = str.substr(i-now0+1, ed-i+now0-1)
                                         +(i-now0+1 > 0 ? str.substr(st, i-now0+1) : "");
                            // if(mins.length() == 0 || tmp < mins) mins = tmp;
                            if(tmp < mins)
                            {
                                flag = 1;
                                break;
                            }
                        }
                    }
                    else now0 = 0;
                }
                if(flag) continue;
                else
                {
                    res.push_back(str.substr(st, ed-st));
                    st = ed;
                    break;
                }
            }
        }
        for(int i = 0; i < res.size()-1; ++i)
            cout << res[i] << " ";
        cout << res.back() << endl;
    }
    return 0;
}
