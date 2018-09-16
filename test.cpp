#include <bits/stdc++.h>

using namespace std;

int fa(vector<int> &A)
{
    int res = 0;
    for(int l = 0; l < A.size(); ++l)
    {
        for(int r = l; r < A.size(); ++r)
        {
            int minv = 30001;
            for(int k = l; k <= r; ++k)
            {
                minv = min(minv, A[k]);
            }
            res += minv;
        }
    }
    return res;
}

int fb(vector<int> &A)
{
    int res = 0, vis[A.size()];
    for(int i = 0; i < A.size(); ++i)
    {
        int l = i, r = i;
        while(--l >= 0 && A[l] >= A[i]);
        while(++r < A.size() && A[r] <= A[i]);
        ++l; --r;
        res += A[i]*(i-l+1)*(r-i+1);
    }
    return res;
}

int main()
{
    freopen("tmp.txt", "w", stdout);
    cout << "[";
    for(int i = 1; i < 30000; ++i)
        cout << "30000,";
    cout << "30000]";
	return 0;
}
