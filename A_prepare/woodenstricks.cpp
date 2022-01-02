/*
#include<bits/stdc++.h> 
using namespace std;
int c,n;
struct Node{
    int first,next;
}node[5010];
bool flag[5010];
bool cmp(const Node p,const Node q){
    if(p.first!=q.first) return p.first<q.first;
    else return p.next<q.next;
}
int main(){
    cin>>c;
    while (c--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>node[i].first>>node[i].next;
        sort(node+1,node+n+1,cmp);
        memset(flag,0,sizeof(flag));
        int s=0;
        int k,m=1;
        bool j;
        while(true){
            s++;
            j=true;
            k=node[m].next;
            flag[m]=true;
            for(int i=m+1;i<=n;i++){
                if(!flag[i]&&node[i].next>=k){
                    k=node[i].next;
                    flag[i]=true;
                }else if(!flag[i]&&j&&node[i].next<k){
                    m=i;
                    j=false;
                }
            }
            if(j) break;
        }
        cout<<s<<endl;
    }
    system("pause");
    return 0;
}
*/
#include<bits/stdc++.h> 
using namespace std;
int c,n;struct Node{int first,next;}node[5010];bool flag[5010];bool cmp(const Node p,const Node q){if(p.first!=q.first) return p.first<q.first;else return p.next<q.next;}int main(){cin>>c;while(c--){cin>>n;for(int i=1;i<=n;i++)cin>>node[i].first>>node[i].next;sort(node+1,node+n+1,cmp);memset(flag,0,sizeof(flag));int s=0,k,m=1;bool j;while(1){s++;j=1;k=node[m].next;flag[m]=1;for(int i=m+1;i<=n;i++){if(!flag[i]&&node[i].next>=k){k=node[i].next;flag[i]=1;}else if(!flag[i]&&j&&node[i].next<k){m=i;j=0;}}if(j) break;}cout<<s<<endl;}}