#include<bits/stdc++.h>
using namespace std;
int v[100002];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>v[i];
    }
    int sum,ans;
    sum=ans=0;
    for(int i=0;i<n;i++){
        ans+=sum*v[i];
        sum+=v[i];
    }
    cout<<ans<<endl;
    system("pause");
}