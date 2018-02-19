#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int mark[n+1],hao[n+1];
    for(int i=1;i<=n;i++){
        cin>>mark[i]>>hao[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(mark[i]>mark[j]){
                swap(mark[i],mark[j]);
                swap(hao[i],hao[j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<mark[i]<<" "<<hao[i]<<endl;
    }
    return 0;
}
