#include<bits/stdc++.h>
using namespace std;
const int MAXN=1010;
int a[MAXN],dp[MAXN];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int u=-0x3fffffff;
    dp[0]=a[0];
    u=max(u,dp[0]);
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-1]+a[i],a[i]);// 写错转移方程了
        u=max(u,dp[i]);
    }
    cout<<u;
    system("pause");
    return 0;
}