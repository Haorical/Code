#include<bits/stdc++.h>
using namespace std;
int u[10000];
bool pre(int n){
    if(n==1) return false;
    for(int j=2;j<sqrt(n);j++){
        if(n%j==0){
            return false;
        }
    }
    return true;
}
int main(){
    int l,k;
    string s;
    cin>>l>>k>>s;
    int le=s.length();
    for(int i=0;i<le-k;i++){
        string ts="";
        for (int j = 0; j < k; j++)
        {
            ts[j]=s[i+j];
        }
        //cout<<ts<<endl;
        int tn=stoi(ts);
        //cout<<tmp<<endl;
        if(pre(tn)){
            cout<<ts;
            return 0;
        }
    }
    cout<<"404";
    system("pause");
    return 0;
}