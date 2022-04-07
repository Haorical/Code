#include<bits/stdc++.h>
using namespace std;
int a[20];
bool vis[20]={false};
int main(){
    for(int i=0;i<20;i++){
        cin>>a[i];
    }
    for(int i=0;i<20;i++){
        for(int j=i+1;j<20;j++){
            if(a[j]%a[i]==0){
                vis[j]=true;
            }
        }
    }
    for(int i=0;i<20;i++){
        if(vis[i])
            cout<<a[i]<<endl;
    }
    system("pause");
    return 0;
}