#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;

int n;
string str, sss, article;
map<string, string> mp;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str;
    while (cin >> str && str != "END") {
        cin >> sss;
        mp[sss] = str;
    }
    cin >> str; cin.get();
    while (getline(cin, str) && str != "END")
        article += str+'\n';
    for (int i = 0, j; i < (int)article.length();) {
        if (article[i] < 'a' || article[i] > 'z') cout << article[i++];
        else {
            str = "";
            j = 0;
            while (article[i+j] >= 'a' && article[i+j] <= 'z')
                str += article[i+j++];
            i += j;
            if (mp.find(str) != mp.end()) cout << mp[str];
            else cout << str;
        }
    }
    return 0;
}
