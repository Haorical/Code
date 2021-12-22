#include<bits/stdc++.h>
using namespace std;
#define N 1111
struct Node{
    int st,end,id;
    bool operator < (const Node &a) const{
        if(end == a.end) return st > a.st;
        return end<a.end;
    }
};
Node node[N];
int tmp[N];
int main(){
    int n,ee,k;
    while(~scanf("%d",&n)&&n){
        for(int i=1;i<=n;i++){
            scanf("%d%d",&node[i].st,&node[i].end);
            node[i].id=i;
        }
        sort(node+1,node+n+1);
        ee=-1;
        k=0;
        for(int i=1;i<=n;i++){
            if(node[i].st>ee){
                tmp[k++]=node[i].id;
                ee=node[i].end;
            }
        }
        for(int i=0;i<k-1;i++){
            printf("%d ",tmp[i]);
        }
        printf("%d\n",tmp[k-1]);
    }
    system("pause");
    return 0;
}
/*
将结束时间排个序，先结束早的
然后把开始时间小于结束时间的跳过即可
*/