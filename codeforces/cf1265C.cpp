#include <bits/stdc++.h>

using namespace std;

const int N = 4e5+7;

int T, n;
int a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        vector<int> v, sum;
        int g = 0, s = 0, b = 0;
        cin >> n;
        a[0] = -1;
        for (int i = 1, cnt = 0; i <= n; ++i) {
            cin >> a[i];
            if (a[i] == a[i-1]) ++cnt;
            if (a[i] != a[i-1] || i == n) {
                v.emplace_back(cnt);
                cnt = 1;
            }
        }
        /*
        sum.resize(v.size(), 0);
        for (int i = 1; i < (int)v.size(); ++i) {
            sum[i] = sum[i-1]+v[i];
            if (sum[i] <= n/2) p = i;
        }
        for (int i = 1, l, r; i < n; ++i) {
            l = i+1; r = p-1;
            g = sum[i];
            // [1, i] gold [i+1, l] silver
            while (l < r) {
                int mid = (l+r)>>1;
                s = sum[mid]-sum[i];
                b = sum[p]-sum[i]
            }
        }
        */
        g = v[1];
        for (int i = 2, sum = 0; i < (int)v.size(); ++i) {
            sum += v[i];
            if (sum+g > n/2) break;
            if (sum > g && !s) s = sum;
            if (s) b = sum-s;
        }
        if (g && s && b && g < s && g < b) {
            cout << g << " " << s << " " << b << endl;
        } else {
            cout << "0 0 0" << endl;
        }
    }
    return 0;
}

