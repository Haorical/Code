#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    string nm;
    int x,y;
    while(t--){
        cin>>nm>>x>>y;
        if(x<15||x>20||y<50||y>70){
            cout<<nm<<endl;
        }
    }
    system("pause");
    return 0;
}