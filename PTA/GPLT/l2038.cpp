// 一个pre数组的事 记忆化搜索
// vector 重载 < 直接用
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int pre[N];
int height[N];
int u=-1,MAX=-1;
vector<int> vv;

int geth(int s){
    if(s==-1) return 0;
    if(height[s]==0) height[s]=geth(pre[s])+1;
    return height[s];
}

void dfs(int s,vector<int>& _v){
    if(s==-1) return;
    dfs(pre[s],_v);
    _v.push_back(s);
}

int main(){
    int n,t1,t2;
    memset(pre,-1,sizeof(pre));
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t1;
        for(int j=0;j<t1;j++){
            cin>>t2;
            pre[t2]=i;
        }
    }
    for(int i=0;i<n;i++){
        if(geth(i)>MAX){
            MAX=geth(i);
            vv.clear();
            vv.push_back(i);
        }else if(geth(i)==MAX){
            vv.push_back(i);
        }
    }
    cout<<MAX<<endl;
    vector<vector<int>> ans;
    for(int i=0;i<vv.size();i++){
        vector<int> v;
        dfs(vv[i],v);
        ans.push_back(v);
    }
    sort(ans.begin(),ans.end());
    vector<int> v=ans[0];
    for(int i=0;i<ans[0].size();i++){
        cout<<ans[0][i];
        if(i<ans[0].size()-1) cout<<' ';
    }
    system("pause");
    return 0;
}