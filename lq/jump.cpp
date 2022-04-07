#include <bits/stdc++.h>
using namespace std;
const int MIN=-0x3fffffff;
int main()
{
  int n,m;
  cin>>n>>m;
  int dp[n+1][m+1];
  fill(dp[0],dp[0]+(n+1)*(m+1),0);
  int x[]={0,0,0,-1,-1,-1,-2,-2,-3};
  int y[]={-1,-2,-3,0,-1,-2,0,-1,0};
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>dp[i][j];
      int u=MIN;
      for(int k=0;k<9;k++){
          if(i+x[k]>0&&j+y[k]>0)
            u=max(u,dp[i+x[k]][j+y[k]]);
      }
      if(u!=MIN) dp[i][j]+=u;
    }
  }
  cout<<dp[n][m];
  system("pause");
  return 0;
}