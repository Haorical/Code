#include<bits/stdc++.h>
using namespace std;
const int N=1010;
struct Node{
    double x,y; //测试点3 月饼数量可能为小数
    double a;
}nd[N];
int cmp(Node x,Node y){
    return x.a>y.a;
}
int main(){
    int n;
    double d; //段错误 int double类型比较造成
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>nd[i].x;
    }
    for(int i=0;i<n;i++){
        cin>>nd[i].y;
        nd[i].a=1.0*nd[i].y/nd[i].x;
    }
    sort(nd,nd+n,cmp);
    //cout<<nd[0].x;
    double ans=0;
    int i=0;
    while(d>0){
        if(d>=nd[i].x){
            n--; //太傻逼了 月饼可能会卖完 一直循环段错误
            d-=nd[i].x;
            ans+=nd[i].y;
        }else{
            ans+=d*nd[i].a;
            break;
            d=0;
        }
        if(n==0) break;
        i++;
    }
    printf("%.2f",ans);
    system("pause");
    return 0;
}
//简单贪心