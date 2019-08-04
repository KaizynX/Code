#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e4+7;

int Q, n, m;
int col[Maxn];

int main()
{
    cin >> Q;
    while(Q--)
    {
        char c;
        int maxr = 0, maxc = 0;
        vector<int> rr;
        memset(col, 0, sizeof col);
        cin >> n >> m;
        for(int i = 1, cnt; i <= n; ++i)
        {
            cnt = 0;
            for(int j = 1; j <= m; ++j)
            {
                cin >> c;
                if(c == '*')
                {
                    cnt++;
                    col[j]++;
                }
            }
            // maxr = max(maxr, cnt);
            if(cnt > maxr)
            {
                rr.clear();
                maxr = cnt;
                rr.push_back(i);
            }
        }
        for(int j = 1; j <= m; ++j)
            maxc = max(maxc, col[j]);
        for(int j = 1; j <= m; ++j)
        {
            if(col[j] == maxc)
            {
                for(int i = 0; i < rr.size(); ++i)
                {
                    if()
                }
            }
        }
        cout << n+m-maxr-maxc << endl;
    }
    return 0;
}
