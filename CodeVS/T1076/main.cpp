#include <iostream>
//Éµ·½·¨³¬Ê±
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    cin>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        for(int j=0;j<i;++j){
            if(a[j]>a[i])swap(a[j],a[i]);
        }
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
