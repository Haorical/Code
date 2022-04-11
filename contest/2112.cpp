#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int> m;
void lis(string x){
    int dp[256];
    int l=x.length();
    int u=-1;
    for(int i=0;i<l;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(m[x[j]]<=m[x[i]])
                dp[i]=max(dp[i],dp[j]+1);
        }
        u=max(u,dp[i]);
    }
    cout<<u;
}
int main(){
    string al,s;
    cin>>al;
    int l=al.length();
    for(int i=0;i<l;i++){
        m[al[i]]=i;
    }
    while(cin>>s){
        lis(s);
    }
    system("pause");
    return 0;
}