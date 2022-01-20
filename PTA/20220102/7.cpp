#include<bits/stdc++.h>
using namespace std;
char ch[102][102];
int main(){
    int n;
    string s;
    cin>>n;
    getchar();
    getline(cin,s);
    int l=s.length();
    int m=0;
    int cnt=0;
    while(cnt<=l){
        for(int i=0;i<n;i++){
            ch[m][i]=s[cnt++];
        }
        m++;
    }
    for(int j=0;j<m;j++){
        for(int k=n;k>=0;k--)
        {
            cout<<ch[k][j];
        }
        if(j<m-2)
        cout<<endl;
    }
    system("pause");
    return 0;
}