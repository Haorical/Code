#include<bits/stdc++.h>
using namespace std;
int a[1000002];
int main(){
    memset(a,0,sizeof(a));
    int m,n;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    for(int i=0;i<m;i++){
        cout<<a[i]<<" ";
    }
    system("pause");
    return 0;
}