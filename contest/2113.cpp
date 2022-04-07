#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000+10;
int dp[MAXN],a[MAXN];
int pre[MAXN];

void dfs(int s){
    if(pre[s]==s){
        cout<<a[s]<<" ";
        return;
    }
    dfs(pre[s]);
    cout<<a[s]<<" ";
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=-1,u=-1;
    for(int i=1;i<=n;i++){
        dp[i]=1;
        pre[i]=i;
        for(int j=1;j<i;j++){
            if(a[i]<a[j]&&dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                pre[i]=j;
            }
        }
        if(dp[i]>ans){
            ans=dp[i];
            u=i;
        }
    }
    //cout<<u;
    dfs(u);
    //cout<<ans;
    system("pause");
    return 0;
}