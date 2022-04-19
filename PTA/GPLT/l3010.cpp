// BST建立并判断完全二叉树
#include<bits/stdc++.h>
using namespace std;
int n;
int maxn=1;
struct node{
    int nid; //用nid来模拟数组存数的下标
    int data;
    node *left,*right;
};
void insert(node* &root,int data){
    if(root==nullptr){
        root=new node;
        root->data=data;
        root->left=root->right=nullptr;
        return; // 记得return
    }
    if(data>root->data) insert(root->left,data);
    else insert(root->right,data);
}

int ans=0;
void bfs(node* root){
    queue<node*> q;
    root->nid=1;
    q.push(root);
    while (!q.empty())
    {
        node *now=q.front();
        q.pop();
        cout<<now->data;
        ans++;
        if(ans<n) cout<<' ';
        if(now->left!=nullptr){ 
            q.push(now->left);
            now->left->nid=now->nid*2; //nid*2
            maxn=max(now->left->nid,maxn);
        }
        if(now->right!=nullptr){
            q.push(now->right);
            now->right->nid=now->nid*2+1; //nid*2+1
            maxn=max(now->right->nid,maxn);
        }
    }
    // 写到这，不会判断是不是完全二叉树了
}
int main(){
    cin>>n;
    int t;
    node *root=nullptr;
    for(int i=0;i<n;i++){
        cin>>t;
        insert(root,t);
    }
    bfs(root);
    cout<<endl;
    if(maxn==n) cout<<"YES"; //用完全二叉树性质判断 最大节点id和个数一样
    else cout<<"NO";
    system("pause");
    return 0;
}