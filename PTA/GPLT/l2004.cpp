// 二叉搜索树
// 代码量比较大
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
};
void insert(node* &root,int data){
    if(root==nullptr){
        root=new node;
        root->data=data;
        root->left=root->right=nullptr;
        return;
    }
    if(data<root->data) insert(root->left,data);
    else insert(root->right,data);
}
void preOrder(node *root,vector<int> &v){
    if(root==nullptr) return;
    v.push_back(root->data);
    preOrder(root->left,v);
    preOrder(root->right,v);
}
void preOrder2(node *root,vector<int> &v){
    if(root==nullptr) return;
    v.push_back(root->data);
    preOrder2(root->right,v);
    preOrder2(root->left,v);
}

void postOrder(node *root,vector<int> &v){
    if(root==nullptr) return;
    postOrder(root->left,v);
    postOrder(root->right,v);
    v.push_back(root->data);
}

void postOrder2(node *root,vector<int> &v){
    if(root==nullptr) return;
    postOrder2(root->right,v);
    postOrder2(root->left,v);
    v.push_back(root->data);
}
int main(){
    int n;
    cin>>n;
    vector<int> v1,v2,v3;
    node *root=nullptr; //指针定义时一定要赋空指针
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        v1.push_back(data);
        insert(root,data);
    }
    preOrder(root,v2);
    preOrder2(root,v3);
    if(v1==v2){ //原树的先序遍历
        cout<<"YES\n";
        v1.clear();
        postOrder(root,v1);
        for(int i=0;i<n;i++){
            cout<<v1[i];
            if(i<n-1) cout<<" ";
        }
    }else if(v1==v3){ //镜像树的先序遍历
        cout<<"YES\n";
        v1.clear();
        postOrder2(root,v1);//对镜像树后序遍历
        for(int i=0;i<n;i++){
            cout<<v1[i];
            if(i<n-1) cout<<" ";
        }
    }
    else cout<<"NO";
    system("pause");
    return 0;
}