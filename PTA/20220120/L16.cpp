#include<bits/stdc++.h>
using namespace std;
int main(){
    char c;
    int n;
    cin>>c>>n;
    string s[102];
    bool b[102][102],b1[102][102];
    for(int i=0;i<n;i++){
        getline(cin,s[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]!=' '){
                b[i][j]=1;
                b1[n-i][n-j]=1;
            }
        }
    }
    int flag=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b[i][j]!=b1[i][j]){
                flag=0;
                break;
            }
        }
    }
    if(flag) cout<<"bu yong dao le\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b1[i][j]) putchar(c);
            else putchar(' ');
        }
        cout<<'\n';
    }
    system("pause");
    return 0;
}