#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int v[N],w[N],dp[N][N];
int f[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         dp[i][j]=dp[i-1][j];
    //         if(j>=v[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-v[i]]+w[i]); //状态转移方程

    //     }
    // }
    //cout<<dp[n][m];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            f[j]=max(f[j],f[j-v[i]]+w[i]); //优化
        }
    }
    cout<<f[m];
    system("pause");
}