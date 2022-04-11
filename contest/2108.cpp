#include<bits/stdc++.h>
using namespace std;
const int N=310;
int s[N],dp[N][N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]+=s[i-1];
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
           int j=i+len-1;
           dp[i][j]=0x3fffffff;
           for(int k=i;k<=j;k++){
               dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+s[j]-s[i-1]);
           } 
        }
    }
    cout<<dp[1][n];
    system("pause");
    return 0;
}