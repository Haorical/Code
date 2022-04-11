#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int dp[N][N];
char a[N],b[N];
int main(){
    cin>>a+1>>b+1;
    int la=strlen(a+1),lb=strlen(b+1);
    for(int i=1;i<=la;i++){
        for(int j=1;j<=lb;j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[la][lb];
    system("pause");
    return 0;
}