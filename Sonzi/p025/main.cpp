#include <iostream>

using namespace std;

int main()
{
    int n,m,max1;
    cin>>n;
    cin>>max1;
    for(int i=1;i<n;i++){
        cin>>m;
        if(m>max1){
            max1=m;
        }
    }
    cout<<max1;

}
