#include <bits/stdc++.h> 
using namespace std;

int a[15]={0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 
1358657, 2504881, 13482720};

struct node
{
    int val;
    node* next;
    node(int v): val(v){};
};
int circle(int n, int m){
    if(m==1) return n-1;
   node* root=new node(0);
   node* current=root;
   for(int i=1;i<n;i++){
       current->next=new node(i);
       current=current->next;
   } 
   current->next=root;
   int i=0;
   while(root->next!=root){
       if(i==m-2){
           root->next=root->next->next;
           i=0;
       }else{
           i++;
       }
       root=root->next;
   }
}
int main(){
 int k;
 while(cin>>k){
 if(k==0)
 break;
 cout<<a[k]<<endl;
 }
 return 0;
}

