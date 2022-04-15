//简单结构体排序
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct node{
    int id,cnt;
    int y;
}nd[N];
int cmp(node a,node b){
    if(a.y==b.y){
        if(a.cnt==b.cnt){
            return a.id<b.id;
        }else return a.cnt>b.cnt;
    }else return a.y>b.y;
}
int main(){
    int n;
    cin>>n;
    int k;
    for(int i=1;i<=n;i++){
        nd[i].id=i;
        cin>>k;
        int t1,t2;
        for(int j=0;j<k;j++){
            cin>>t1>>t2;
            nd[t1].id=t1;
            nd[t1].y+=t2;
            nd[t1].cnt++;
            nd[i].y-=t2;
        }
    }
    sort(nd+1,nd+n+1,cmp);
    for(int i=1;i<=n;i++){
        printf("%d %.2f",nd[i].id,1.0*nd[i].y/100);
        if(i<=n-1) cout<<endl;
    }
    system("pause");
    return 0;
}