#include <bits/stdc++.h>

using namespace std;

vector<int> v[3];

int main()
{
    string str;
    int res = 2;
    for(int i = 0; i < 3; ++i)
    {
        cin >> str;
        if(str[1] == 'm') v[0].push_back(str[0]-'0');
        else if(str[1] == 's') v[1].push_back(str[0]-'0');
        else if(str[1] == 'p') v[2].push_back(str[0]-'0');
    }
    for(int i = 0; i < 3; ++i)
    {
        if(v[i].size() <= 1) continue;
        sort(v[i].begin(), v[i].end());
        for(int j = 0; j < v[i].size()-1; ++j)
            for(int k = j+1; k < v[i].size(); ++k)
                if(abs(v[i][j]-v[i][k]) <= 2)
                    res = min(res, 1);
        if(v[i].size() == 3)
        {
            if(v[i][0] == v[i][1] && v[i][1] == v[i][2]) res = 0;
            if(v[i][0] == v[i][1]-1 && v[i][1] == v[i][2]-1) res = 0;
        }
    }
    cout << res << endl;
    return 0;
}
