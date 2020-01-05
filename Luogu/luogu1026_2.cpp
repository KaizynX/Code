#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e2+7;
const int K = 4e2+7;

int p, k, n, s;
int dp[N][K], w[N][N];
string str;
vector<string> dic;

int main()
{
    cin >> p >> k;
    n = p*20;
    for (int i = 0; i < p; ++i) {
        string tmp;
        cin >> tmp;
        str += tmp;
    }
    cin >> s;
    for (int i = 0; i < s; ++i) {
        string tmp;
        cin >> tmp;
        dic.emplace_back(tmp);
    }
    for (int i = s-1; i >= 0; --i) {
        for (int j = 0; j < (int)dic.size(); ++j) {
            if (i == j) continue;
            if (dic[i].find(dic[j]) == 0) {
                dic.erase(dic.begin()+i);
                break;
            }
        }
    }
#ifdef DEBUG
    for (auto i : dic) cout << i << " ";
    cout << endl;
#endif
    for (int t = 0, p; t < (int)dic.size(); ++t) {
        p = 0;
        while ((p = str.find(dic[t], p)) != str.npos) {
            for (int i = 1; i <= p+1; ++i)
                for (int j = p+dic[t].length(); j <= n; ++j)
                    ++w[i][j];
            ++p;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i && j <= k; ++j) {
            for (int l = max(0, j-1); l < i; ++l) {
                dp[i][j] = max(dp[i][j], dp[l][j-1]+w[l+1][i]);
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
