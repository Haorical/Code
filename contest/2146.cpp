//贪心 开始时间排序
#include<bits/stdc++.h>
using namespace std;
const int N=5010;
struct Node{
    int s,e;
}node[N];
int cmp(Node x,Node y){
    return x.s<y.s;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>node[i].s>>node[i].e;
    }
    sort(node,node+n,cmp);
    int sum1=0,sum2=0;
    int l,r;
    l=node[0].s;//一个阶段的左起点
    r=node[0].e;//一个阶段的终点
    sum1=r-l;
    for(int i=1;i<n;i++){
        if(node[i].s<=r){//开始时间<终点
            r=max(r,node[i].e);//维护终点
            sum1=max(sum1,r-l);//l-r的最大值
        }else{//开始>终点
            l=node[i].s;//新阶段 维护起点
            sum2=max(sum2,l-r);//l-r最大值 r是上一个终点
            r=node[i].e;//维护终点
        }
    }
    cout<<sum1<<' '<<sum2;
    system("pause");
    return 0;
}