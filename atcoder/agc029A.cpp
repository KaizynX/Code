#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;

string S;
int a[Maxn], b[Maxn];
long long ans;

void merge_sort(int l, int r)
{
    if(l == r) return;
    int mid = (l+r)>>1;
    merge_sort(l, mid);
    merge_sort(mid+1, r);

    int i = l, j = mid+1, k = l;
    while(k <= r)
    {
        if(j <= r && (i > mid || a[j] < a[i]))
        {
            ans += mid-i+1;
            b[k++] = a[j++];
        }
        else b[k++] = a[i++];
    }
    memcpy(a+l, b+l, sizeof(int)*(r-l+1));
}

int main()
{
    cin >> S;
    for(int i = 0; i < S.length(); ++i)
        a[i+1] = S[i] == 'B' ? 1 : 0;
    merge_sort(1, S.length());
    cout << ans << endl;
    return 0;
}
