#include<bits/stdc++.h>
using namespace std;
int yy[100002],f[100002];
int fuck(int x){
    int ds;
    if(yy[x]==-1) return 1;
    else{
        ds = fuck(yy[x])+1;
    }
    f[x]=ds;
    return ds;
}
int main(){
    int n;
    cin>>n;
    int t;
    for(int i=1;i<=n;i++){
        cin>>t;
        yy[i]=t;
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,fuck(i));      
    }
    cout<<mx<<endl;
    for(int i=1;i<=n;i++){
        if(mx==f[i]){
            cout<<i<<" ";
        }      
    }
    system("pause");
    return 0;
}