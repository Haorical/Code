#include<bits/stdc++.h>
using namespace std;
const int N=50;
struct node{
    int data;
    node *left,*right;
};
int pre[N],in[N],post[N];
int n;
node* create(int postL,int postR,int L,int R){ //建立二叉树
    if(postL>postR) return nullptr;
    node *root=new node;
    root->data=post[postR]; //后序数组最后是根节点
    int k;
    for(k=L;k<=R;k++){ //在中序遍历中查找根节点
        if(in[k]==post[postR]){
            break;
        }
    }
    int numLeft=k-L;//左子树节点个数  
    //postR 和 k 是根节点， 不包含
    root->left=create(postL,postL+numLeft-1,L,k-1); //建立左子树 更新中序R=k-1
    root->right=create(postL+numLeft,postR-1,k+1,R);//建立右子树 更新中序L=k+1
    return root;
}
int num=0;
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now=q.front();
        q.pop();
        num++;
        cout<<now->data;
        if(num<n) cout<<" ";
        if(now->left!=nullptr) q.push(now->left); //注意判空
        if(now->right!=nullptr) q.push(now->right);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>post[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    node *root=create(0,n-1,0,n-1);
    bfs(root);
    system("pause");
    return 0;
}