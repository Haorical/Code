#include<bits/stdc++.h>
using namespace std;
const int MAXN=110;
int mp[MAXN][MAXN],dp[MAXN][MAXN];
int x[]={-1,1,0,0};
int y[]={0,0,-1,1};
int main(){
    int r,c;
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>mp[i][j];
            dp[i][j]=1;
        }
    }
    int ans=-1,u=-1,v=-1;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            for(int k=0;k<4;k++){
                int xx=i+x[k],yy=j+y[k];
                if(xx>=1&&xx<=r&&yy>=1&&yy<=r){
                    if(mp[i][j]>mp[xx][yy]&&dp[i][j]<dp[xx][yy]+1){
                        dp[i][j]=dp[xx][yy]+1;
                        if(dp[i][j]>ans){
                            ans=dp[i][j];
                            u=i;
                            v=j;
                        }
                    }
                }
            }
        }
    }
    cout<<u<<" "<<v;
    system("pause");
    return 0;
}