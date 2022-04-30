// 搜索
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int y[N];
int n,m;
vector<int> tmp,path;
void dfs(int index,int value){
    if(index==n+1||value==0){
        if(value==0) path=tmp;
        return;
    }
    dfs(index+1,value);
    tmp.push_back(index);
    if(value-y[index]>0)
        dfs(index+1,value-y[index]);
    tmp.pop_back();
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>y[i];
    }
    dfs(1,m);
    for(auto i:path){
        cout<<i<<endl;
    }
    system("pause");
    return 0;
}