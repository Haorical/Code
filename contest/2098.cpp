#include<bits/stdc++.h>
using namespace std;
string s[27];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n);
    for(int i=0;i<n;i++){
        cout<<s[i]<<' ';
    }
    system("pause");
    return 0;
}