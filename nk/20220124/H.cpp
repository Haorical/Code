#include<bits/stdc++.h>
using namespace std;
int a[1000002];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum+=abs(a[i]+a[j]-1000);
        }
    }
    cout<<sum;
    system("pause");
    return 0;
}