#include <bits/stdc++.h>

using namespace std;

const int N = 20;
typedef pair<int, int> pii;


int main()
{
    int num;
    string str;
    stringstream ss;
    while (cin >> str) {
        ss.clear();
        ss << str;
        ss >> num;
        cout << num << endl;
    }
    return 0;
}