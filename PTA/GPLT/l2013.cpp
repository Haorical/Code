// 并查集通过查祖宗节点可以找到有几个集合，用来查连通块数量很好用
// 改成循环还是段错误，数组开小了
// 尝试搜索，csdn都用的dfs,不过bfs不是用来求连通块更好用吗？？？
// #include<bits/stdc++.h>
// using namespace std;
// const int N=510;
// int n,m;
// bool vis[N]={false};
// int f[N];
// struct node{
//     int x,y;
// }nd[10*N];//这里开小了，应该按m道路条数最大值开，不用城市数开。
// void init(){
//     for(int i=0;i<n;i++){
//         f[i]=i;
//     }
// }
// int findf(int x){
//     int t=x;
//     while(t!=f[t]){
//         t=f[t];
//     }
//     int a=x;
//     while(f[a]!=t){
//         int z=a;
//         f[z]=t;
//         a=f[z];
//     }
//     return t;
//     // if(x==f[x]) return x;
//     // f[x]=findf(f[x]);
//     // return f[x]; 
// }
// void Union(int a,int b){
//     a=findf(a);
//     b=findf(b);
//     if(a!=b) f[a]=b;
// }
// int count(){
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         if(f[i]==i&&vis[i]==false){
//             cnt++;
//         }
//     }
//     return cnt;
// }
// int main(){
//     cin>>n>>m;
//     init();
//     for(int i=0;i<m;i++){
//         cin>>nd[i].x>>nd[i].y;
//         Union(nd[i].x,nd[i].y);
//     }
//     int cnt1=count(),cnt2=0,cnt3=0;
//     int k,u;
//     cin>>k;
//     while(k--){
//         cin>>u;
//         cnt3++;
//         vis[u]=true;
//         init();//每次都要初始化
//         for(int i=0;i<m;i++){
//             if(!vis[nd[i].x]&&!vis[nd[i].y]) Union(nd[i].x,nd[i].y);
//         }
//         cnt2=count();
//         if(cnt1<cnt2) printf("Red Alert: City %d is lost!",u);
//         else printf("City %d is lost.",u);
//         cnt1=cnt2; //集合个数每次都要更新
//         if(k>0) cout<<'\n';
//         if(cnt3==n) printf("\nGame Over.");
//     }
//     system("pause");
//     return 0;
// }

//尝试bfs搜索实现,我太nb了,一遍过
#include<bits/stdc++.h>
using namespace std;
const int N=510;
vector<int> v[N],lost;
bool inq[N]={false};
int n,m,k,u;
void bfs(int x){
    queue<int> q;
    q.push(x);
    inq[x]=true; //inq队列，判断是否入过队，约等于有没有访问过
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<v[now].size();i++){
            if(inq[v[now][i]]==false){
                q.push(v[now][i]);
                inq[v[now][i]]=true;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    int t1,t2;
    for(int i=0;i<m;i++){
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(inq[i]==false){
            sum++;
            bfs(i);
        }
    }
    memset(inq,0,sizeof(inq));
    cin>>k;
    int ans,cnt3=0;
    while(k--){
        cnt3++;
        cin>>u;
        ans=0;
        memset(inq,0,sizeof(inq));//每次初始化
        lost.push_back(u);
        for(int i=0;i<lost.size();i++){
            inq[lost[i]]=true;//从lost里给inq赋初值
        }
        for(int i=0;i<n;i++){
            if(inq[i]==false){
                ans++;
                bfs(i);
            }
        }
        if(sum<ans) printf("Red Alert: City %d is lost!",u);
        else printf("City %d is lost.",u);
        sum=ans;
        if(k>0) cout<<'\n';
        if(cnt3==n) printf("\nGame Over.");
    }
    system("pause");
    return 0;
}