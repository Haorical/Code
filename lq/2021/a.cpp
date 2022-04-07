#include<bits/stdc++.h>
using namespace std;
int n[10];
int main(){
    fill(n,n+10,2021);
    for(int i=1;;i++){
        string s=to_string(i);
        for(int j=0;j<s.size();j++){
            n[s[j]-'0']--;
        }
        for(int k=0;k<10;k++){
            if(n[k]==0){
                cout<<s;
                system("pause");
            }
        }
    }
    system("pause");
    return 0;
}