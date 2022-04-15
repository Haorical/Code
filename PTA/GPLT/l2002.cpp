#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct Node{
    int cur,next,data;
}node[N];
bool flag[N];
vector<Node> l1,l2;
int main(){
    int p,n;
    cin>>p>>n;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>node[a].data>>node[a].next;
        node[a].cur=a;
    }
    l1.push_back(node[p]);
    flag[abs(node[p].data)]=true;
    p=node[p].next;
    for(int i=p;i!=-1;){  //巨坑 不要判断节点个数 判断链表下一个地址是不是-1
        if(flag[abs(node[i].data)]==false){
            flag[abs(node[i].data)]=true;
            Node tp=l1.back(); //取最后节点
            l1.pop_back(); //弹出
            tp.next=node[i].cur; //更改上个节点的指针
            l1.push_back(tp);
            l1.push_back(node[i]);
        }else{
            if(!l2.empty()){ //判空
                Node tp=l2.back();
                l2.pop_back();
                tp.next=node[i].cur;
                l2.push_back(tp);
            }
            l2.push_back(node[i]);
        }
        i=node[i].next;
    }
    for(int i=0;i<l1.size()-1;i++){
        printf("%05d %d %05d\n",l1[i].cur,l1[i].data,l1[i].next);
    }
    Node t1=l1.back();
    printf("%05d %d %d\n",t1.cur,t1.data,-1);
    if(!l2.empty()){ //判空
    for(int i=0;i<l2.size()-1;i++){
        printf("%05d %d %05d\n",l2[i].cur,l2[i].data,l2[i].next);
    }
    t1=l2.back();
    printf("%05d %d %d",t1.cur,t1.data,-1);}
    system("pause");
    return 0;
}