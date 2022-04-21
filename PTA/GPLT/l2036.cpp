// 模拟
#include<bits/stdc++.h>
using namespace std;
const int N=210;
int cost[N][N],r[N];
int main(){
    int n,m;
    cin>>n>>m;
    int t1,t2,t3;
    for(int i=0;i<m;i++){
        cin>>t1>>t2>>t3;
        cost[t1][t2]=cost[t2][t1]=t3;
    }
    int k;
    cin>>k;
    int MIN=0x3fffffff,u=-1,cnt=0;
    for(int i=1;i<=k;i++){
        set<int> s;
        int flag=0;
        cin>>t1;
        memset(r,-1,sizeof(r));
        r[0]=0;
        for(int j=1;j<=t1;j++){
            cin>>r[j]; //标错下标了
        }
        r[t1+1]=0; //这里设置了结束后面就不用判断了
        int ans=0;
        for(int j=0;j<=t1;j++){
            // cout<<r[j]<<' '<<r[j+1]<<endl;
            if(cost[r[j]][r[j+1]]==0){
                // cout<<cost[r[j]][r[j+1]]<<endl;
                flag=1;
                break;
            }
            // cout<<cost[r[j]][r[j+1]]<<endl;
            ans+=cost[r[j]][r[j+1]];
            int pre=s.size();
            s.insert(r[j]);
            if(s.size()==pre){
                flag=1;
                break;
            }
        }
        if(flag||s.size()!=n+1||cost[r[t1]][0]==0) continue;
        cnt++;
        if(ans<MIN){
            MIN=ans;
            u=i;
        }
    }
    cout<<cnt<<'\n'<<u<<' '<<MIN;
    system("pause");
    return 0;
}