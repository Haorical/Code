#include<bits/stdc++.h>

const int MAXN=100000;
using namespace std;

char a[MAXN];
char b[MAXN];
int dp[MAXN][MAXN];

int main(){
    int n;
    cin>>a+1>>b+1;
    int la=strlen(a+1),lb=strlen(b+1);
    for(int i=0;i<=la;++i){
        dp[i][0]=0;
    }
    for(int j=0;j<=lb;++j){
        dp[0][j]=0;
    }
    for(int i=1;i<=la;++i){
        for(int j=1;j<=lb;++j){
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
