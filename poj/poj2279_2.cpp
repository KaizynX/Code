#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3e1+1;

int n;
int a[5];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n && n) {
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = n; i < 5; ++i) a[i] = 0;
        vector<vector<vector<vector<vector<unsigned> > > > > f(a[0]+1,
               vector<vector<vector<vector<unsigned> > > >    (a[1]+1,
                      vector<vector<vector<unsigned> > >      (a[2]+1,
                             vector<vector<unsigned> >        (a[3]+1,
                                    vector<unsigned>          (a[4]+1, 0)))));
        f[0][0][0][0][0] = 1;
        for (int i0 = 1; i0 <= a[0]; ++i0) 
        for (int i1 = 0; i1 <= i0 && i1 <= a[1]; ++i1)
        for (int i2 = 0; i2 <= i1 && i2 <= a[2]; ++i2)
        for (int i3 = 0; i3 <= i2 && i3 <= a[3]; ++i3)
        for (int i4 = 0; i4 <= i3 && i4 <= a[4]; ++i4) {
            if (i0) f[i0][i1][i2][i3][i4] += f[i0-1][i1][i2][i3][i4];
            if (i1) f[i0][i1][i2][i3][i4] += f[i0][i1-1][i2][i3][i4];
            if (i2) f[i0][i1][i2][i3][i4] += f[i0][i1][i2-1][i3][i4];
            if (i3) f[i0][i1][i2][i3][i4] += f[i0][i1][i2][i3-1][i4];
            if (i4) f[i0][i1][i2][i3][i4] += f[i0][i1][i2][i3][i4-1];
        }
        cout << f[a[0]][a[1]][a[2]][a[3]][a[4]] << endl;
    }
    return 0;
}

