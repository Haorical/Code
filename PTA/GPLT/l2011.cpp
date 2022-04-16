// 也是建树，和6题差不多，一遍过
#include<bits/stdc++.h>
using namespace std;
const int N=50;
struct  node
{
    int data;
    node *left,*right;
};
 
int pre[N],in[N],n;

node* create(int pl,int pr,int l,int r){
    if(pl>pr) return nullptr; //return条件
    node *root=new node;
    root->data=pre[pl];
    int k;
    for(k=l;k<=r;k++){
        if(in[k]==pre[pl]) break;
    }
    int len=k-l;
    root->right=create(pl+1,pl+len,l,k-1);
    root->left=create(pl+len+1,pr,k+1,r);
    return root;
}
int num=0;
void bfs(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *now=q.front();
        q.pop();
        cout<<now->data;
        num++;
        if(num<n) cout<<" ";
        if(now->left!=nullptr) q.push(now->left);
        if(now->right!=nullptr) q.push(now->right);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    node *root=create(0,n-1,0,n-1);
    bfs(root);
    system("pause");
    return 0;
}