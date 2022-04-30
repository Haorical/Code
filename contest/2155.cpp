#include<bits/stdc++.h>
using namespace std;
int main(){
    int v,p1;
    string s1,s2;
    cin>>s1>>s2;
    int l2=s2.length();
    int l1=s1.length();
    p1=0;
    for(int i=0;i<l2;i++){
        char t1=s1[p1];
        if(t1>='a'&&t1<='z') v=t1-'a';
        else v=t1-'A';
        t1=s2[i];
        if(t1>='a'&&t1<='z') t1='a'+(t1-'a'+26-v)%26;
        else t1='A'+(t1-'A'+26-v)%26;
        cout<<t1;
        p1=(p1+1)%l1;
    }
    system("pause");
    return 0;
}