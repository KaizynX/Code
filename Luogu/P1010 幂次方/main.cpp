#include <iostream>
#include <cstring>
using namespace std;

string solve(long long n)
{
    string res;
    int pos=0;
    while(n)
    {
        if(n%2==1)
        {
            if(pos==0)res="2(0)";
            else if(pos==1)
            {
                if(res=="")res="2";
                else res="2+"+res;
            }
            else
            {
                if(res=="")res="2("+solve(pos)+")";
                else res="2("+solve(pos)+")+"+res;
            }
        }
        pos++;
        n>>=1;
    }
    return res;
}

int main()
{
    long long n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}
