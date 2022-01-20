#include<bits/stdc++.h>
using namespace std;
int pa,pb;
int main(){
    cin>>pa>>pb;
    int _pa=pa,_pb=pb;
    int n,t1,t2,t3,t4,sum;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t1>>t2>>t3>>t4;
        sum=t1+t3;
        if(t2==sum){
            pa--;
            if(pa==-1) break;
        }
        if(t4==sum){
            pb--;
            if(pb==-1) break;
        }
    }
    if(pa==-1){
        cout<<"A"<<'\n'<<_pb-pb;
    }else{
        cout<<"B"<<'\n'<<_pa-pa;
    }
    system("pause");
    return 0;
}