#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e4+7;

int Q, n, m;
vector<string> v;

int main()
{
    cin >> Q;
    while(Q--)
    {
        int maxr = 0, maxc = 0, res = 0;
        vector<int> rr, cc;
        v.clear();

        cin >> n >> m;
        for(int i = 0, cnt; i < n; ++i)
        {
            string str;
            cin >> str;
            v.push_back(str);

            cnt = 0;
            for(int j = 0; j < m; ++j)
                if(str[j] == '*') cnt++;
            if(cnt > maxr)
            {
                maxr = cnt;
                rr.clear();
                rr.push_back(i);
            }
            else if(cnt == maxr) rr.push_back(i);
        }
        for(int j = 0, cnt; j < m; ++j)
        {
            cnt = 0;
            for(int i = 0; i < n; ++i)
                if(v[i][j] == '*') cnt++;
            if(cnt > maxc)
            {
                maxc = cnt;
                cc.clear();
                cc.push_back(j);
            }
            else if(cnt == maxc) cc.push_back(j);
        }
        res = n+m-maxr-maxc;
        if(maxr == 0 && maxc == 0)
        {
            cout << res-1 << endl;
            continue;
        }
        for(int i = 0, flag = 0; i < rr.size(); ++i)
        {
            for(int j = 0; j < cc.size(); ++j)
            {
                if(v[rr[i]][cc[j]] == '.')
                {
                    res--;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        cout << res << endl;
    }
    return 0;
}
