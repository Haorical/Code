#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+10;
struct Node{
    int s,e;
}node[MAXN];
//贪心，最早结束
bool cmp(Node x,Node y){
    return x.e<y.e;
}
int main(){
    int n,m,l,r;
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            cin>>node[i].s>>node[i].e;
        }
        sort(node,node+n,cmp);
        for(int i=0;i<m;i++){
            cin>>l>>r;
            int ans=0;
            for(int i=0;i<n;i++){
                if(node[i].e>r) break;
                if(node[i].s>=l){
                    ans++;
                    l=node[i].e; //非常巧妙
                }
            }
            cout<<ans<<endl;
        }
    }
    system("pause");
    return 0;
}