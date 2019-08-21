#include <bits/stdc++.h>

using namespace std;

const int kN = 1e2+7;

int T;
char s[kN];

int main()
{
    scanf("%d", &T);
    while (T--){
        priority_queue<int, vector<int>, greater<int> > q;
        scanf("%s", s);
        int len = strlen(s);
        for (int i = 0; i < len; ++i) 
            if (s[i] == 'z')
                q.push(i);
        while (q.size()) {
            int cur = q.top();
            q.pop();
            if (s[cur] != 'z') continue;
            // Rikka
            s[cur] = 'a';
            // Yuta
            for (int i = 0; i < len; ++i) {
                if (s[i] == 'z') continue;
                if (++s[i] == 'z') q.push(i);
                break;
            }
        }
        printf("%s\n", s);
    }
    return 0;
}
