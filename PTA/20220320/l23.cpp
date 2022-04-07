#include<bits/stdc++.h>
using namespace std;
int n;
int tree[50];
void creat(int i){
    if(i>n) return;
    creat(2*i);
    creat(2*i+1);
    cin>>tree[i];
}
int main(){
    cin>>n;
    creat(1);
    cout<<tree[1];
    for(int i=2;i<=n;i++){
        cout<<" "<<tree[i];
    }
    system("pause");
    return 0;
}