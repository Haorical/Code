#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    int n=log2(t+2)-1;
    //cout<<n;
    int j=1,sum=0;
    for(int i=1;i<=n;i++){
        sum+=(j*(1<<i));
        j++;
    }
    //cout<<n;
    int a=t-((1<<(n+1))-2);
    sum+=a*j;
    cout<<sum;
    system("pause");
}