//完全二叉树直接数组存
#include<bits/stdc++.h>
using namespace std;
int n;
int tree[40];
void creat(int root){
    if(root>n) return; //注意递归结束条件
    creat(root*2);
    creat(root*2+1);
    cin>>tree[root];
}
int main(){
    cin>>n;
    creat(1);
    for(int i=1;i<=n;i++){
        cout<<tree[i];
        if(i<n) cout<<' ';
    }
    system("pause");
    return 0;
}