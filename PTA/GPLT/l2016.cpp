//初看并查集？实际搜索，类似连通块
// 尝试bfs,实际上dfs更简洁
// 用下标表示id的时候，空间尽可能大
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
bool inq[N]={false};
int n,k;
vector<int> v1,v2;
struct node{
    int sex;
    int step;
    int fid,mid;
}nd[N];
vector<int> bfs(int x){ //标准bfs
    queue<int> q;
    vector<int> v;
    v.push_back(x);
    q.push(x);
    nd[x].step=1;
    while (!q.empty()){
        int now=q.front();
        q.pop();
        if(nd[now].step==5) break;
        if(inq[nd[now].fid]==false&&nd[now].fid!=-1){
            q.push(nd[now].fid);
            inq[nd[now].fid]=true;
            nd[nd[now].fid].step=nd[now].step+1;
            v.push_back(nd[now].fid);
        }
        if(inq[nd[now].mid]==false&&nd[now].mid!=-1){
            q.push(nd[now].mid);
            inq[nd[now].mid]=true;
            nd[nd[now].mid].step=nd[now].step+1;
            v.push_back(nd[now].mid);
        }
    }
    return v;
}
int main(){
    cin>>n;
    int t1,t2,t3;
    char s;
    for(int i=0;i<N;i++){
        nd[i].fid=nd[i].mid=-1;//全部初始化为-1
    }
    for(int i=0;i<n;i++){
        cin>>t1>>s>>t2>>t3;
        nd[t1].sex=(s=='M'?1:0);
        nd[t1].fid=t2;
        if(t2!=-1) nd[t2].sex=1; //要标记父母性别
        nd[t1].mid=t3;
        if(t3!=-1) nd[t3].sex=0;
    }
    cin>>k;
    while(k--){
        cin>>t1>>t2;
        if(nd[t1].sex==nd[t2].sex){
            cout<<"Never Mind";
        }else{
            memset(inq,0,sizeof(inq));
            v1=bfs(t1); //t1的5代所有人
            memset(inq,0,sizeof(inq));
            v2=bfs(t2); //t2 5代所有人
            set<int> s;
            int l1=v1.size();
            int l2=v2.size();
            for(int i=0;i<l1;i++){
                s.insert(v1[i]);
            }
            for(int i=0;i<l2;i++){
                s.insert(v2[i]);
            }
            if(l1+l2==s.size()) cout<<"Yes"; //有重复的一去重大小会变
            else cout<<"No";
        }
        if(k>0) cout<<'\n';
    }
//     system("pause");
    return 0;
}