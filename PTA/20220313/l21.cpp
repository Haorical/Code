#include<bits/stdc++.h>
using namespace std;
int pre[1010],cru[1010];
stack<int> st;
int main(){
    int m,n,k;
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    while(k--){
        for(int i=0;i<n;i++){
            cin>>cru[i];
        }
        int p1=0,p2=0;
        for(int j=0;j<n;j++){
            if(pre[p1]!=pre[p2]){
                st.push(pre[p1]);
            }else if(st.top()==pre[p2]);
        }
    }
    system("pause");
    return 0;
}