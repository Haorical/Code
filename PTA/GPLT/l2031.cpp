// 很直白的搜索 dfs bfs差不多 记忆化搜索。。
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
// vector<int> v[N];
// 貌似一个pre数组就可以 对每个节点遍历深度
int pre[N];
// 先找入口 用pre的话,入口都不用找
int height[N];

int geth(int s){
    if(s==-1) return 0;
    if(height[s]==0) height[s]=geth(pre[s])+1;
    return height[s];
}

int main(){
    int n;
    memset(pre,-1,sizeof(pre));
    cin>>n;
    int k,t;
    for(int i=1;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>t;
            pre[t]=i;
        }
    }
    int u=-1,MAX=-1;
    for(int i=1;i<=n;i++){
        if(geth(i)>MAX){
            MAX=geth(i);
            u=i;
        }
    }
    cout<<u;
    system("pause");
    return 0;
}