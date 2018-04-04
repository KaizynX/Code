#include <iostream>

using namespace std;

int main()
{
    int k;
    cin>>k;
    for(int i=1;i<=k;++i){
        for(int i=1;i<=k;++i)cout<<"*";
        for(int i=1;i<=k;++i)cout<<"x";
        for(int i=1;i<=k;++i)cout<<"*";
        cout<<endl;
    }
    for(int i=1;i<=k;++i){
        for(int i=1;i<=k;++i)cout<<"  ";
        for(int i=1;i<=k;++i)cout<<"xx";
        cout<<endl;
    }
    for(int i=1;i<=k;++i){
        for(int i=1;i<=k;++i)cout<<"*";
        for(int i=1;i<=k;++i)cout<<" ";
        for(int i=1;i<=k;++i)cout<<"*";
        cout<<endl;
    }
    return 0;
}
