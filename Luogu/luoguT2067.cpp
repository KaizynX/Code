#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n;
long long ans;
map<string, int> mmp;
int a[Maxn], b[Maxn];

void merge_sort(int l, int r)
{
    if(l >= r) return;
    int mid = (l+r)>>1;
    merge_sort(l, mid);
    merge_sort(mid+1, r);

    int i = l, j = mid+1, p = l;
    while(p <= r)
    {
        if(i > mid || (j <= r && a[j] < a[i]))
        {
            ans += mid-i+1;
            b[p++] = a[j++];
        }
        else b[p++] = a[i++];
    }
    memcpy(a+l, b+l, sizeof(int)*(r-l+1));
}

int main()
{
    string name;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> name;
        mmp.insert(make_pair(name, i));
    }
    for(int i = 1; i <= n; ++i)
    {
        cin >> name;
        a[i] = mmp[name];
    }
    merge_sort(1, n);
    cout << ans << endl;
    return 0;
}
