#include <bits/stdc++.h>

using namespace std;

int myAtoi(string str) {
        long long res = 0, tag = 1, edge = 3000000000;
        int cur = 0;
        while(cur < str.length() && str[cur] == ' ') cur++;
        if(cur < str.length() && str[cur] == '-') tag = -1, cur++;
        if(cur < str.length() && str[cur] == '+') cur++;
        while(cur < str.length() && str[cur] >= '0' && str[cur] <= '9')
        {
            res = res*10+str[cur]-'0';
            if(res > edge) break;
            cur++;
        }
        if(tag == 1) return res <= INT_MAX ? res : INT_MAX;
        res *= tag;
        return res >= INT_MIN ? res : INT_MIN;
    }

int main()
{
    string str;
	getline(cin, str);
	cout << myAtoi(str) << endl;
	return 0;
}
