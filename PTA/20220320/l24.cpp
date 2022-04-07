#include<bits/stdc++.h>
using namespace std;
const int MAXN=210;
int n,m;
int cost[MAXN][MAXN],r[MAXN];
unordered_map<int,int> ju;
int main(){
    cin>>n>>m;
    fill(cost[0],cost[0]+MAXN*MAXN,0);
    for(int i=1;i<=m;i++){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        cost[t1][t2]=t3;
        cost[t2][t1]=t3;
    }
    int k;
    cin>>k;
    int yk=0,ok=k,MIN=0x3fffffff,u=-1;
    while(k--){
        ju.clear();
        int n2,sum=0;
        cin>>n2;
        memset(r,0,sizeof(r));
        r[0]=0;
        for(int i=1;i<=n2;i++){
            cin>>r[i];
        }
        if(n2>n||n2<n) continue;
        r[n2+1]=0;
        int flag=1;
        for(int i=0;i<=n2;i++){
            ju[r[i]]=ju[r[i+1]]=1;
            if(cost[r[i]][r[i+1]]==0){
                flag=0;
                break;
            }
            else sum+=cost[r[i]][r[i+1]];
        }
        if(!flag) continue;
        if(ju.size()<n) continue;
        if(sum<MIN){
            MIN=sum;
            u=ok-k;
        }
        yk++;
    }
    cout<<yk<<'\n'<<u<<" "<<MIN;
    system("pause");
    return 0;
}