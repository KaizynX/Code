#include <bits/stdc++.h>

using namespace std;

int T, n, k;

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n >> k;
        if(n == 0) cout << "Bob" << endl;
        else if(k%3) cout << (n%3 ? "Alice" : "Bob") << endl;
        else
        {
            if(n%(k+1) == 0) cout << "Bob" << endl;
            else
            {
                if(n%(k+1) == k) cout << "Alice" << endl;
                else cout << (n%(k+1)%3 ? "Alice" : "Bob") << endl;
            }
        }
    }
    return 0;
}
