#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int v[N],w[N],dp[N][N],f[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=v[i]) dp[i][j]=max(dp[i][j],dp[i][j-v[i]]+w[i]);
        }
    }
    // 优化版
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=m;j++){
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout<<dp[n][m]<<" "<<f[m];
    system("pause");
    return 0;
}