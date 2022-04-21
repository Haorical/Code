// map vector
// map pair类型变量 类似结构体
// 用结构题存map 重载<排序 vector自带<
#include<bits/stdc++.h>
using namespace std;
map<vector<int>,int> mp; // 只能用来统计数量，不能重载运算符
// 重新用node来保存
struct node
{
    vector<int> v;
    int cnt;
};

vector<int> v;

int cmp(node x,node y){
    if(x.cnt==y.cnt) return x.v<y.v;
    else return x.cnt>y.cnt;
}
vector<node> ans;
int main(){
    int n,m,t;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        v.clear();
        for(int j=0;j<m;j++){
            cin>>t;
            v.push_back(t);
        }
        mp[v]++;
    }
    for(auto i:mp){
        node tn;
        tn.v=i.first;
        tn.cnt=i.second;
        ans.push_back(tn);
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].cnt;
        for(int j=0;j<m;j++){
            cout<<' '<<ans[i].v[j];
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}