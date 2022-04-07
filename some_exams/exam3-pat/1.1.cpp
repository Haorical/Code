#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int l=s.length();
    int w=0;
    for(int i=0;i<l;i++){
        if(s[i]=='2'){
            w++;
        }
    }
    double sum=0.0;
    int l1=l;
    //cout<<cnt<<" "<<w<<endl;
    if(s[0]=='-') l1--;
    sum=1.0*w/l1;
    if(s[0]=='-') sum*=1.5;
    //cout<<sum<<endl;
    //cout<<s[l-1]-'0'<<endl;
    if((s[l-1]-'0')%2==0) sum*=2.0;
    //cout<<sum<<endl;
    printf("%.2f%%",sum*100);
    system("pause");
    return 0;
}