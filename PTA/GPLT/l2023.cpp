//初看比较唬人，实际考图邻接表存储
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int v,e,k;
vector<int> g[N];
set<int> sss;
int color[N];
int main(){
    cin>>v>>e>>k;
    int t1,t2;
    for(int i=0;i<e;i++){
        cin>>t1>>t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    int n;
    cin>>n;
    while(n--){
        memset(color,0,sizeof(color));
        sss.clear();// 记得clear
        int flag=0;
        for(int j=1;j<=v;j++){
            cin>>color[j];
            sss.insert(color[j]);
        }
        if(sss.size()!=k) flag=1; // 必须就这几个颜色多了少了都不行
        if(!flag)
            for(int j=1;j<=v;j++){
                if(flag) break;
                int len=g[j].size();
                for(int t=0;t<len;t++){
                    if(color[j]==color[g[j][t]]){
                        flag=1;
                        break;
                    }
                }
            } 
        if(flag) cout<<"No"; // 注意yes no大小写
        else cout<<"Yes";
        if(n>0) cout<<endl;
    }
    system("pause");
    return 0;
}