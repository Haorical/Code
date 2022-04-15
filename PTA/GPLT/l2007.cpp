// 并查集 不能用路径压缩
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int vis[N],m[N];
struct node{
    double ans1,ans2;
    int id,num;
};
int s[N];
int n;
bool cmp(node a,node b){
    if(a.ans)
}
void init(){
    for(int i=0;i<n;i++){
        s[i]=i;
    }
}
int find(int x){
    if(x==s[x]) return x;
    int a=find(s[x]);
    s[x]=a;
    return a;
}
void Union(int x,int y){
    int a=find(x);
    int b=find(y);
    if(a!=b) s[b]=a;
}
int main(){

    system("pause");
    return 0;
}