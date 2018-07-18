#include <iostream>

using namespace std;

int main()
{
    int minn=0,step=0;
    int n;cin>>n;
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a>minn)step+=a-minn;
        minn=a;
    }
    cout<<step;
    return 0;
}
