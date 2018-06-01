#include <iostream>

using namespace std;

int a[105],cnt,n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        cnt=0;
        for(int j=1;j<=i-1;++j)
        {
            if(a[j]<a[i])
                cnt++;
        }
        cout<<cnt<<" ";
    }
    cout<<endl;
    return 0;
}
