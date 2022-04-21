//模拟链表，结构体做就可以
// 奇数点情况
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Node{
    int now;
    int front;
    int data;
    int next;
}node[N];
map<int,Node> mp; 
int main(){
    int p1,p2,n;
    cin>>p1>>n;
    int t1,t2,t3;
    for(int i=1;i<=n;i++){
        cin>>t1>>t2>>t3;
        node[t1].now=t1;
        node[t1].data=t2;
        node[t1].next=t3;
        if(t3==-1) p2=t1;
    }
    int id=1;
    for(int i=p1;i!=-1;i=node[i].next){
        // cout<<node[i].data<<endl;
        mp[id]=node[i];
        id++;
    }
    int qqq;
    n=mp.size(); // 有多余节点
    if(n%2==0) qqq=n/2;
    else qqq=n/2+1;
    // cout<<qqq;
    for(int i=1;i<=qqq;i++){
        int j=n+1-i;
        if(i==j) printf("%05d %d -1",mp[i].now,mp[i].data);
        else {printf("%05d %d %05d\n%05d %d",mp[j].now,mp[j].data,mp[i].now,mp[i].now,mp[i].data);
        if(i==n/2) printf(" -1\n");
        else printf(" %05d\n",mp[j-1].now);}
    }
    system("pause");
    return 0;
}

// 00100 5
// 00000 4 99999
// 00100 1 12309
// 33218 3 00000
// 99999 5 -1
// 12309 2 33218