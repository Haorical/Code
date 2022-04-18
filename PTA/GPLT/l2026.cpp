// 记忆化搜索 和20题差不多
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int f[N],c[N];
vector<int> v[N];
int dfs(int s){
    if(s==-1) return 0;
    if(c[s]==-1) c[s]=dfs(f[s])+1;
    return c[s]; 
}
int main(){
    int n,t;
    cin>>n;
    memset(c,-1,sizeof(c));
    for(int i=1;i<=n;i++){
        cin>>t;
        f[i]=t;
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(c[i]==-1){
            c[i]=dfs(i);
            sum=max(sum,c[i]);
            v[c[i]].push_back(i);
        } 
    }
    cout<<sum<<endl;
    int len=v[sum].size();
    for(int i=0;i<len;i++){
        cout<<v[sum][i];
        if(i<len-1) cout<<' ';
    }
    system("pause");
    return 0;
}