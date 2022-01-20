#include<bits/stdc++.h>
using namespace std;
int mp[10002][10002],tmp[10002][10002];
int main(){
    int n,m;
    cin>>n>>m;
    memset(mp,0,sizeof mp);
    for(int i=0;i<m;i++){
        int s,d;
        cin>>s>>d;
        mp[s][d]=1;
        mp[d][s]=1;
    }
    int k;
    cin>>k;
    while(k--){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                tmp[i][j]=mp[i][j];
            }
        }
        int np;
        cin>>np;
        for(int i=0;i<np;i++){
            int t;
            cin>>t;
            for(int j=1;j<=n;j++){
                tmp[t][j]=0;
                tmp[j][t]=0;
            }
        }
        int flag=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(tmp[i][j]==1){
                    flag=0;
                    break;
                }
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    system("pause");
    return 0;
}