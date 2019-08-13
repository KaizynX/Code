#include <bits/stdc++.h>

using namespace std;

int T, n, k;
vector<vector<int> > v[10];
vector<vector<int> > sss;

inline bool cmp(vector<int> &a, vector<int> &b)
{
    for(int i = 1; i < a.size(); ++i)
    {
        if(a[i]-a[i-1] != b[i]-b[i-1])
            return a[i]-a[i-1] < b[i]-b[i-1];
    }
    return false;
}

int main()
{
    scanf("%d", &T);
    vector<int> tmp;
    for(int i = 1; i <= 9; ++i)
    {
        tmp.clear();
        for(int j = 1; j <= i; ++j) tmp.push_back(j);
        if(i <= 8)
        {
            do v[i].push_back(tmp);
            while(next_permutation(tmp.begin(), tmp.end()));
        }
        else if(i == 9)
        {
            do v[i].push_back(tmp);
            while(next_permutation(tmp.begin()+1, tmp.end()));
        }
        sort(v[i].begin(), v[i].end(), cmp);
    }
    while(T--)
    {
        scanf("%d%d", &n, &k);
        if(n <= 8)
        {
            for(int i = 0; i < v[n][k-1].size()-1; ++i)
                printf("%d ", v[n][k-1][i]);
            printf("%d\n", v[n][k-1].back());
            continue;
        }
        printf("%d ", n);
        for(int i = 1; i <= n-9; ++i) printf("%d ", i);
        for(int i = 1; i < 8; ++i) printf("%d ", v[9][k-1][i]+n-10);
        printf("%d\n", v[9][k-1].back()+n-10);
        /*
        vector<int> tmp;
        tmp.push_back(n-9);
        for(int i = n-8; i < n; ++i) tmp.push_back(i);
        do sss.push_back(tmp);
        while(next_permutation(tmp.begin()+1, tmp.end()));
        sort(sss.begin(), sss.end(), cmp);
        for(int i = 1; i < sss[k-1].size()-1; ++i) printf("%d ", sss[k-1][i]);
        printf("%d\n", sss[k-1].back());
        */
    }
    return 0;
}
