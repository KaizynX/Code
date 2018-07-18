#include <iostream>

using namespace std;

int main()
{
    int apple[10],taotao,ans=0;
    for(int i=0;i<10;i++)
    {
        cin>>apple[i];
    }
    cin>>taotao;
    taotao+=30;
    for(int i=0;i<10;i++)
    {
        if(apple[i]<=taotao)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
