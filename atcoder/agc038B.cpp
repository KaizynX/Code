#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, k, res;
int p[N], s[N];
set<int> st;

int main()
{
    cin >> n >> k;
    p[0] = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        s[i] = s[i-1]+(p[i] < p[i-1]);
    }
    for (int i = 0; i < k; ++i) st.insert(p[i]);
    for (int l = 1, r = k, flag = 1; r <= n; r = (++l)+k-1) {
        if (s[r]-s[l] == 0) {
            res += flag;
            flag = 0;
        } else {
            int minv = *st.begin(), maxv = *st.rbegin();
            if (l == 1 || p[l-1] != minv || p[r] < maxv) ++res;
        }
        st.erase(p[l-1]);
        st.insert(p[r]);
    }
    cout << res << endl;
    return 0;
}
